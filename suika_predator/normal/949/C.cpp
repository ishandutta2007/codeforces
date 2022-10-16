#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<stack>

using namespace std;
int n,m,H;
struct edge
{
	int v;
	edge *next;
}*h[233333],pool[233333];
int top;
inline void addedge(int u,int v)
{
//	cout<<"addedge "<<u<<' '<<v<<endl;
	edge *tmp=&pool[top++];tmp->v=v;tmp->next=h[u];h[u]=tmp;
}
stack<int> st;
int u[233333],dfn[233333],low[233333],ins[233333];
int bel[233333],cnt[233333];
int ind=0;
void dfs(int u)
{
//	cout<<"dfs "<<u<<endl;
//	for(int i=1;i<=n;i++)cout<<i<<' '<<dfn[i]<<' '<<low[i]<<endl;
	dfn[u]=low[u]=++ind;
	st.push(u);ins[u]=1;
	for(edge *tmp=h[u];tmp;tmp=tmp->next)
	{
		if(ins[tmp->v]==0)
		{
			dfs(tmp->v);
			low[u]=min(low[u],low[tmp->v]);
		}
		else if(ins[tmp->v]==1)
		{
			low[u]=min(low[u],dfn[tmp->v]);
		}
	}
//	cout<<"enddfs "<<u<<endl;
//	for(int i=1;i<=n;i++)cout<<i<<' '<<dfn[i]<<' '<<low[i]<<endl;
/*	while(!st.empty()&&dfn[u]==low[st.top()])
	{
		bel[st.top()]=u;
		cnt[u]++;
		ins[st.top()]=2;
		cout<<"pop "<<st.top()<<endl;
		st.pop();
	}*/
	if(dfn[u]==low[u])
	{
		do
		{
			bel[st.top()]=u;
			cnt[u]++;
			ins[st.top()]=2;
			if(st.top()==u)
			{
				st.pop();
				break;
			}
			st.pop();
		}while(!st.empty());
	}
	
}
int fl[233333];
int main()
{
//	freopen("data.txt","r",stdin);
	scanf("%d%d%d",&n,&m,&H);
	for(int i=1;i<=n;i++)scanf("%d",&u[i]);
	int x,y;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		if((u[x]+1)%H==u[y])addedge(x,y);
		if((u[y]+1)%H==u[x])addedge(y,x);
	}
	for(int i=1;i<=n;i++)if(!dfn[i])dfs(i);
//	for(int i=1;i<=n;i++)cout<<bel[i]<<' '<<cnt[i]<<endl;
//	for(int i=1;i<=n;i++)cout<<cnt[bel[i]]<<' ';
	for(int i=1;i<=n;i++)
	{
		for(edge *tmp=h[i];tmp;tmp=tmp->next)
		{
			if(bel[i]!=bel[tmp->v])
			{
				fl[bel[i]]=1;
			}
		}
	}
	int maxx=0;
	cnt[0]=233333;
	for(int i=1;i<=n;i++)
		if(!fl[i]&&cnt[i]&&cnt[i]<cnt[maxx])
			maxx=i;
	printf("%d\n",cnt[maxx]);
	for(int i=1;i<=n;i++)
	{
		if(bel[i]==maxx)printf("%d ",i);
	}
	return 0;
}