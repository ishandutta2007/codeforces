#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int head[N],nxt[N],to[N],cnt;
int n,p[N],siz[N];
double dp[N];
void add(int u,int v)
{
	nxt[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

void get_size(int u)
{
	int i,v;
	siz[u]=1;
	for (int i=head[u];i;i=nxt[i])
	{
		v=to[i];
		get_size(v);
		siz[u]+=siz[v];
	}
}

void dfs2(int u)
{
	int i,v;
	for (int i=head[u];i;i=nxt[i])
	{
		v=to[i];
		dp[v]=dp[u]+1+(siz[u]-1-siz[v])/2.0;
		dfs2(v);
	}
}

int main()
{
	cin>>n;
	for (int i=2;i<=n;++i)
	{
		cin>>p[i];
		add(p[i],i);
	}	
	get_size(1);
	dp[1]=1;
	dfs2(1);
	for (int i=1;i<=n;++i)
		printf("%.12lf ",dp[i]);
	return 0;
}