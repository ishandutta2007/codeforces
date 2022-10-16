#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 50;

int n;
int a[N], b[N];
long long f[2][N];

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	f[0][0] = f[1][0] = 0;
	f[0][1] = f[1][1] = 0;
	for (int i = 2; i <= n; i++)
	{
		f[0][i] = min(f[0][i - 1] + abs(a[i] - a[i - 1]) + abs(b[i] - b[i - 1]),
			f[1][i - 1] + abs(a[i] - b[i - 1]) + abs(b[i] - a[i - 1]));
		f[1][i] = min(f[0][i - 1] + abs(b[i] - a[i - 1]) + abs(a[i] - b[i - 1]),
			f[1][i - 1] + abs(b[i] - b[i - 1]) + abs(a[i] - a[i - 1]));
	}
	printf("%lld\n", min(f[0][n], f[1][n]));
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}