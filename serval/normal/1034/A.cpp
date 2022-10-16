#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,j,g,l;
int a[300005];
int cnt[15000005];
int f[15000005];
int pr[15000005],prtot;
bool np[15000005];
int gcd(int x,int y)
{
	return x%y==0?y:gcd(y,x%y);
}
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	g=a[1];
	for (i=2;i<=n;i++)
		g=gcd(g,a[i]);
	for (i=1;i<=n;i++)
		a[i]/=g;
	for (i=2;i<=15000005;i++)
	{
		if (!np[i])
		{
			prtot++;
			pr[prtot]=i;
			f[i]=i;
		}
		for (j=1;j<=prtot&&i*pr[j]<=15000000;j++)
		{
			np[i*pr[j]]=1;
			f[i*pr[j]]=pr[j];
			if (pr[j]%i==0)
				break;
		}
	}
	for (i=1;i<=n;i++)
	{
		j=a[i];
		l=0;
		while (j!=1)
		{
			if (f[j]!=l)
				cnt[f[j]]++;
			l=f[j];
			j/=f[j];
		}
	}
	j=0;
	for (i=1;i<=prtot;i++)
		if (cnt[pr[i]]>cnt[j])
			j=pr[i];
	if (j)
		printf("%d\n",n-cnt[j]);
	else
		printf("%d\n",-1);
	return 0;
}