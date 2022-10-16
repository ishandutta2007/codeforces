#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int MAXN=200010;
struct edge
{
	int v;
	edge *next;
}*h[MAXN],pool[MAXN*2];
int top;
inline void addedge(int u,int v)
{
	edge *tmp=&pool[top++];tmp->v=v;tmp->next=h[u];h[u]=tmp;
	edge *pmt=&pool[top++];pmt->v=u;pmt->next=h[v];h[v]=pmt;
}
int vis[MAXN],pre[MAXN];
struct tri
{
	int x,y,z;
	tri(int a,int b,int c){x=a;y=b;z=c;}
};
vector<tri> ans;
int root;
void dfs(int u,int pa)
{
	//cout<<u<<' '<<pa<<endl;
	vis[u]=1;
	for(edge *tmp=h[u];tmp;tmp=tmp->next)
	{
		if(tmp->v==pa)continue;
		if(!vis[tmp->v])
		{
			dfs(tmp->v,u);
			if(pre[tmp->v])
			{
				ans.push_back(tri(pre[tmp->v],tmp->v,u));
				pre[tmp->v]=0;
			}
			else if(pre[u])
			{
				ans.push_back(tri(tmp->v,u,pre[u]));
				pre[u]=0;
			}
			else pre[u]=tmp->v;
		}
		else if(vis[tmp->v]==1)
		{
			if(pre[u])
			{
				ans.push_back(tri(tmp->v,u,pre[u]));
				pre[u]=0;
			}
			else
			{
				pre[u]=tmp->v;
			}
		}
		//cout<<u<<"->"<<tmp->v<<endl;for(int i=1;i<=4;i++)cout<<pre[i]<<' ';cout<<endl;
	}
	vis[u]=2;
}
int main()
{
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		addedge(a,b);
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])dfs(root=i,0);
	}
	printf("%d\n",ans.size());
	for(auto r:ans)
	{
		printf("%d %d %d\n",r.x,r.y,r.z);
	}
	return 0;
}