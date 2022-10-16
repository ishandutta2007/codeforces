#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<vector>
using namespace std;
const int MAXN=3011;
struct edge
{
	int v;
	edge *next;
}*h[MAXN],pool[MAXN];
int top;
inline void addedge(int u,int v)
{
	edge *tmp=&pool[top++];tmp->v=v;tmp->next=h[u];h[u]=tmp;
}
struct query
{
	int id,k;
	query(int b,int c)
	{
		id=b,k=c;
	}
	inline bool operator<(const query &q)const{return id<q.id;}
};
vector<query> tmp[MAXN][MAXN];
int vis[MAXN],seq[MAXN];
int index,low[MAXN],dfn[MAXN];
int ans[400011];
void dfs(int root,int u,int dep,int ok)
{
	seq[dep]=u;
	vis[u]=1;
	dfn[u]=++index;
	//cout<<"dfs "<<root<<' '<<u<<endl;
	//for(int i=1;i<=7;i++)cout<<low[i]<<' ';cout<<endl;
	if(ok&&root!=u)
	{
		for(auto x:tmp[root][u])
		{
			if(x.k<=dep)ans[x.id]=seq[x.k];
			else ans[x.id]=-1;
		}
	}
	for(edge *tmp=h[u];tmp;tmp=tmp->next)
	{
		if(!vis[tmp->v])
		{
			dfs(root,tmp->v,dep+1,ok);
			low[u]=min(low[u],low[tmp->v]);
			if(low[u]<=dfn[u])
			{
				ok=false;
			}
		}
		else if(vis[tmp->v]==1)
		{
			low[u]=min(low[u],dfn[tmp->v]);
			if(low[u]<=dfn[u])
			{
				ok=false;
			}
		}
	}
	vis[u]=2;
	//cout<<"dfs_end "<<u<<endl;
	//for(int i=1;i<=7;i++)cout<<low[i]<<' ';cout<<endl;
}
bool adj[MAXN][MAXN];
int main()
{
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	int a,b,c;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		adj[a][b]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=n;j>=1;j--)
		{
			if(adj[i][j])addedge(i,j);
		}
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		tmp[a][b].push_back(query(i,c));
	}
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		memset(seq,0,sizeof(seq));
		memset(low,0x3f,sizeof(low));
		memset(dfn,0,sizeof(dfn));
		index=0;
		dfs(i,i,1,1);
		//for(int j=1;j<=n;j++)cout<<len[j]<<' ';cout<<endl;
	}
	for(int i=1;i<=q;i++)
	{
		if(ans[i])printf("%d\n",ans[i]);
		else printf("-1\n");
	}
	return 0;
}
/**
6 6 1
2 4
4 5
5 1
1 6
5 3
4 1
2 3 4

7 7 1
3 4
4 5
5 1
5 2
1 6
6 1
2 7
3 7 5

7 8 1
7 6
6 1
1 4
4 1
6 3
3 2
4 2
2 5
7 5 1
*/