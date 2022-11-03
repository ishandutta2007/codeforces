#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define foreach(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

struct Pos {
	int x, l;
	bool operator < (const Pos &p) const {
		return x < p.x;
	}
} s[105];

int n;
int dp[105][105][2];

int main() {
	scanf("%d", &n);
	cont(i, n) {
		scanf("%d%d", &s[i].x, &s[i].l);
	}
	s[0].x = -Inf;
	sort(s + 1, s + n + 1);
	loop(i, n) loop(j, i + 1) loop(d, 2) {
		int cur = s[j].x + d * s[j].l, mx = -Inf, mxp, mxd;
		circ(k, i + 1, n) loop(nd, 2) {
			int nxt = s[k].x + nd * s[k].l;
			if (nxt > mx) mx = nxt, mxp = k, mxd = nd;
			dp[k][mxp][mxd] = max(dp[k][mxp][mxd], dp[i][j][d] + min(mx - nxt + s[k].l, mx - cur));
		}
	}
	int ans = 0;
	loop(j, n + 1) loop(d, 2) ans = max(ans, dp[n][j][d]);
	printf("%d\n", ans);
	return 0;
}