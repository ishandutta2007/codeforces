#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,a,c[MAXN],d[MAXN];
ll val[MAXN],ans;
void solve(ll l,ll r)
{
    if(l>r) return;
    ll mid=(l+r)/2;
    vector<P> lb,rb;lb.clear();rb.clear();
    lb.push_back(P(0,0)); rb.push_back(P(0,0));
    ll cnt=0,mx=0;
    for(ll i=mid;i<=r-1;i++) 
    {
        cnt+=a;cnt-=c[i+1];mx=max(mx,val[i]);
        rb.push_back(P(mx,cnt));
    }
    cnt=0;mx=0;
    for(ll i=mid-1;i>=l;i--)
    {
        cnt+=a; cnt-=c[i];mx=max(mx,val[i]);
        lb.push_back(P(mx,cnt));
    }
    ll szl=(int)lb.size(),szr=rb.size();
    ll now=0;
    ll curmax=0;
    for(ll i=0;i<szr;i++)
    {
        while(now<szl&&lb[now].F<=rb[i].F)
        {
            curmax=max(curmax,lb[now].S);
            now++;
        }
        ans=max(ans,rb[i].S+curmax+a-c[mid]-rb[i].F);
    }
    now=0; curmax=0;
    for(ll i=0;i<szl;i++)
    {
        while(now<szr&&rb[now].F<=lb[i].F)
        {
            curmax=max(curmax,rb[now].S);
            now++;
        }
        ans=max(ans,lb[i].S+curmax+a-c[mid]-lb[i].F);
    }
    solve(l,mid-1);solve(mid+1,r);
}
int main()
{
    scanf("%lld%lld",&n,&a);
    for(ll i=1;i<=n;i++) scanf("%lld%lld",&d[i],&c[i]);
    for(ll i=1;i<=n-1;i++) val[i]=1LL*(d[i+1]-d[i])*(d[i+1]-d[i]);
    ans=0;
    solve(1,n);
    printf("%lld\n",ans);
    return 0;
}