#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
#define INF 100000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
ll getmask()
{
    ll x,mask=0;
    scanf("%lld",&x);
    for(ll i=0;i<x;i++)
    {
        ll y;
        scanf("%lld",&y);
        mask|=(1<<(y-1));
    }
    return mask;
}
ll n,m,a[MAXN];
ll cnt[1005];
P res[1005][2];
ll ans,price;
ll id1,id2;
int main()
{
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++) cnt[getmask()]++;
    for(ll i=0;i<9;i++)
        for(ll mask=0;mask<(1<<9);mask++)
		    if(mask&(1<<i)) cnt[mask]+=cnt[mask^(1<<i)];
    for(ll i=0;i<(1<<9);i++)
        res[i][0]=res[i][1]=make_pair(INF,-1);
    for(ll i=1;i<=m;i++)
    {
        ll pr;
        scanf("%lld",&pr);
        ll mask=getmask();
        if(pr<res[mask][0].F)
        {
            res[mask][1]=res[mask][0];
            res[mask][0]=make_pair(pr,i);
        }
        else if(pr<res[mask][1].F) res[mask][1]=make_pair(pr,i);
    }
    ans=-1,price=INF;
    id1=id2=-1;
    for(ll mask=0;mask<(1<<9);mask++)
    {
        if(res[mask][0].S==-1||res[mask][1].S==-1) continue;
        if(cnt[mask]>ans||(cnt[mask]==ans&&res[mask][0].F+res[mask][1].F<price))
        {
            ans=cnt[mask];
            price=res[mask][0].F+res[mask][1].F;
            id1=res[mask][0].S; id2=res[mask][1].S;
        }
    }
    for(ll mask1=0;mask1<(1<<9);mask1++)
    {
        for(ll mask2=mask1+1;mask2<(1<<9);mask2++)
        {
            if(res[mask1][0].S==-1||res[mask2][0].S==-1) continue;
            ll mask=mask1|mask2;
            if(cnt[mask]>ans||(cnt[mask]==ans&&res[mask1][0].F+res[mask2][0].F<price))
            {
                ans=cnt[mask];
                price=res[mask1][0].F+res[mask2][0].F;
                id1=res[mask1][0].S; id2=res[mask2][0].S;
            }
        }
    }
    printf("%lld %lld\n",id1,id2);
    return 0;
}