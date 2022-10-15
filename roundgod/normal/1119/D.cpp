#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,q,tot;
ll a[MAXN];
map<ll,int> mp;
vector<ll> v;
ll ans[MAXN];
ll cnt[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++) mp[a[i]-a[i-1]]++;
    int res=n;
    ll now=0,last=0;
    for(auto x:mp)
    {
        v.push_back(x.F);
        now+=1LL*res*(x.F-last);
        last=x.F;
        res-=x.S;
        ++tot;
        ans[tot]=now;
        cnt[tot]=res;
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        ll l,r;
        scanf("%lld%lld",&l,&r);
        l=r-l+1;
        int id=upper_bound(v.begin(),v.end(),l)-v.begin();
        if(id==0) printf("%lld ",n*l);
        else
        {
            id--;
            printf("%lld ",ans[id+1]+(l-v[id])*(cnt[id+1]));
        }
    }
    return 0;
}