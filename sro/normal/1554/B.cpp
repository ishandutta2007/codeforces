#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;

int N, K;
int a[100005];

void solve() {
	scanf("%d%d", &N, &K);
	repi(i, N) scanf("%d", a + i);
	ll ans = -0x3f3f3f3f3f3f3f3fll;
	for (int i = max(1, N - 3 * K); i <= N; ++i) for (int j = max(1, N - 3 * K); j < i; ++j) ans = max(ans, 1ll * i * j - 1ll * K * (a[i] | a[j]));
	printf("%lld\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	while(T--) solve();
	return 0;
}