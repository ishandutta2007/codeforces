#include <cstdio>
#include <algorithm>
using namespace std;
const int N=55;
const int M=305;
int n,m;
int u[M],v[M],w[M];
long long k[M],b[M];
int p[M],f[N];
int kv[M*M],cnt;
long long kans[M*M],bans[M*M];
int mid;
int qp,qk,qa,qb,qc;
long long ans;
bool cmp(int x,int y)
{
	return 1ll*mid*k[x]+2*b[x]<1ll*mid*k[y]+2*b[y];
}
int F(int u)
{
	return f[u]?f[u]=F(f[u]):u;
}
void kruskal(int id)
{
	int vl=kv[id-1],vr=kv[id]-1;
	mid=vl+vr;
	for (int i=1;i<=m;i++)
	{
		k[i]=(mid<2*w[i])?-1:1;
		b[i]=-1*k[i]*w[i];
		p[i]=i;
	}
	sort(p+1,p+m+1,cmp);
	for (int i=1;i<=n;i++)
		f[i]=0;
	for (int i=1;i<=m;i++)
	{
		int cur=p[i];
		if (F(u[cur])!=F(v[cur]))
		{
			f[F(u[cur])]=v[cur];
			kans[id]+=k[cur];
			bans[id]+=b[cur];
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
	for (int i=1;i<=m;i++)
		for (int j=i;j<=m;j++)
		{
			kv[++cnt]=(w[i]+w[j])>>1;
			if ((w[i]+w[j])&1)
				kv[++cnt]=(w[i]+w[j]+1)>>1;
		}
	kv[++cnt]=0;
	kv[++cnt]=1e8+1;
	sort(kv+1,kv+cnt+1);
	cnt=unique(kv+1,kv+cnt+1)-kv-1;
	for (int i=2;i<=cnt;i++)
		kruskal(i);
	scanf("%d%d%d%d%d",&qp,&qk,&qa,&qb,&qc);
	int las;
	for (int i=1;i<=qk;i++)
	{
		int qv;
		if (i<=qp)
			scanf("%d",&qv);
		else
			qv=(1ll*qa*las+qb)%qc;
		las=qv;
		int lb=lower_bound(kv+1,kv+cnt+1,qv+1)-kv;
		ans^=kans[lb]*qv+bans[lb];
	}
	printf("%lld\n",ans);
	return 0;
}