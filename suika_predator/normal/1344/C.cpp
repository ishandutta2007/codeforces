#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int v;
	edge *next;
}*h[233333],*rh[233333],pool[555555];
int top;
int in[233333];
inline void addedge(int u,int v)
{
	edge *tmp=&pool[top++];tmp->v=v;tmp->next=h[u];h[u]=tmp;
	edge *pmt=&pool[top++];pmt->v=u;pmt->next=rh[v];rh[v]=pmt;
	in[v]++;
}
int n,m,k;
int fl[233333][2],ok[233333];
queue<int> q;
void dfs(int u)
{
	fl[u][0]=1;
	for(edge *tmp=h[u];tmp;tmp=tmp->next)
	{
		if(!fl[tmp->v][0])dfs(tmp->v);
	}
}
void rdfs(int u)
{
	fl[u][1]=1;
	for(edge *tmp=rh[u];tmp;tmp=tmp->next)
	{
		if(!fl[tmp->v][1])rdfs(tmp->v);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	int x,y;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		addedge(x,y);
	}
	for(int i=1;i<=n;i++)
	{
		if(in[i]==0)q.push(i);
	}
	int cnt=0;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		cnt++;
		for(edge *tmp=h[u];tmp;tmp=tmp->next)
		{
			in[tmp->v]--;
			if(in[tmp->v]==0)
			{
				q.push(tmp->v);
			}
		}
	}
	if(cnt!=n)
	{
		cout<<-1<<endl;
		return 0;
	}
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(!fl[i][0]&&!fl[i][1])ok[i]=1,cnt++;
		if(!fl[i][0])dfs(i);
		if(!fl[i][1])rdfs(i);
	}
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++)
	{
		if(ok[i]==0)cout<<'E';
		else cout<<'A';
	}
	cout<<endl;
	return 0;
}