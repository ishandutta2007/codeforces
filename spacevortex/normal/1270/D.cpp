#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<int> VC;
const int N=1050;
int n,K;
int h[N];
namespace GR
{
	int n,m,K;
	int a[N];
	void init()
	{
		int i;
		ifstream A("t.in");
		A>>n>>K>>m;
		for(i=1;i<=n;i++) A>>a[i];
	}
	void qry(VC A,int &pos,int &val)
	{
		int i,j,x,num;
		for(i=0;i<K;i++)
		{
			x=A[i];
			num=0;
			for(j=0;j<K;j++)
			{
				if(a[A[j]]<=a[x]) num++;
			}
			if(num==m) 
			{
				pos=x;val=a[x];return ;
			}
		}
	}
}
void qry(VC A,int &pos,int &val)
{
	//return GR::qry(A,pos,val);
	int i;
	printf("? ");
	for(i=0;i<K;i++) printf("%d ",A[i]);
	putchar('\n');
	fflush(stdout);
	scanf("%d%d",&pos,&val);
}
void answer(int m)
{
	printf("! %d\n",m);
	fflush(stdout);
	exit(0);
}
vector<int> e[N];
int p,id,w;
bool vis[N];
void dfs(int x)
{
	if(vis[x]) return ;
	//printf("N%d\n",x);
	vis[x]=1;
	for(int v:e[x])
	{
		h[v]=h[x];
		dfs(v);
	}
}
int main()
{
	//GR::init();
	//freopen("a.in","r",stdin);
	int i,j,np,nw,m=0;
	VC s,bs;
	scanf("%d%d",&n,&K);
	if(K==1) answer(1);
	s.clear();
	for(i=1;i<=K;i++) s.pb(i);
	qry(s,p,w);
	if(p!=1) id=1;
	else id=2;
	bs.clear();
	for(i=1;i<=K;i++) if(i!=id) bs.pb(i);
	for(i=K+1;i<=n;i++)
	{
		s=bs;s.pb(i);
		qry(s,np,nw);
		if(nw>w) h[id]=-1,h[i]=1;
		else if(nw<w) h[id]=1,h[i]=-1;
		else e[id].pb(i),e[i].pb(id);
	}
	for(i=1;i<=K;i++)
	{
		if(i==p||i==id) continue;
		s.clear();
		for(j=1;j<=K+1;j++) if(j!=i) s.pb(j);
		qry(s,np,nw);
		if(nw>w) h[i]=-1,h[K+1]=1;
		else if(nw<w) h[i]=1,h[K+1]=-1;
		else e[i].pb(K+1),e[K+1].pb(i);
	}
	for(i=1;i<=n;i++) if(h[i]) dfs(i);
	//printf("I%d %d\n",p,w);
	//for(i=1;i<=n;i++) printf("#%d %d\n",i,h[i]);
	if(h[id]==0) 
	{
		s.clear();
		for(i=1;i<=K+1;i++) if(i!=p) s.pb(i);
		qry(s,np,nw);
		if(nw<w) answer(K);
		else answer(1);
	}
	else
	{
		m=1;
		for(i=1;i<=K;i++) if(h[i]==-1) m++;
		answer(m);
	}
	return 0;
}