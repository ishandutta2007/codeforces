#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=1e9;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
const int N=447;
int n,q,c1,c2,ans[200001],f[200001][N+2],g[N+2],sz[2000001];
vector<int> G[200001];
array<int,3> a[200001],b[200001];
void dfs1(int x,int fa)
{
	for(int i:G[x])
		if(i!=fa)
		{
			dfs1(i,x);
			for(int l=0;l<N;l++)
				f[x][l]=max(f[x][l]+1,f[x][l]-l+f[i][l]);
		}
}
void dfs2(int x,int fa)
{
	for(int i=0;i<=N+1;i++)
		f[x][i]=-INF;
	for(int i=0;i<=N+1;i++)
		g[i]=-INF;
	sz[x]=1;
	f[x][0]=0;
	for(int i:G[x])
		if(i!=fa)
		{
			dfs2(i,x);
			for(int l=0;l<=sz[x]&&l<=N;l++)
				for(int j=0;j<sz[i]&&j+l<=N;j++)
				{
					g[l+j]=max(g[l+j],f[x][l]+1);
					g[l+j+1]=max(g[l+j+1],f[x][l]+f[i][j]);
				}
			sz[x]+=sz[i];
			for(int l=0;l<=sz[x]&&l<=N;l++)
			{
				f[x][l]=g[l];
				g[l]=-INF;
			} 
		}
}
signed main()
{
	n=read();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	q=read();
	for(int i=1;i<=q;i++)
	{
		int x=read(),y=read();
		if(y<N)
			a[++c1]={x,y,i};
		else
			b[++c2]={x,y,i};
	}
	dfs1(1,0);
	for(int i=1;i<=c1;i++)
		ans[a[i][2]]=f[a[i][0]][a[i][1]];
	dfs2(1,0);
	for(int i=1;i<=c2;i++)
		for(int l=0;l<=N;l++)
			ans[b[i][2]]=max(ans[b[i][2]],f[b[i][0]][l]-l*b[i][1]);
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<endl;
	return 0;
}