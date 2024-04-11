#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
ll n;
int main()
{
    scanf("%I64d",&n);
    if(n==1||n==2)
    {
        printf("-1\n");
        return 0;
    }
    if(n&1) printf("%I64d %I64d",n*(n-1)/2+(n-1)/2,n*(n-1)/2+(n-1)/2+1);
    else
    {
        ll t=n;
        ll s=1;
        while(n%2==0)
        {
           n/=2;
           s*=2;
        }
        if(n==1) printf("%I64d %I64d",3*t/4,5*t/4);
        else printf("%I64d %I64d",(n*(n-1)/2+(n-1)/2)*s,(n*(n-1)/2+(n-1)/2+1)*s);
    }
    return 0;
}