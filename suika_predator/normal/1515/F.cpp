#include<bits/stdc++.h>
using namespace std;
int n,m,k,x;
long long a[333333];
struct edge
{
	int v,id;
	edge *next;
}*h[333333],pool[777777];
int top;
inline void addedge(int u,int v,int id)
{
	edge *tmp=&pool[top++];tmp->v=v;tmp->id=id;tmp->next=h[u];h[u]=tmp;
	edge *pmt=&pool[top++];pmt->v=u;pmt->id=id;pmt->next=h[v];h[v]=pmt;
}
stack<int> L,R;
int vis[333333];
void dfs(int u)
{
	vis[u]=1;
	for(edge *tmp=h[u];tmp;tmp=tmp->next)
	{
		if(!vis[tmp->v])
		{
			dfs(tmp->v);
			if(a[u]+a[tmp->v]<x)
			{
				R.push(tmp->id);
			}
			else
			{
				a[u]=a[u]+a[tmp->v]-x;
				L.push(tmp->id);
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m>>x;
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	if(sum<1ll*x*(n-1))
	{
		cout<<"NO"<<endl;
		return 0;
	}
	int u,v;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		addedge(u,v,i);
	}
	dfs(1);
	while(!L.empty())
	{
		R.push(L.top());L.pop();
	}
	cout<<"YES"<<endl;
	while(!R.empty())
	{
		cout<<R.top()<<endl;
		R.pop();
	}
	return 0;
}