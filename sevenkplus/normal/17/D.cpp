#include<cstdio>
#include<cstring>
typedef long long ll;
char B[1000020],N[1000020];
int c,x;
ll n,b;
int p(int x)
{
    int c=x;
    for(int i=2;i<100000;i++)
        if(x%i==0)
            for(c=c/i*(i-1);x%i==0;x/=i);
    if(x!=1)
        c=c/x*(x-1);
    return c;
}
int main()
{
    scanf("%s%s%d",B,N,&c);
    int lb=strlen(B),ln=strlen(N);
    x=p(c);
    for(int i=0;i<lb;i++)
        b=(b*10+B[i]-'0')%c;
    if(ln<10)
    {
        for(int i=0;i<ln;i++)
            n=n*10+N[i]-'0';
        n--;
    }
    else
    {
        for(int i=0;i<ln;i++)
            n=(n*10+N[i]-'0')%x;
        n+=x-1,n+=x;
    }
    ll r=b?b-1:c-1,t=b;
    for(;n;n/=2)
    {
        if(n&1)
            r=r*t%c;
        t=t*t%c;
    }
    printf("%lld\n",r?r:c);
    return 0;
}