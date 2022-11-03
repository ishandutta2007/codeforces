/*
ID: Sfiction
OJ: CF
PROB: 336A
*/
#include <cstdio>
int main()
{
    int a,b,as,bs,x,y;
    scanf("%d%d",&a,&b);
    as=a>0?1:-1;
    bs=b>0?1:-1;
    a*=as;
    b*=bs;
    x=(a+b)*as;
    y=(a+b)*bs;
    if (x<0) printf("%d 0 0 %d",x,y);
    else printf("0 %d %d 0",y,x);
    return 0;
}