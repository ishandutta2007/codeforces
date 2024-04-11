#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1005;

int n, q;
long long s[N][N];

void solve()
{
	scanf("%d%d", &n, &q);
	memset(s, 0, sizeof(s));
	for (int i = 1; i <= n; i++)
	{
		int h, w;
		scanf("%d%d", &h, &w);
		s[h][w] += 1ll * h * w;
	}
	for (int i = 1; i < N; i++)
		for (int j = 1; j < N; j++)
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
	while (q--)
	{
		int h1, w1, h2, w2;
		scanf("%d%d%d%d", &h1, &w1, &h2, &w2);
		long long ans = 0;
		ans = s[h2 - 1][w2 - 1] - s[h1][w2 - 1] - s[h2 - 1][w1] + s[h1][w1];
		printf("%lld\n", ans);
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}