#include <cstdio>
#include <algorithm>
using namespace std;
const int N=1e5+5;
const int P=105;
int n,m,p;
int d[N],h[N],t[N],ct[N];
long long s[N],cnt[N];
long long f[P][N];
int q[N],qt,ql;
double cv(int i,int x,int y)
{
	return ((f[i][x]-s[x]+cnt[x])-(f[i][y]-s[y]+cnt[y]))*1.0/(x-y);
}
int main()
{
	scanf("%d%d%d",&n,&m,&p);
	for (int i=2;i<=n;i++)
	{
		scanf("%d",&d[i]);
		d[i]+=d[i-1];
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&h[i],&t[i]);
		ct[i]=t[i]-d[h[i]];
	}
	sort(ct+1,ct+m+1);
	for (int i=1;i<=m;i++)
	{
		s[i]=s[i-1]+1ll*(i-1)*(ct[i]-ct[i-1]);
		cnt[i]=1ll*i*ct[i];
	}
	for (int i=1;i<=m;i++)
		f[1][i]=s[i];
	for (int i=2;i<=p;i++)
	{
		ql=qt=1;
		q[ql]=i-1;
		for (int j=i;j<=m;j++)
		{
			while (ql<qt&&cv(i-1,q[ql],q[ql+1])<ct[j])
				ql++;
			f[i][j]=s[j]-s[q[ql]]+f[i-1][q[ql]]-1ll*q[ql]*(ct[j]-ct[q[ql]]);
			while (ql<qt&&cv(i-1,j,q[qt])<cv(i-1,q[qt],q[qt-1]))
				qt--;
			q[++qt]=j;
		}
	}
	printf("%lld\n",f[p][m]);
	return 0;
}