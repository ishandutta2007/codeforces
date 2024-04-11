#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
ll extgcd(ll a,ll b,ll &x,ll &y)
{
    ll d=a;
    if(b!=0)
    {
        d=extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else
    {
        x=1;
        y=0;
    }
    return d;
}
ll mod_inverse(ll a,ll m)
{
    ll x,y;
    extgcd(a,m,x,y);
    return (m+x%m)%m;
}
ll n,m;
ll num[MAXN],pre[MAXN],dis[MAXN];
bool valid[MAXN];
vector<ll> save[MAXN];
vector<ll> G[MAXN];
ll p[MAXN],color[MAXN];
deque<ll> order;
void dfs_visit(ll v)
{
	color[v]=1;
	for(ll i=0;i<G[v].size();i++)
	{
		ll to=G[v][i];
		if(color[to]==0)
		{
			p[to]=v;
			dfs_visit(to);
		}
	}
	color[v]=2;
	order.push_front(v);
}
void toposort()
{
	memset(color,0,sizeof(color));
	memset(p,-1,sizeof(p));
	for(ll i=1;i<=m;i++)
		if(color[i]==0)
			dfs_visit(i);
}
int main()
{
	scanf("%I64d%I64d",&n,&m);
	memset(valid,true,sizeof(valid));
	memset(num,0,sizeof(num));
	for(ll i=0;i<n;i++)
	{
		ll x;
		scanf("%I64d",&x);
		valid[x]=false;
	}
	for(ll i=0;i<m;i++)
	{
		ll t=gcd(i,m);
		if(valid[i])
		{
			num[t]++;
			save[t].push_back(i);
		}
	}
	/*for(ll i=1;i<=m;i++)
		printf("%I64d ",num[i]);
	printf("\n");*/
	for(ll i=1;i<=m;i++)
		for(ll j=2*i;j<=m;j+=i)
			G[i].push_back(j);
	toposort();
	/*for(ll i=0;i<order.size();i++)
		printf("%I64d ",order[i]);
	printf("\n");*/
	memset(pre,-1,sizeof(pre));
	fill(dis,dis+m+1,-INF);
	for(ll i=0;i<m;i++)
	{
		ll v=order[i];
		if(num[v]==0) continue;
		if(dis[v]==-INF) dis[v]=num[v];
		for(ll j=0;j<G[v].size();j++)
		{
			ll to=G[v][j];
			if(num[v]==0) continue;
			if(dis[v]+num[to]>dis[to])
			{
				dis[to]=dis[v]+num[to];
				pre[to]=v;
			}
		}
	}
	ll ans=0,res=-INF,now=1;
	for(ll i=1;i<=m;i++)
	{
		if(dis[i]>res)
		{
			res=dis[i];
			ans=i;
		}
	}
	vector<ll> s;
	printf("%I64d\n",res);
	while(ans!=-1)
	{
		s.push_back(ans);
		ans=pre[ans];
	}
	ll cnt=0;
	for(ll i=s.size()-1;i>=0;i--)
	{
		for(ll j=0;j<save[s[i]].size();j++)
		{
			ll x=save[s[i]][j],y=gcd(now,m);
			ll result=mod_inverse(now/y,m/y)*(x/y)%(m/y);
			printf("%I64d ",result);
			now=x;
		}
	}
	return 0;
}