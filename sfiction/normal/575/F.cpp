#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 5E3 + 10;
const ll INF = 1ll << 60;

int n, m, start;
int a[MAXN << 1], l[MAXN], r[MAXN];
ll dp[2][MAXN << 1];

inline int getid(int x){
	return lower_bound(a, a + m, x) - a;
}

int main(){
	scanf("%d%d", &n, &start);
	a[0] = start;
	m = 1;
	for (int i = 1; i <= n; ++i){
		scanf("%d%d", &l[i], &r[i]);
		a[m++] = l[i];
		a[m++] = r[i];
	}
	sort(a, a + m);
	m = unique(a, a + m) - a;

	for (int i = 0; i < m; ++i)
		dp[0][i] = INF;
	dp[0][getid(start)] = 0;
	for (int i = 1; i <= n; ++i){
		ll (&f)[MAXN << 1] = dp[i + 1 & 1], (&g)[MAXN << 1] = dp[i & 1];

		g[0] = f[0];
		for (int j = 1; j < m; ++j)
			g[j] = min(g[j - 1] + a[j] - a[j - 1], f[j]);
		ll val = g[m - 1];
		for (int j = m - 2; j >= 0; --j)
			g[j] = min(g[j], val = min(val + a[j + 1] - a[j], f[j]));

		for (int j = 0; a[j] < l[i]; ++j)
			g[j] += l[i] - a[j];
		for (int j = m - 1; r[i] < a[j]; --j)
			g[j] += a[j] - r[i];
	}
	ll ans = INF;
	for (int i = 0; i < m; ++i)
		ans = min(ans, dp[n & 1][i]);
	printf("%I64d\n", ans);
	return 0;
}