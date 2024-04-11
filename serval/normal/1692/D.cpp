#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 60;

int vis[N][N];

void pass(int &h, int &m, int d)
{
	int t = h * 60 + m;
	t = (t + d) % (24 * 60);
	h = t / 60;
	m = t % 60;
}

void solve()
{
	memset(vis, 0, sizeof(vis));
	int h, m, d;
	scanf("%d:%d", &h, &m);
	scanf("%d", &d);
	while (!vis[h][m])
	{
		vis[h][m] = 1;
		pass(h, m, d);
	}
	int ans = 0;
	for (int i = 0; i < 24; i++)
	{
		int b1 = i / 10;
		int b0 = i % 10;
		int tt = b0 * 10 + b1;
		if (tt < 60)
			ans += vis[i][tt];
	}
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