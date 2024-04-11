#include<cstdio>

using namespace std;

long long n;
int cnt,a[100],now;

int main()
{
    scanf("%I64d",&n);
    while(n)
    {
        now=n%10;
        if((n/10!=0&&9-now<now)||(n/10==0&&now!=9&&9-now<now))now=9-now;
        a[++cnt]=now;
        n/=10;
    }
    while(cnt)printf("%d",a[cnt--]);
}