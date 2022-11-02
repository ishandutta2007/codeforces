#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

#define LL long long
#define ULL unsigned long long
#define m_p make_pair
#define l_b lower_bound
#define p_b push_back
#define w1 first
#define w2 second
#define maxlongint 2147483647
#define biglongint 2139062143

const int maxn=500005;

int fa[maxn],xc[maxn],yc[maxn],usec[maxn],xd[maxn],yd[maxn],used[maxn],faF[maxn],faG[maxn];
set<PII> Pc;
set<PII>::iterator Pg;
vector<PII> F[maxn],G[maxn];
int N,root,ans,x,y;

int getwhere(int s)
{
	while (fa[s]!=s) s=fa[s];
	return s;
}

int merge(int x,int y)
{
	int xc=getwhere(x),yc=getwhere(y),uu;
	if (xc!=yc)
	{
		fa[xc]=yc;
		while (fa[x]!=yc) uu=fa[x],fa[x]=yc,x=uu;
		while (fa[y]!=yc) uu=fa[y],fa[y]=yc,y=uu;
	}
}

void dfs(int s,int fa,const vector<PII> F[],int *faF)
{
	for (int i=0;i<F[s].size();i++)
		if (F[s][i].w1!=fa)
		{
			faF[F[s][i].w1]=F[s][i].w2;
			dfs(F[s][i].w1,s,F,faF);
		}
}

void dfs2(int s,int fa)
{
	for (int i=0;i<F[s].size();i++)
		if (F[s][i].w1!=fa) dfs2(F[s][i].w1,s);
	if (s!=root) printf("%d %d %d %d\n",xc[faF[s]],yc[faF[s]],xd[faG[s]],yd[faG[s]]);
}

int main()
{
	//freopen("E.in","r",stdin);
	//freopen("E.out","w",stdout);
	
	scanf("%d",&N);
	memset(usec,0,sizeof(usec));
	for (int i=1;i<N;i++)
	{
		scanf("%d %d",&xc[i],&yc[i]);
		if (xc[i]<yc[i]) swap(xc[i],yc[i]);
		Pc.insert(m_p(xc[i],yc[i]));
	}
	memset(used,0,sizeof(used));
	for (int i=1;i<N;i++)
	{
		scanf("%d %d",&xd[i],&yd[i]);
		if (xd[i]<yd[i]) swap(xd[i],yd[i]);
		PII tmp=m_p(xd[i],yd[i]);
		Pg=Pc.l_b(tmp);
		if ((Pg!=Pc.end())&&(*(Pg)==tmp))
			used[i]=-1,
			Pc.insert(m_p(-xd[i],yd[i]));
	}
	for (int i=1;i<N;i++)
		if (Pc.find(m_p(-xc[i],yc[i]))!=Pc.end())
			usec[i]=-1;
			
	for (int i=1;i<=N;i++) fa[i]=i;
	for (int i=1;i<N;i++)
		if (usec[i]==-1) merge(xc[i],yc[i]);
	
	for (int i=1;i<N;i++)
	{
		if (usec[i]==0)
		{
			x=getwhere(xc[i]),y=getwhere(yc[i]);
			F[x].p_b(m_p(y,i));
			F[y].p_b(m_p(x,i));
		}
		if (used[i]==0)
		{
			x=getwhere(xd[i]),y=getwhere(yd[i]);
			G[x].p_b(m_p(y,i));
			G[y].p_b(m_p(x,i));
			
		}
	}
	root=0,ans=0;
	for (int i=1;i<=N;i++)
		if (fa[i]==i) root=i,ans++;
	memset(faF,0,sizeof(faF));
	memset(faG,0,sizeof(faG));
	dfs(root,0,F,faF);
	dfs(root,0,G,faG);
	
	printf("%d\n",ans-1);
	dfs2(root,0);

	return 0;
}