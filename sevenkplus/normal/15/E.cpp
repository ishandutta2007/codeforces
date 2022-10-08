#include<cstdio>
#define P 1000000009
int main()
{
    int n;
    long long a=1,b=2,c=4;
    for(scanf("%d",&n);n-=2;c=c*a%P,b=(b+c)%P,a=(a*2+3)%P);
    printf("%I64d\n",(b*b+1)*2%P);
    return 0;
}