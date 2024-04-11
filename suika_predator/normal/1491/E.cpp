#include<bits/stdc++.h>
using namespace std;
vector<int> G[233333];
int f[233],b[233333];
int siz[233333],pa[233333],cut[233333];
void dfs(int u)
{
	siz[u]=1;
	for(auto v:G[u])
	{
		if(pa[u]!=v)
		{
			pa[v]=u;
			dfs(v);
			siz[u]+=siz[v];
		}
	}
}
int dfs2(int u,int s,int s2)
{
	if(siz[u]==s||siz[u]==s2)return u;
	for(auto v:G[u])
	{
		int qwq=0;
		if(v==pa[u])
		{
//			if(!cut[u])
//				qwq=dfs2(v,s,s2);
		}
		else if(!cut[v])
		{
			qwq=dfs2(v,s,s2);
		}
		if(qwq)return qwq;
	}
	return 0;
}
int gao(int u,int l)
{
//	cerr<<"gao "<<u<<' '<<l<<endl;
//	for(int i=1;i<=5;i++)cerr<<siz[i]<<' ';cerr<<endl;
	if(l<=1)return true;
	int z=dfs2(u,f[l-1],f[l-2]);
	if(!z)return false;
	int s=siz[z],tz=z;
	while(!cut[tz])
	{
		tz=pa[tz];
		siz[tz]-=s;
	}
	cut[z]=1;
	
	return gao(z,b[s])&&gao(u,2*l-3-b[s]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	f[0]=f[1]=1;
	b[1]=1;
	for(int i=2;i<=30;i++)
	{
		f[i]=f[i-1]+f[i-2];
		if(f[i]<=200000)
			b[f[i]]=i;
	}
	int n,x,y;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	if(!b[n])
	{
		cout<<"NO"<<endl;
	}
	else
	{
		dfs(1);
		cut[1]=1;
		if(gao(1,b[n]))cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}