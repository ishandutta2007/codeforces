#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
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
struct hull:multiset<line>
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
ll n;
ll a[MAXN],b[MAXN];
vector<int> G[MAXN];
ll dp[MAXN];
hull* merge(hull* x,hull* y)
{
    if(x->size()<y->size()) swap(x,y);
    for(auto l:*y) x->add(l.m,l.b);
    return x;
}
hull* dfs(ll v,ll p)
{
    hull* now=new hull();
    for(auto to:G[v])
    {
        if(to==p) continue;
        hull* tmp=dfs(to,v);
        now=merge(now,tmp);
        //merge(h[v],h[to]);
    }
    if(now->empty()) dp[v]=0; else dp[v]=-now->eval(a[v]);
    now->add(-b[v],-dp[v]);
    return now;
}
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(ll i=1;i<=n;i++) scanf("%lld",&b[i]);
    for(ll i=0;i<n-1;i++)
    {
        ll u,v;
        scanf("%lld%lld",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(1,0);
    for(ll i=1;i<=n;i++) printf("%lld ",dp[i]);
    return 0;
}