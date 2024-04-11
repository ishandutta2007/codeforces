#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll arr[10101010];
ll dp[10101010];
ll brr[10101010];

int main()
{
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        ll i,j,k,l,m,n,a,b,c;
        ll cnt=0,ans=0,chk=0;
        scanf("%lld %lld %lld",&a,&b,&c);
        if(c%3==0)printf("%lld\n",a);
        else if(c%3==1) printf("%lld\n",b);
        else printf("%lld\n",a^b);
;    }

}