#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

const int N = 2e5 + 5;

int n;
int a[N], b[N], c[N];
long long ans;

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		b[i] = c[i] = 0;
	}
	ans = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] < i)
		{
			b[a[i]]++;
			c[i]++;
		}
	for (int i = 1; i <= n; i++)
		c[i] += c[i - 1];
	for (int i = 1; i <= n; i++)
		ans += 1ll * b[i] * c[i - 1];
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