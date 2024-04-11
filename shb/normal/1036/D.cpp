#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,M;
LL a[300010],b[300010],sa[300010],sb[300010];

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%lld",&a[i]),sa[i] = sa[i-1] + a[i];
	scanf("%d",&M);
	for (int i=1;i<=M;i++)scanf("%lld",&b[i]),sb[i] = sb[i-1] + b[i];
	if (sa[N] != sb[M])
	{
		puts("-1");
		return 0;
	}
	int ans = 0;
	for (int i=1;i<=N;i++)
	{
		LL tmp = *lower_bound(sb+1,sb+M+1,sa[i]);
		if (tmp == sa[i]) ans++;
	}
	printf("%d\n",ans);
}