#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=2005;
const int maxe=20000005;
const int qtop=2005;
int n,m,k,s,t,ans;
int to[maxe],wt[maxe],nx[maxe],h[maxn],et;
int dis[maxn];
int i,j,u,v,w;
bool inq[maxn],vis[maxn];
int q[maxn],ql,qr,qt;
void addedge(int u,int v,int w)
{
	to[++et]=v;
	wt[et]=w;
	nx[et]=h[u];
	h[u]=et;
}
int main()
{
	scanf("%d%d",&n,&m);
	s++;t++;
	for (i=1;i<=m;i++)
	{
		scanf("%d",&u);
		vis[1002+u-n]=1;
		addedge(1,1002+u-n,1);
	}
	for (i=0;i<=1000;i++)
		if (vis[1002+i-n])
			if (i<n)
				for (j=n-i+2;j<=2002;j++)
					addedge(j,j+i-n,1);
			else
				for (j=2;j<=2002-i+n;j++)
					addedge(j,j+i-n,1);
	memset(dis,0x7f,sizeof(dis));
	s=1;
	t=1002;
	ans=0x7fffffff;
	dis[s]=0;
	qt=ql=qr=1;
	q[1]=s;
	inq[s]=1;
	while (qt)
	{
		for (i=h[q[ql]];i;i=nx[i])
			if (dis[to[i]]>dis[q[ql]]+wt[i]&&dis[q[ql]]+wt[i]<ans)
			{
				dis[to[i]]=dis[q[ql]]+wt[i];
				if (to[i]==t)
					if (ans>dis[to[i]])
						ans=dis[to[i]];
				if (!inq[to[i]])
				{
					qr++;qt++;
					if (qr>qtop)
						qr=1;
					q[qr]=to[i];
					inq[to[i]]=1;
				}
			}
		inq[q[ql]]=0;
		ql++;qt--;
		if (ql>qtop)
			ql=1;
	}
	if (ans==0x7fffffff)
		ans=-1;
	printf("%d\n",ans);
	return 0;
}