#include<cstdio>

#define mo 1000000007

using namespace std;

int power(int x,long long m)
{
    int nowans=1;
    while(m)
    {
        if(m&1)nowans=1ll*nowans*x%mo;
        x=1ll*x*x%mo;
        m>>=1;
    }
    return nowans;
}

long long n;
int now;

int main()
{
    scanf("%I64d",&n);
    now=power(2,n);
    printf("%d\n",(int)(1ll*(1+now)*now%mo*(mo+1)/2%mo));
}