#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

const int L = 32;
const int N = 1e5 + 5;
const long long oo = 1e18;

int n, k;
int a[N];
int dc[L][N];
long long f[L][N];
long long ans;

void solve()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int x = 0; x < L; x++)
		for (int i = 0; i <= n; i++)
		{
			f[x][i] = -oo;
			if (x == 0)
				dc[x][i] = a[i];
			else
				dc[x][i] = dc[x - 1][i] / 2;
		}
	f[0][0] = 0;
	for (int x = 0; x < L; x++)
		for (int i = 1; i <= n; i++)
		{
			f[x][i] = f[x][i - 1] + dc[x][i] - k;
			if (x == L - 1)
				f[x][i] = max(f[x][i], f[x][i - 1] + dc[x][i]);
			if (x > 0)
				f[x][i] = max(f[x][i], f[x - 1][i - 1] + dc[x][i]);
		}
	ans = -oo;
	for (int x = 0; x < L; x++)
		ans = max(ans, f[x][n]);
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