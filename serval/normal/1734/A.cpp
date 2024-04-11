#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 305;
const int oo = 1e9 + 5;

int n;
int a[N];
int ans;

void solve()
{
	scanf("%d", &n);
	ans = oo;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n - 2; i++)
		ans = min(ans, a[i + 2] - a[i]);
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