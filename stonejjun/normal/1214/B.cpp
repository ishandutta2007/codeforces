#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    ll n,m,k,chk=0,i,j;
    scanf("%lld %lld %lld",&n,&m,&k);
    for(i=0;i<=k;i++)
    {
        ll a=i;
        ll b=k-i;
        if(a<=n&&b<=m) chk++;
    }
    printf("%lld",chk);
}