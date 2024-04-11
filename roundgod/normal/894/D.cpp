#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m,k,a[MAXN];
struct edge
{
	ll to,cost;
};
vector<edge> G[MAXN];
vector<ll> dat[MAXN];
vector<ll> sum[MAXN];
void dfs(ll v)
{
	dat[v].push_back(0);
	if(v*2<=n)
	{
		dfs(v*2);
		dat[v].insert(dat[v].end(),dat[v*2].begin(),dat[v*2].end());
		ll t=dat[v*2].size();
		for(ll j=dat[v].size()-1;j>=dat[v].size()-t;j--)
			dat[v][j]+=a[v*2];
	}
	if(v*2+1<=n)
	{
		dfs(v*2+1);
		dat[v].insert(dat[v].end(),dat[v*2+1].begin(),dat[v*2+1].end());
		ll t=dat[v*2+1].size();
		for(ll j=dat[v].size()-1;j>=dat[v].size()-t;j--)
			dat[v][j]+=a[v*2+1];
	}
	sort(dat[v].begin(),dat[v].end());
}
int main()
{
	scanf("%I64d%I64d",&n,&m);
	for(ll i=2;i<=n;i++)
		scanf("%I64d",&a[i]);
	dfs(1);
	for(ll i=1;i<=n;i++)
	{
		ll sz=dat[i].size();
		for(ll j=0;j<sz;j++)
			if(j==0) sum[i].push_back(0); else sum[i].push_back(sum[i][j-1]+dat[i][j]);
	}
	for(ll i=1;i<=m;i++)
	{
		ll x,y;
		scanf("%I64d%I64d",&x,&y);
		ll ans=0;
		ll dist=0;
		ll l=0,r=dat[x].size();
		while(r-l>1)
		{
			ll mid=(l+r)/2;
			if(dat[x][mid]<y) l=mid; else r=mid;
		}
		ans+=(l+1)*y-sum[x][l];
		//printf("%I64d\n",ans);
		while(x>1&&dist+a[x]<=y)
		{
			dist+=a[x];
			ans+=y-dist;
			ll res=x&1;
			x=x/2;
			res=x*2+1-res;
			if(res<=n&&dist+a[res]<y)
			{
				ll l=0,r=dat[res].size();
				while(r-l>1)
				{
					ll mid=(l+r)/2;
					if(dat[res][mid]+dist+a[res]<y) l=mid; else r=mid;
				}
				ans+=(l+1)*(y-a[res]-dist)-sum[res][l];
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}