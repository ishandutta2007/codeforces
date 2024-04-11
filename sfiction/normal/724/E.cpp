#include <climits>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1E4 + 10;

int p[MAXN], s[MAXN];
ll dp[2][MAXN];

int main(){
	int n;
	ll c;
	scanf("%d%lld", &n, &c);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &p[i]);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &s[i]);
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i){
		ll *f = dp[i & 1], *g = dp[i + 1 & 1];
		fill_n(g, i + 2, LLONG_MAX);
		for (int j = 0; j <= i; ++j){
			g[j] = min(g[j], f[j] + p[i + 1] + j * c);
			g[j + 1] = min(g[j + 1], f[j] + s[i + 1]);
		}
	}
	ll ans = LLONG_MAX;
	for (int i = 0; i <= n; ++i)
		ans = min(ans, dp[n & 1][i]);
	printf("%lld\n", ans);
	return 0;
}