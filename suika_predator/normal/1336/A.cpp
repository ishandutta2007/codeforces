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
int dep[233333],siz[233333],a[233333];
void dfs(int u)
{
	siz[u]=1;
	for(edge *tmp=h[u];tmp;tmp=tmp->next)
	{
		if(!dep[tmp->v])
		{
			dep[tmp->v]=dep[u]+1;
			dfs(tmp->v);
			siz[u]+=siz[tmp->v];
		}
	}
}
int n,m,k;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	int x,y;
	for(int i=1;i<n;i++)
	{
		cin>>x>>y;
		addedge(x,y);
	}
	dep[1]=1;
	dfs(1);
	for(int i=1;i<=n;i++)
	{
		a[i]=dep[i]-siz[i];
	}
	sort(a+1,a+n+1,greater<int>());
	long long ans=0;
	for(int i=1;i<=k;i++)
	{
		ans+=a[i];
	}
	cout<<ans<<endl;
	return 0;
}