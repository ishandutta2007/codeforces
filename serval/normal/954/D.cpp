#include <cstdio>
using namespace std;
int n,m,s,t,i,j,u,v,l,ans;
int dis1[1005],dis2[1005];
int q[100005],ql,qr;
bool inq[1005];
int h[1005],to[2005],nx[2005],et;
bool mat[1005][1005];
void addedge(int u,int v)
{
	et++;
	to[et]=v;
	nx[et]=h[u];
	h[u]=et;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for (i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
		mat[u][v]=1;
		mat[v][u]=1;
	}
	for (i=1;i<=n;i++)
	{
		dis1[i]=n;
		dis2[i]=n;
	}
	ql=qr=1;
	q[1]=s;
	inq[s]=1;
	dis1[s]=0;
	while (ql<=qr)
	{
		for (i=h[q[ql]];i;i=nx[i])
			if (dis1[q[ql]]+1<=dis1[to[i]])
			{
				dis1[to[i]]=dis1[q[ql]]+1;
				if (!inq[to[i]])
				{
					qr++;
					q[qr]=to[i];
					inq[to[i]]=1;
				}
			}
		inq[q[ql]]=0;
		ql++;
	}
	ql=qr=1;
	q[1]=t;
	inq[t]=1;
	dis2[t]=0;
	while (ql<=qr)
	{
		for (i=h[q[ql]];i;i=nx[i])
			if (dis2[q[ql]]+1<=dis2[to[i]])
			{
				dis2[to[i]]=dis2[q[ql]]+1;
				if (!inq[to[i]])
				{
					qr++;
					q[qr]=to[i];
					inq[to[i]]=1;
				}
			}
		inq[q[ql]]=0;
		ql++;
	}
	l=dis2[s];
	for (i=1;i<n;i++)
		for (j=i+1;j<=n;j++)
			if (mat[i][j]==0)
				if (dis1[i]+dis2[j]+1>=l&&dis1[j]+dis2[i]+1>=l)
					ans++;
	printf("%d\n",ans);
	return 0;
}