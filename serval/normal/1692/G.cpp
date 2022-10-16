#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 2e5 + 5;

int n, k;
int a[N], b[N];
int ans;

void solve()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i < n; i++)
		b[i] = (a[i] < 2 * a[i + 1]);
	for (int i = 1; i < n; i++)
		b[i] += b[i - 1];
	ans = 0;
	for (int i = k; i < n; i++)
		if (b[i] - b[i - k] == k)
			ans++;
	printf("%d\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}