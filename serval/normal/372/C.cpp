#include <cstdio>
using namespace std;
const int maxn=150005;
const int maxm=305;
long long f[2][maxn];
int n,m;
long long d;
int a[maxm];
long long b[maxm],t[maxm];
int i,j,k,l;
int q[maxn],ql,qr;
long long ca(long long v)
{
	return v>=0?v:-v;
}
int main()
{
	scanf("%d%d%lld",&n,&m,&d);
	for (i=1;i<=m;i++)
		scanf("%d%lld%lld",&a[i],&b[i],&t[i]);
	for (i=1;i<=m;i++)
	{
		k=i&1;
		ql=1;
		qr=0;
		l=n;
		if (d*(t[i]-t[i-1])<l)
			l=d*(t[i]-t[i-1]);
		for (j=1;j<=l;j++)
		{
			while (ql<=qr&&f[k^1][j]>f[k^1][q[qr]])
				qr--;
			q[++qr]=j;
		}
		for (j=1;j<=n;j++)
		{
			while (ql<=qr&&q[ql]<j-d*(t[i]-t[i-1]))
				ql++;
			if (j+d*(t[i]-t[i-1])<=n)
			{
				while (ql<=qr&&f[k^1][j+d*(t[i]-t[i-1])]>f[k^1][q[qr]])
					qr--;
				q[++qr]=j+d*(t[i]-t[i-1]);
			}
			f[k][j]=f[k^1][q[ql]]+b[i]-ca(a[i]-j);
		}
	}
	for (i=2;i<=n;i++)
		if (f[m&1][i-1]>f[m&1][i])
			f[m&1][i]=f[m&1][i-1];
	printf("%lld\n",f[m&1][n]);
	return 0;
}