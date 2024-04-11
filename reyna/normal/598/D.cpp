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

const int maxN = 1049;
const int mod = 0;
const int base = 1000 * 1000 + 3;
const int oo = 1e9 + 49;

int col[maxN][maxN], cnt[maxN * maxN], sz = 1, n, m;
string s[maxN];

void dfs (int x, int y) {
	if (col[x][y]) return;
	col[x][y] = sz;
	for (int l = -1; l < 2; l++)
		for (int r = -1; r < 2; r++) {
			if (abs(l + r) == 1) {
				int i = x + l, j = y + r;
				if (i < 0 || j < 0 || i == n || j == m)
					continue;
				if (s[i][j] == '*')
					cnt[sz]++;
				else
					dfs(i, j);
			}
		}
}

int32_t main () {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q; cin >> n >> m >> q;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) if (s[i][j] == '.' && !col[i][j])
			dfs(i, j), sz++;
	while (q--) {
		int x, y; cin >> x >> y; --x, --y;
		cout << cnt[col[x][y]] << '\n';	
	}
}