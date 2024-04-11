#include<bits/stdc++.h>
using namespace std;
namespace flow
{
	const int MAXN=7777,MAXM=233333;
	const int S=1,T=2,A=3,B=1007,C=2011,E1=3020,E2=5030;
	const long long inf=0,INF=1e18;
	struct edge
	{
		int v;
		long long f;
		edge *next,*rev;
	}*h[MAXN],pool[MAXM*2];
	int top;
	inline void addedge(int u,int v,long long c)
	{
//		cerr<<"addedge "<<u<<' '<<v<<' '<<c<<endl;
		edge *tmp=&pool[top++];tmp->v=v;tmp->next=h[u];h[u]=tmp;tmp->f=c;
		edge *pmt=&pool[top++];pmt->v=u;pmt->next=h[v];h[v]=pmt;pmt->f=0;
		tmp->rev=pmt;pmt->rev=tmp;
	}
	int level[MAXN];
	bool mklevel()
	{
		queue<int> q;
		memset(level,-1,sizeof(level));
		q.push(S);
		level[S]=0;
		while(not q.empty())
		{
			int u=q.front();q.pop();
			for(edge *tmp=h[u];tmp;tmp=tmp->next)
			{
				if(level[tmp->v]==-1 and tmp->f)
				{
					level[tmp->v]=level[u]+1;
					q.push(tmp->v);
				}
			}
			if(level[T]!=-1)return true;
		}
		return false;
	}
	long long dinic(int u,long long minf)
	{
		if(u==T)return minf;
		long long totf=0;
		for(edge *tmp=h[u];tmp;tmp=tmp->next)
		{
			if(tmp->f and level[tmp->v]==level[u]+1)
			{
				long long f=dinic(tmp->v,min(minf-totf,tmp->f));
				tmp->f-=f;
				tmp->rev->f+=f;
				totf+=f;
				if(totf==minf)return totf;
			}
		}
		if(totf==0)level[u]=-1;
		return totf;
	}
	long long gao()
	{
		long long totf=0;
		while(mklevel())totf+=dinic(S,INF);
		return totf;
	}
}
using flow::gao;
using flow::S;
using flow::T;
using flow::A;
using flow::B;
using flow::C;
using flow::E1;
using flow::E2;
using flow::addedge;
using flow::inf;
using flow::INF;
using flow::level;
long long sl[1111];
int main()
{
	ios_base::sync_with_stdio(false);
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	long long sw=0;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		long long w;
		cin>>u>>v>>w;
		addedge(E1+i,T,2*w);
		addedge(E2+i,T,2*w);
		addedge(A+u,E1+i,INF);
		addedge(B+v,E1+i,INF);
		addedge(A+v,E2+i,INF);
		addedge(B+u,E2+i,INF);
		sw+=w;
		sl[u]+=w;
		sl[v]+=w;
	}
	addedge(S,A+b,INF);
	addedge(S,B+a,INF);
	addedge(B+b,T,INF);
	addedge(A+a,T,INF);
	for(int i=1;i<=n;i++)
	{
		addedge(S,A+i,sl[i]+inf);
		addedge(S,B+i,sl[i]+inf);
		addedge(A+i,T,inf);
		addedge(B+i,T,inf);
	}
	cout<<gao()-inf*n*2-4*sw<<endl;
	flow::mklevel();
	for(int i=1;i<=n;i++)
	{
		if(level[A+i]==-1 and level[B+i]==-1)cout<<'C';
		else if(level[A+i]==-1)cout<<'A';
		else if(level[B+i]==-1)cout<<'B';
		else assert(0);
	}
	return 0;
}