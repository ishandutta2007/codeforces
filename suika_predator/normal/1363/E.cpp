#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int v;
	edge *next;
}*h[233333],pool[555555];
int top;
inline void addedge(int u,int v)
{
	edge *tmp=&pool[top++];tmp->v=v;tmp->next=h[u];h[u]=tmp;
	edge *pmt=&pool[top++];pmt->v=u;pmt->next=h[v];h[v]=pmt;
}
int n,m,k;
int a[233333],b[233333],c[233333];
int siz[233333],vis[233333];
long long ans=0;
void dfs1(int u)
{
	vis[u]=1;
	for(edge *tmp=h[u];tmp;tmp=tmp->next)
	{
		if(!vis[tmp->v])
		{
			a[tmp->v]=min(a[tmp->v],a[u]);
			dfs1(tmp->v);
		}
	}
}
void dfs2(int u)
{
	vis[u]=2;
	siz[u]=b[u];
	for(edge *tmp=h[u];tmp;tmp=tmp->next)
	{
		if(vis[tmp->v]!=2)
		{
			dfs2(tmp->v);
			if(siz[u]*siz[tmp->v]<0)
			{
//				cerr<<"add "<<2*a[u]*min(abs(siz[u]),abs(siz[tmp->v]))<<endl;
				ans+=2ll*a[u]*min(abs(siz[u]),abs(siz[tmp->v]));
			}
			siz[u]+=siz[tmp->v];
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	int x,y;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
		b[i]-=c[i];
	}
	for(int i=1;i<n;i++)
	{
		cin>>x>>y;
		addedge(x,y);
	}
	dfs1(1);
	dfs2(1);
	if(siz[1]==0)cout<<ans<<endl;
	else cout<<-1<<endl;
	return 0;
}