//In the name of God
// (c) Silver soul 49
// What i'll engrave in this place is my soul!!!

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, e) for(int i = (s); i < (e); i++)
#define x first
#define y second

typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin (P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax (P &a, Q b) { if (a < b) a = b; return a; }


int pw (int a, int b, int mod) { return (b? pw(1LL * a * a % mod, b >> 1, mod) * 1LL * (b & 1? a : 1) % mod: 1); }
int lcm (int x, int y) { return min(x, y)? x / __gcd(x, y) * y: max(x, y); }

/*******************************************************************************************************/

const int maxN = 409;
const int mod = 0;
const int base = 1000 * 1000 + 3;
const int oo = 1e9 + 49;

int d[maxN][maxN];

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			d[i][j] = oo;
	for (int i = 0; i < n; i++)
		d[i][i] = 0;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; --u, --v;
		d[u][v] = d[v][u] = 1;
	}
	if (d[0][n - 1] == 1) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) if (i != j) {
				if (d[i][j] == oo) d[i][j] = 1;
				else d[i][j] = oo;	
			}
	}
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				smin(d[i][j], d[i][k] + d[k][j]);
	cout << (d[0][n - 1] == oo? -1: d[0][n - 1]);
	
}