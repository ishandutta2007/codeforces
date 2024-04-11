#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;
const long long MAX = 1e18;

int n, x;
int a[N], b[N];
long long ans;

long long cal(int p1, int px)
{
	long long ret = 0;
	if (p1 <= 0 && px <= 0)
		ret += x - 1;
	if (p1 > n && px > n)
		ret += x - 1;
	for (int i = 1; i <= n; i++)
		b[i] = a[i];
	if (1 <= p1 && p1 <= n)
		b[p1] = min(b[p1], 1);
	if (1 <= px && px <= n)
		b[px] = max(b[px], x);
	if (p1 == 0)
		ret += abs(b[1] - 1);
	if (px == 0)
		ret += abs(b[1] - x);
	if (p1 == n + 1)
		ret += abs(b[n] - 1);
	if (px == n + 1)
		ret += abs(b[n] - x);
	for (int i = 2; i <= n; i++)
		ret += abs(b[i] - b[i - 1]);
	return ret;
}

void solve()
{
	ans = MAX;
	scanf("%d%d", &n, &x);
	int mn = 0, mx = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (mn == 0 || a[i] < a[mn])
			mn = i;
		if (mx == 0 || a[i] > a[mx])
			mx = i;
	}
	ans = min(ans, cal(-1, 0));
	ans = min(ans, cal(0, -1));
	if (mx != 1)
		ans = min(ans, cal(0, mx));
	if (mn != 1)
		ans = min(ans, cal(mn, 0));
	if (mn != mx)
		ans = min(ans, cal(mn, mx));
	if (mx != n)
		ans = min(ans, cal(n + 1, mx));
	if (mn != n)
		ans = min(ans, cal(mn, n + 1));
	ans = min(ans, cal(n + 1, n + 2));
	ans = min(ans, cal(n + 2, n + 1));
	ans = min(ans, cal(0, n + 1));
	ans = min(ans, cal(n + 1, 0));
	printf("%lld\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}