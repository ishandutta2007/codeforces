#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<vector>
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
vector<int> qwq[233333];
int a[233333],ok[233333],siz[233333];
long long ans[233333];
void dfs(int u)
{
	siz[u]=1;ok[u]=2;
	for(edge *tmp=h[u];tmp;tmp=tmp->next)
	{
		if(ok[tmp->v]==1)
		{
			dfs(tmp->v);
			siz[u]+=siz[tmp->v];
		}
	}
}
int main()
{
	int n,u,v;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		int s=sqrt(a[i]);
		for(int j=1;j<=s;j++)
		{
			if(a[i]%j==0)
			{
				qwq[j].push_back(i);
				if(a[i]/j!=j)qwq[a[i]/j].push_back(i);
			}
		}
	}
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		addedge(u,v);
	}
	for(int i=1;i<=200000;i++)
	{
		for(auto x:qwq[i])ok[x]=1;
		for(auto x:qwq[i])if(ok[x]==1)dfs(x),ans[i]+=(1ll*siz[x]*(siz[x]-1)/2)+siz[x];
		for(auto x:qwq[i])ok[x]=siz[x]=0;
	}
	for(int i=200000;i>=1;i--)
	{
		for(int j=i+i;j<=200000;j+=i)
			ans[i]-=ans[j];
	}
	for(int i=1;i<=200000;i++)if(ans[i])printf("%d %lld\n",i,ans[i]);
	return 0;
}