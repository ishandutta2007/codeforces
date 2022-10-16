#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
#define ll long long
#define elif else if
#define ALL(x) x.begin(),x.end()
using namespace std;
const int M=55555;
int n,m,rt,tot,cnt,ty[M],ans[M],p[M*100],ls[M*100],rs[M*100],a[M*100],fa[M*100];
ll N=1,ql[M],qr[M];
vector<ll> v;
vector<int> e[M*100],g[M];
void modify(int &x,ll L,ll R,ll l=0,ll r=N-1)
{
	if(!x)
		x=++tot;
	if(L<=l&&r<=R)
	{
		a[x]=++cnt;
		return ;
	}
	ll mid=(l+r)>>1;
	if(mid>=L)
		modify(ls[x],L,R,l,mid);
	if(mid<R)
		modify(rs[x],L,R,mid+1,r);
}
void dfs(int k1,int k2,int d,int D)
{
	if(d>D)
	{
		if(a[k1])
			return ;
		dfs(ls[k1],ls[k2],d-1,D);
		dfs(rs[k1],rs[k2],d-1,D);
		return ;
	}
	if(d==D)
	{
		if(a[k1])
			return ;
		dfs(ls[k1],rs[k2],d-1,D);
		return ; 
	}
	if(a[k1]&&a[k2])
	{
		e[a[k1]].push_back(a[k2]);
		e[a[k2]].push_back(a[k1]);
		return ;
	}
	if(a[k1])
	{
		dfs(k1,ls[k2],d-1,D);
		dfs(k1,rs[k2],d-1,D);
		return ;
	}
	if(a[k2])
	{
		dfs(ls[k1],k2,d-1,D);
		dfs(rs[k1],k2,d-1,D);
		return ;
	}
	dfs(ls[k1],ls[k2],d-1,D);
	dfs(rs[k1],rs[k2],d-1,D);
}
void query(int k,ll L,ll R,int i,ll l=0,ll r=N-1)
{
	if(L<=l&&r<=R)
	{
		p[a[k]]=i;
		g[i].push_back(a[k]);
		return ;	
	}
	ll mid=(l+r)>>1;
	if(L<=mid)
		query(ls[k],L,R,i,l,mid);
	if(mid<R)
		query(rs[k],L,R,i,mid+1,r);
}
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]); 
}
void ins(int x)
{
	fa[x]=x;
	for(int i:e[x])
		if(fa[i])
			fa[find(x)]=find(i);
}
int get(int k,ll x)
{
	for(int i=n-1;i>=0;i--)
	{
		if((x>>i)&1)
			k=rs[k];
		else
			k=ls[k];
		if(a[k])
			return a[k];
	}
}
signed main()
{
	int i;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		N*=2; 
	for(i=1;i<=m;i++)
	{
		string s;
		cin>>s>>ql[i]>>qr[i];
		if(s[0]=='a')
			ty[i]=1;
		else
		{
			v.push_back(ql[i]-1);
			v.push_back(qr[i]);	
		}
	}
	v.push_back(-1);
	v.push_back(N-1);
	sort(ALL(v));
	v.resize(unique(ALL(v))-v.begin());
	for(i=1;i<v.size();i++)
		modify(rt,v[i-1]+1,v[i]);
	for(i=0;i<n;i++)
		dfs(rt,rt,n-1,i);
	for(i=1;i<=m;i++)
		if(!ty[i])
			query(rt,ql[i],qr[i],i);
	for(i=1;i<=cnt;i++)
		if(!p[i])
			ins(i);
	for(i=m;i;i--)
		if(!ty[i])
			for(int l:g[i])
				ins(l);
		else
		{
			ql[i]=get(rt,ql[i]);
			qr[i]=get(rt,qr[i]);
			if(find(ql[i])==find(qr[i]))
				ans[i]=1;
		}
	for(i=1;i<=m;i++)
		if(ty[i])
			printf("%d\n",ans[i]);
	return 0;
}