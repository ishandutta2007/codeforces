#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
ll a[MAXN];
ll n,x,k;
map<ll,ll> mp;
int main()
{
    scanf("%I64d%I64d%I64d",&n,&x,&k);
    for(ll i=0;i<n;i++)
        scanf("%I64d",&a[i]);
    sort(a,a+n);
    ll ans=0;
    mp.clear();
    for(ll i=n-1;i>=0;i--)
    {
        ll d=a[i]/x;
        if(mp.find(d)==mp.end()) mp[d]=0;
        mp[d]++;
        if(a[i]%x==0)
        {
            if(mp.find(d+k-1)==mp.end()) mp[d+k-1]=0;
            ans+=mp[d+k-1];
        }
        else
        {
            if(mp.find(d+k)==mp.end()) mp[d+k]=0;
            ans+=mp[d+k];
        }
    }
    if(k==0)
    {
        ll cnt=0;
        for(ll i=1;i<n;i++)
        {
            if(a[i]==a[i-1]&&a[i]%x!=0) cnt++;
            else if(cnt) {ans+=cnt*(cnt+1)/2; cnt=0;}
        }
        if(cnt) {ans+=cnt*(cnt+1)/2; cnt=0;}
    }
    if(k==1)
    {
        ll cnt=0;
        for(ll i=1;i<n;i++)
        {
            if(a[i]==a[i-1]&&a[i]%x==0) cnt++;
            else if(cnt) {ans+=cnt*(cnt+1)/2; cnt=0;}
        }
        if(cnt) {ans+=cnt*(cnt+1)/2; cnt=0;}
    }
    printf("%I64d\n",ans);
    return 0;
}