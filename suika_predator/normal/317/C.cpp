#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
struct edge
{
	int v;
	edge *next;
}*h[555],pool[2333];
int top;
int deg[555];
inline void addedge(int u,int v)
{
//	cout<<"addedge "<<u<<' '<<v<<endl;
	edge *tmp=&pool[top++];tmp->v=v;tmp->next=h[u];h[u]=tmp;
	edge *pmt=&pool[top++];pmt->v=u;pmt->next=h[v];h[v]=pmt;
	deg[u]++;deg[v]++;
}
int pa[555],a[555],b[555];
long long s1[555],s2[555];
int e[555][555],vis[555];
int find(int x){return pa[x]?pa[x]=find(pa[x]):x;}
bool onion(int u,int v)
{
	int pu=find(u),pv=find(v);
	if(pu==pv)return false;
	s1[pu]+=s1[pv];s2[pu]+=s2[pv];
	pa[pv]=pu;
	return true;
}
struct op
{
	int u,v,f;
};
vector<op> ans;
queue<int> q;
int n,V,m;
int push(int u,int f)
{
	vis[u]=1;
//	cout<<"push "<<u<<' '<<f<<endl;
	int curf=min(f,V-a[u]);
	for(edge *tmp=h[u];tmp&&curf<f;tmp=tmp->next)
	{
		if(!vis[tmp->v])
		{
			int qwq=push(tmp->v,f-curf);
			ans.push_back({u,tmp->v,qwq});
			a[u]-=qwq;
			a[tmp->v]+=qwq;
			curf+=qwq;
		}
	}
	vis[u]=0;
	return curf;
}
int pull(int u,int f)
{
	vis[u]=1;
//	cout<<"pull "<<u<<' '<<f<<endl;
	int curf=min(f,a[u]);
	for(edge *tmp=h[u];tmp&&curf<f;tmp=tmp->next)
	{
		if(!vis[tmp->v])
		{
			int qwq=pull(tmp->v,f-curf);
			ans.push_back({tmp->v,u,qwq});
			a[tmp->v]-=qwq;
			a[u]+=qwq;
			curf+=qwq;
		}
	}
	vis[u]=0;
	return curf;
}
int main()
{
	scanf("%d%d%d",&n,&V,&m);
	for(int i=1;i<=n;i++)scanf("%d",&s1[i]),a[i]=s1[i];
	for(int i=1;i<=n;i++)scanf("%d",&s2[i]),b[i]=s2[i];
	int x,y;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		e[x][y]=e[y][x]=1;
		if(onion(x,y))addedge(x,y);
	}
	for(int i=1;i<=n;i++)if(s1[find(i)]!=s2[find(i)])return printf("NO\n"),0;
	for(int i=1;i<=n;i++)
	{
		if(deg[i]==1)q.push(i);
	}
	while(!q.empty())
	{
		int u=q.front();q.pop();
		vis[u]=1;
		for(edge *tmp=h[u];tmp;tmp=tmp->next)
		{
			if(!vis[tmp->v])
			{
				if(a[u]>b[u])
				{
					int qwq=a[u]-b[u];
					push(tmp->v,qwq);
					ans.push_back({u,tmp->v,qwq});
					a[u]-=qwq;
					a[tmp->v]+=qwq;
				}
				else if(a[u]<b[u])
				{
					int qwq=b[u]-a[u];
					pull(tmp->v,qwq);
					ans.push_back({tmp->v,u,qwq});
					a[tmp->v]-=qwq;
					a[u]+=qwq;
				}
				deg[tmp->v]--;
				if(deg[tmp->v]==1)q.push(tmp->v);
			}
		}
//		cout<<"end "<<u<<endl;
	}
	printf("%d\n",ans.size());
	for(auto _:ans)
	{
		printf("%d %d %d\n",_.u,_.v,_.f);
	}
	return 0;
}