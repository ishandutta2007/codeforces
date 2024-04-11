#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
typedef long long ll;
ll a[MAXN];
ll n,ans;
map<ll,ll> mp;
int main()
{
    scanf("%lld",&n);
    for(ll i=0;i<n;i++)
        scanf("%lld",&a[i]);
    long double ans=0;
    ll sum=0;
    for(ll i=0;i<n;i++)
    {
        mp[a[i]]++;
        ll cnt=i,res=sum;
        cnt-=mp[a[i]-1]; res-=mp[a[i]-1]*(a[i]-1);
        cnt-=mp[a[i]]; res-=mp[a[i]]*a[i];
        cnt-=mp[a[i]+1]; res-=mp[a[i]+1]*(a[i]+1);
        ans+=cnt*a[i]-res;
        sum+=a[i];
    }
    printf("%.0Lf\n",ans);
    return 0;
}