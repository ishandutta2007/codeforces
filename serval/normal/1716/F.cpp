#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2005;
const int mod = 998244353;

int s2[N][N];

int n, m, k;
int ndec[N], mpow[N], hmpow[N];
int ans;

int fpw(int b, int e)
{
	if (e == 0)
		return 1;
	int ret = fpw(b, e >> 1);
	ret = 1ll * ret * ret % mod;
	if (e & 1)
		ret = 1ll * ret * b % mod;
	return ret;
}

void solve()
{
	scanf("%d%d%d", &n, &m, &k);
	ndec[0] = 1;
	for (int i = 1, j = n; i <= k; i++, j--)
		ndec[i] = 1ll * ndec[i - 1] * j % mod;
	mpow[min(k, n)] = fpw(m, max(n - k, 0));
	for (int i = min(k, n); i; i--)
		mpow[i - 1] = 1ll * mpow[i] * m % mod;
	hmpow[0] = 1;
	for (int i = 1; i <= k; i++)
		hmpow[i] = 1ll * hmpow[i - 1] * ((m + 1) / 2) % mod;
	ans = 0;
	for (int c = 0; c <= k; c++)
		ans = (ans + 1ll * s2[k][c] * hmpow[c] % mod * ndec[c] % mod * mpow[c]) % mod;
	printf("%d\n", ans);
}

int main()
{
	s2[0][0] = 1;
	for (int i = 1; i < N; i++)
	{
		s2[i][0] = 0;
		for (int j = 1; j < N; j++)
			s2[i][j] = (s2[i - 1][j - 1] + 1ll * j * s2[i - 1][j]) % mod;
	}
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}