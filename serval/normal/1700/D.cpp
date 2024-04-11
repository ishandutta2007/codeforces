#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int n, q;
long long v[N], pre[N];
long long lim;

void solve()
{
	scanf("%d", &n);
	lim = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &v[i]);
		pre[i] = pre[i - 1] + v[i];
		lim = max(lim, (pre[i] + i - 1) / i);
	}
	scanf("%d", &q);
	while (q--)
	{
		long long t;
		scanf("%lld", &t);
		if (t < lim)
			printf("-1\n");
		else
			printf("%lld\n", (pre[n] + t - 1) / t);
	}
}

int main()
{
	int T;
	T = 1; //scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}