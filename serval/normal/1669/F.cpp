#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int n;
int w[N];

void solve()
{
	scanf("%d", &n);
	int ans = 0;
	for (int i = 1; i <= n; i++)
		scanf("%d", &w[i]);
	int l = 1, r = n;
	int sl = 0, sr = 0;
	while (l <= r)
	{
		if (sl == sr)
			ans = max(ans, n - (r - l + 1));
		if (sl <= sr)
			sl += w[l++];
		else
			sr += w[r--];
	}
	if (sl == sr)
		ans = max(ans, n - (r - l + 1));
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