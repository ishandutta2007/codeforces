#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int N, M, K;
int a[200005];
pair<int, int> s[400005], t[400005];
int pp[400005];
ll dp[400005][2];
ll mx[400005][2];

void solve() {
	scanf("%d%d", &N, &M);
	repi(i, N) scanf("%d", a + i);
	sort(a + 1, a + N + 1);
	repi(i, M) scanf("%d%d", &s[i].first, &s[i].second);
	repi(i, N) s[++M] = make_pair(a[i], a[i]);
	sort(s + 1, s + M + 1, [&] (pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
	int cl = -Inf; K = 0;
	repi(i, M) {
		int pos = upper_bound(a + 1, a + N + 1, s[i].first) - a - 1;
		if (s[i].first > cl) {
			cl = s[i].first;
			t[++K] = s[i];
			pp[K] = pos;
		}
	}
	rep(i, K + 5) dp[i][0] = dp[i][1] = mx[i][0] = mx[i][1] = 1e18;
	int p = 1;
	while (!pp[p]) ++p;
	dp[1][0] = -t[1].second;
	dp[1][1] = -2 * t[1].second;
	mx[0][0] = dp[1][0];
	mx[0][1] = dp[1][1];
	repi(i, N) {
		int np = p;
		while (p <= K && pp[p] == i) ++p;
		for (int j = np; j < p; ++j) {
			ll cst = mx[i - 1][0] - a[i] + 2 * t[j].first;
			cst = min(cst, mx[i - 1][1] + a[i] + t[j].first);
			if (j == K) return printf("%lld\n", cst), void();
			dp[j + 1][0] = min(dp[j + 1][0], cst - t[j + 1].second);
			dp[j + 1][1] = min(dp[j + 1][1], cst - 2 * t[j + 1].second);
			mx[i][0] = min(mx[i][0], dp[j + 1][0]);
			mx[i][1] = min(mx[i][1], dp[j + 1][1]);
		}
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}