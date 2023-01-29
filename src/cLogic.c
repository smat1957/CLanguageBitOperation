#include<stdio.h>
#define CHAR_BIT 8
static char frm[15] = " = ( 0x%08X )";

void printb(unsigned int v) {
  unsigned int mask = (int)1 << (sizeof(v) * CHAR_BIT - 1);
  int n=0;
  do{
     if(n++%4==0)	putchar(' ');
     putchar(mask & v ? '1' : '0');
  }while(mask >>= 1);
}

void binhex(unsigned int v1) {
    printb(v1);     printf(frm, v1);    printf("\n");
}

void binhex1(char* s1,unsigned v1) {
    printf("%s", s1);   binhex( v1 );
}

void binhex2(char* s1,unsigned v1,char* s2,unsigned v2) {
    binhex1( s1, v1 );   binhex1( s2, v2 );
}

void binhex3(char* s1,unsigned v1,char* s2,unsigned v2,char* s3,unsigned v3) {
    binhex2( s1, v1, s2, v2 );  binhex1( s3, v3 );
}

void main(void) {
    sprintf( frm, "%s%c%s", " = ( 0x%0", CHAR_BIT+'0' ,"X )" );
    unsigned int a, b, c;
    a = 0xA5A5A5A5;     b = 0x000000FF;
    /* NOT */
    printf("=== NOT:(~a) ===\n");
    binhex2( " a =", a, "~a =", ~a);                         printf("\n");
    /* AND */
    printf("=== AND:(a & b) ===\n");   
    binhex3("a     =", a, "b     =", b, "a & b =", a & b);   printf("\n");
    /* OR */
    printf("=== OR:(a | b) ===\n");
    binhex3("a     =", a, "b     =", b, "a | b =", a | b);   printf("\n");
    /* XOR */
    printf("=== XOR:(a ^ b ) ===\n");
    b = 0xFFFFFFFF;
    binhex3("a     =", a, "b     =", b, "a ^ b =", a ^ b);   printf("\n");
    b = 0x00000000;
    binhex3("a     =", a, "b     =", b, "a ^ b =", a ^ b);   printf("\n");
    /* 応用問題 */
    printf("=== c = (( a & 3) << 8 ) | (b & 255 ) ===\n"); 
    printf(" a を入力： ");  scanf("%u", &a);
    printf(" b を入力： ");  scanf("%u", &b);                printf("\n");
    printf(" a                    =");   binhex( a );
    printf("     3                =");   binhex( 3 );
    printf(" a & 3                =");   binhex( a&3 );
    printf("(a & 3) << 8          =");   binhex( (a&3)<<8 ); printf("\n");
    printf(" b                    =");   binhex( b );
    printf("     255              =");   binhex( 255 );
    printf(" b & 255              =");   binhex( b&255 );    printf("\n");
    c = ( (a & 3) << 8 ) | ( b & 255 );
    printf(" c = (a&3)<<8+(b&255) =");   binhex( c );
}