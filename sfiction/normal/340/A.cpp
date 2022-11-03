/*
ID: Sfiction
OJ: CF
PROB: 340A
*/
#include <cstdio>
int Gcd(int a,int b)
{
    return b?Gcd(b,a%b):a;
}
int main()
{
    int x,y,a,b,d;
    scanf("%d%d%d%d",&x,&y,&a,&b);
    d=Gcd(x,y);
    x=x*y/d;
    printf("%d",b/x-(a-1)/x);
    return 0;
}