#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int n, x;
int a[N];
long long s[N], k[N];
long long ans;

void solve()
{
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	ans = 0;
	for (int i = 1; i <= n; i++)
	{
		s[i] = s[i - 1] + a[i];
		// s[i] + k * i <= x
		k[i] = max(0LL, x - s[i] + i) / i;
		ans += k[i];
	}
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