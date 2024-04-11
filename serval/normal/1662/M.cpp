#include <cstdio>
#include <algorithm>

using namespace std;

void solve()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int r = 0, w = 0;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		r = max(r, x);
		w = max(w, y);
	}
	if (r + w > n)
	{
		printf("IMPOSSIBLE\n");
		return;
	}
	for (int i = 1; i <= r; i++)
		printf("R");
	for (int i = r + 1; i <= n; i++)
		printf("W");
	printf("\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}