#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 500005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<ll,ll> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,tot,t,now;
ll a;
int sz[MAXN],cnt[MAXN];
ll dp[MAXN],ans;
vector<int> G[MAXN];
bool qu=0;
struct line
{
	long long m,b;
	mutable function<const line*()> succ;
	bool operator<(const line& rhs) const
	{
		if (!qu) return m<rhs.m;
		const line* s=succ();
		if (!s)
		return 0;
		return b-s->b<rhs.m*(s->m-m);
	}
};
struct hull:public multiset<line>
{
	bool bad(iterator y)
	{
		auto z=next(y);
		if (y==begin())
		{
			if (z==end())
			return 0;
			return (y->m==z->m && y->b<=z->b);
		}
		auto x=prev(y);
		if (z==end())
		return (y->m==x->m && y->b<=x->b);
		return 1.0*(x->b-y->b)*(z->m-y->m)>=1.0*(y->b-z->b)*(y->m-x->m);
	}
	void add(long long m,long long b)
	{
		auto it=insert({m,b});
		it->succ=[=] { return (next(it)==end())? 0:&*next(it); };
		if (bad(it))
		{
			erase(it);
			return;
		}
		while (next(it)!=end() && bad(next(it))) erase(next(it));
		while (it!=begin() && bad(prev(it))) erase(prev(it));
	}
	long long eval(long long x)
	{
		if (empty()) return -(1LL<<60);
		qu=1;line l=*lower_bound((line){x,0});qu=0;
		return l.m*x+l.b;
	}
};
hull ch;
void dfs1(int v,int p)
{
    sz[v]=1;
    dp[v]=INF;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs1(to,v);
        cnt[v]++;
        sz[v]+=sz[to];
    }
    if(cnt[v]==0) dp[v]=0;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dp[v]=min(dp[v],dp[to]+1LL*(sz[v]-sz[to])*(sz[v]-sz[to]-1));
    }
}
vector<P> tmp;
void dfs2(int v,int p)
{
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs2(to,v);
    }
    if(cnt[v]==0) return;
    ch.clear();
    tmp.clear();
    for(auto to:G[v])
    {
        if(to==p) continue;
        tmp.push_back(make_pair(sz[to],dp[to]));
    }
    sort(tmp.begin(),tmp.end());
    a=n-tmp[0].F;
    ch.add(-(1-2*a),-(a*a-a+tmp[0].S));
    ans=min(ans,tmp[0].S+a*(a-1));
    for(int i=1;i<(int)tmp.size();i++)
    {
        ans=min(ans,tmp[i].S+a*(a-1));
        ans=min(ans,-ch.eval(tmp[i].F)+tmp[i].S+tmp[i].F*tmp[i].F);
        a=n-tmp[i].F;
        ch.add(-(1-2*a),-(a*a-a+tmp[i].S));
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs1(1,0);
    ans=INF;
    dfs2(1,0);
    assert(ans%2==0);
    printf("%lld\n",1LL*n*(n-1)-ans/2);
    return 0;
}