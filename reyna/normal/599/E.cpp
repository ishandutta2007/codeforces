//In the name of God
// (c) Silver soul 49
// What i'll engrave in this place is my soul!!!

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, e) for(int i = (s); i < (e); i++)
#define x first
#define y second
#define int long long

typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin (P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax (P &a, Q b) { if (a < b) a = b; return a; }


int pw (int a, int b, int mod) { return (b? pw(1LL * a * a % mod, b >> 1, mod) * 1LL * (b & 1? a : 1) % mod: 1); }
int lcm (int x, int y) { return min(x, y)? x / __gcd(x, y) * y: max(x, y); }

/*******************************************************************************************************/

const int maxN = 13;
const int mod = 0;
const int base = 1000 * 1000 + 3;
const int oo = 1e9 + 49;
const int maxM = 27 * 27 * 27 * 3;

long long dp[1 << maxN][maxN];
int who[maxN][1 << maxN], adj[maxN], lca[maxN][maxN], sz;

int who_merge (int a, int b) {
	if (a == -2) return b;
	if (b == -2) return a;
	if (a == b) return a;
	return -1;	
}

int32_t main () {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 0; i < maxN; i++)
		for (int j = 0; j < maxN; j++) {
			lca[i][j] = -2;	
		}
	for (int i = 0; i < maxN; i++)
		for (int j = 0; j < (1 << maxN); j++)
			who[i][j] = -2;
	int n, m, q; cin >> n >> m >> q;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; --u, --v;
		adj[u] |= 1 << v;
		adj[v] |= 1 << u;	
	}
	for (int i = 0; i < q; i++) {
		int u, v, p; cin >> u >> v >> p; --u, --v, --p;
		if ((lca[u][v] != -2 && lca[u][v] != p) || (u == v && p != v)) {
			cout << 0 << '\n';
			return 0;
		}
		lca[u][v] = lca[v][u] = p;
	}
	for (int i = 0; i < n; i++) dp[1 << i][i] = 1;
	for (int i = 0; i < n; i++)
		for (int mask = 0; mask < (1 << n); mask++) if ((mask >> i & 1) == 0) {
			for (int j = 0; j < n; j++) if (mask >> j & 1)
				who[i][mask] = who_merge(who[i][mask], lca[i][j]);
		}
	for (int sub = 1; sub < (1 << n); sub++) {
		int xx = (1 << n) - 1;
		for (int mm = 0; mm < (1 << n); mm++) if (((sub ^ xx) & mm) == mm) {
			int mask = sub ^ mm, maskl = mask ^ sub, maskr = sub;
			ll suml = 0, sumr = 0;
			for (int rootr = 0; rootr < n; rootr++) if (maskr >> rootr & 1)
				sumr += dp[maskr][rootr];
			for (int rootl = 0; rootl < n; rootl++) if (maskl >> rootl & 1)
				suml += dp[maskl][rootl];
			int rl = -2, rr = -2, rkol = -2;
			for (int i = 0; i < n; i++) {
				if (maskl >> i & 1) {
					if (adj[i] & maskr)
						rl = who_merge(rl, i);
					rl = who_merge(who[i][maskr], rl);
					rkol = who_merge(who[i][maskr], rkol);
				}
				if (maskr >> i & 1) {
					if (adj[i] & maskl)
						rr = who_merge(rr, i);
				}
			}
			if (rkol == -1 || rl == -1 || rr == -1)
				continue;
			if (rkol == -2 && rl != -2) rkol = rl;
			if (rkol != -2) {
				int root = rl;
				if (rr == -2)
					dp[mask][root] += sumr * dp[maskl][root];
				else
					dp[mask][root] += dp[maskr][rr] * dp[maskl][root];
			} else {
				for (int root = 0; root < n; root++) if (maskl >> root & 1) {
					if (rr == -2)
						dp[mask][root] += sumr * dp[maskl][root];
					else
						dp[mask][root] += dp[maskr][rr] * dp[maskl][root];	
				}
			}
		}
	}
	cout << dp[(1 << n) - 1][0] << '\n';
}