#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int SHIFT=10000,S=15000,T=15001,inf=0x3f3f3f3f;
struct edge
{
	int v,f;
	edge *next,*rev;
}*h[23333],pool[2333333];
int top;
inline void addedge(int u,int v,int c)
{
//	cout<<"addedge "<<u<<' '<<v<<' '<<c<<endl;
	edge *tmp=&pool[top++];tmp->v=v;tmp->f=c;tmp->next=h[u];h[u]=tmp;
	edge *pmt=&pool[top++];pmt->v=u;pmt->f=0;pmt->next=h[v];h[v]=pmt;
	tmp->rev=pmt;pmt->rev=tmp;
}
queue<int> q;
int lv[23333];
inline bool mklevel()
{
//	cout<<"mklevel"<<endl;
	while(!q.empty())q.pop();
	memset(lv,-1,sizeof(lv));
	q.push(S);lv[S]=0;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(edge *tmp=h[u];tmp;tmp=tmp->next)
		{
			if(tmp->f&&lv[tmp->v]==-1)
			{
				lv[tmp->v]=lv[u]+1;
				q.push(tmp->v);
			}
		}
		if(lv[T]!=-1)return true;
	}
	return false;
}
int dinic(int u,int minf)
{
//	cout<<"dinic "<<u<<' '<<minf<<endl;
	if(u==T)return minf;
	int totf=0;
	for(edge *tmp=h[u];tmp&&totf<minf;tmp=tmp->next)
	{
		if(tmp->f&&lv[tmp->v]==lv[u]+1)
		{
			int f=dinic(tmp->v,min(tmp->f,minf-totf));
			tmp->f-=f;
			tmp->rev->f+=f;
			totf+=f;
		}
	}
	if(!totf)lv[u]=-1;
	return totf;
}
int n,m,g,tot;
int s[23333],v[23333];
int main()
{
	scanf("%d%d%d",&n,&m,&g);
	for(int i=1;i<=n;i++)scanf("%d",&s[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&v[i]);
		if(s[i])addedge(S,i,v[i]);
		else addedge(i,T,v[i]);
	}
	int ss,w,k,x,f;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&ss,&w,&k);
		tot+=w;
		if(ss)
		{
			for(int j=1;j<=k;j++)
			{
				scanf("%d",&x);
				addedge(i+SHIFT,x,inf);
			}
			scanf("%d",&f);
			addedge(S,i+SHIFT,w+f*g);
		}
		else
		{
			for(int j=1;j<=k;j++)
			{
				scanf("%d",&x);
				addedge(x,i+SHIFT,inf);
			}
			scanf("%d",&f);
			addedge(i+SHIFT,T,w+f*g);
		}
	}
	int totf=0;
	while(mklevel())totf+=dinic(S,inf);
	printf("%d\n",tot-totf);
	return 0;
}