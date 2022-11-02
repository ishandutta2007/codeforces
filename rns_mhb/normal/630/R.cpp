#include<stdio.h>
main() {
    char c,d;
    while(~scanf("%c",&c))if('0'<=c&&c<'0'+10)d=c;d++;
    printf("%d",(d&1)+1);
}