#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,h[MAXN];
vector<P> v;
vector<int> G[MAXN];
int l[MAXN],r[MAXN],fa[MAXN];
int id[MAXN],s[MAXN];
int f[MAXN],g[MAXN];
int save[MAXN];
void dfs(int v,int p)
{
	f[v]=id[v]; fa[v]=p;
	for(auto to:G[v]) 
	{
		if(to==p) continue;
		dfs(to,v);
		f[v]=min(f[v],f[to]);
	}
}
void dfs2(int v,int p)
{
	vector<int> pre,suf;
	pre.push_back(INF+1);
	for(auto to:G[v])
	{
		if(to==p) continue;
		pre.push_back(f[to]);
		suf.push_back(f[to]);
	}
	suf.push_back(INF+1);
	for(int i=1;i<(int)pre.size();i++) pre[i]=min(pre[i],pre[i-1]);
	for(int i=suf.size()-2;i>=0;i--) suf[i]=min(suf[i],suf[i+1]);
	int cnt=0;
	for(auto to:G[v])
	{
		if(to==p) continue;
		cnt++;
		g[to]=min(id[v],min(g[v],min(pre[cnt-1],suf[cnt])));
	}
	for(auto to:G[v])
	{
		if(to==p) continue;
		dfs2(to,v);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&h[i]);
		v.push_back(P(h[i],i));
	}
	sort(v.begin(),v.end(),greater<P>());
	for(int i=0;i<(int)v.size();i++) id[v[i].S]=i;
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v); G[v].push_back(u);
	}
	dfs(1,0); g[1]=INF; dfs2(1,0);
	for(int i=1;i<=n;i++)
	{
		vector<int> tmp;
		for(auto to:G[i])
		{
			if(to==fa[i]) tmp.push_back(g[i]);
			else tmp.push_back(f[to]); 
		}
		if(tmp.size()==1) { s[id[i]]++;}
		else 
		{
			sort(tmp.begin(),tmp.end());
			int death=tmp[1];
			if(death>id[i]) {s[id[i]]++; s[death]--;}
		}
	}
	ll ans=0;
	int sum=0;
	for(int i=0;i<(int)v.size();i++)
	{
		assert(s[i]==1||s[i]==0);
		sum+=s[i];
		if(i==0) save[i]=2; else save[i]=sum;
		if(i==0) ans+=1LL*save[i]*v[i].F; else ans+=1LL*(save[i]-save[i-1])*v[i].F;
	}
	printf("%lld\n",ans);
	return 0;
}