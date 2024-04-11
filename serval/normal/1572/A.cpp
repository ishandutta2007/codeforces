#include <cstdio>
using namespace std;
const int N=2e5+5;
const int E=N<<1;
int T;
int n;
int indeg[N],ind0[N],ql,qr;
int h[N],to[E],nx[E],tp[E],et;
int f[N];
void ae(int u,int v,int t)
{
	et++;
	to[et]=v;
	nx[et]=h[u];
	tp[et]=t;
	h[u]=et;
}
int solve()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		f[i]=ind0[i]=h[i]=0;
	et=qr=0;
	ql=1;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&indeg[i]);
		if (indeg[i]==0)
			ind0[++qr]=i;
		for (int j=1;j<=indeg[i];j++)
		{
			int u;
			scanf("%d",&u);
			ae(u,i,0);
			ae(i,u,1);
		}
	}
	while (ql<=qr)
	{
		int cur=ind0[ql];
		for (int i=h[cur];i;i=nx[i])
			if (tp[i]==0)
			{
				int des=to[i];
				indeg[des]--;
				if (indeg[des]==0)
					ind0[++qr]=des;
			}
		ql++;
	}
	if (qr!=n)
		return -1;
	for (int i=1;i<=n;i++)
	{
		int cur=ind0[i];
		int mx=1;
		for (int j=h[cur];j;j=nx[j])
			if (tp[j]==1)
			{
				int v=f[to[j]];
				if (to[j]>cur)
					v++;
				if (v>mx)
					mx=v;
			}
		f[cur]=mx;
	}
	int mx=0;
	for (int i=1;i<=n;i++)
		if (f[i]>mx)
			mx=f[i];
	return mx;
}
int main()
{
	scanf("%d",&T);
	while (T--)
		printf("%d\n",solve());
	return 0;
}