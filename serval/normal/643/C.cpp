#include <cstdio>
using namespace std;
int n,k,i,j,x;
double t[200005];
double pre[200005],sum[200005],rev[200005];
double f[51][200005];
int q[2][200005],ql[2],qr[2];
double slope(int p,int a,int b)
{
	return (f[p][b]-f[p][a]-pre[b]+pre[a]
		-rev[a]*sum[a]+rev[b]*sum[b])
		/(sum[b]-sum[a]);
}
int main()
{
	scanf("%d%d",&n,&k);
	for (i=1;i<=n;i++)
	{
		scanf("%lf",&t[i]);
		sum[i]=sum[i-1]+t[i];
		rev[i]=rev[i-1]+1.0/t[i];
	}
	for (i=1;i<=n;i++)
		pre[i]=pre[i-1]+sum[i]/t[i];
	for (j=1;j<=k;j++)
	{
		x=j&1;
		ql[x]=qr[x]=0;
		for (i=1;i<=n;i++)
		{
			while (ql[x^1]<qr[x^1]&&slope(j-1,q[x^1][ql[x^1]],q[x^1][ql[x^1]+1])<rev[i])
				ql[x^1]++;
			f[j][i]=pre[i]+f[j-1][q[x^1][ql[x^1]]]-pre[q[x^1][ql[x^1]]]
				-rev[i]*sum[q[x^1][ql[x^1]]]+rev[q[x^1][ql[x^1]]]*sum[q[x^1][ql[x^1]]];
			while (ql[x]<qr[x]&&slope(j,q[x][qr[x]],i)<slope(j,q[x][qr[x]-1],q[x][qr[x]]))
				qr[x]--;
			q[x][++qr[x]]=i;
		}
	}
	printf("%.10lf\n",f[k][n]);
	return 0;
}