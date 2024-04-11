#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

char M[MAXN][MAXN];
int n, m;

inline int solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char c;
			cin >> c;
			M[i][j] = c;
		}
	}

	if (m & 1) {
		cout << "YES" << endl;
		for (int i = 0; i <= m; i++) {
			if (i & 1) cout << 1 << sep;
			else cout << 2 << sep;
		}

		cout << endl;
		return 0;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (M[i][j] == M[j][i]) {
				cout << "YES" << endl;
				for (int k = 0; k <= m; k++) {
					if (k & 1) cout << i << sep;
					else cout << j << sep;
				}
				
				cout << endl;
				return 0;
			}
		}	
	}

	for (int v = 1; v <= n; v++) {
		int ina = 0, inb = 0, outa = 0, outb = 0;
		for (int u = 1; u <= n; u++) {
			if (v == u) continue;
			if (M[u][v] == 'a') ina = u;
			else inb = u;
			if (M[v][u] == 'a') outa = u;
			else outb = u;
		}

		if (outa != 0 && ina != 0) {
			cout << "YES" << endl;
			if (m % 4 == 0) {
				for (int i = 0; i <= m; i++) {
					if (i % 2 == 0) cout << v << sep;
					else if (i < m / 2) cout << ina << sep;
					else cout << outa << sep;
				}	
			} else {
				for (int i = 0; i <= m; i++) {
					if (i % 2 == 1) cout << v << sep;
					else if (i < m / 2) cout << ina << sep;
					else cout << outa << sep;
				}
			}

			cout << endl;
			return 0;
		}

		if (outb != 0 && inb != 0) {
			cout << "YES" << endl;
			if (m % 4 == 0) {
				for (int i = 0; i <= m; i++) {
					if (i % 2 == 0) cout << v << sep;
					else if (i < m / 2) cout << inb << sep;
					else cout << outb << sep;
				}	
			} else {
				for (int i = 0; i <= m; i++) {
					if (i % 2 == 1) cout << v << sep;
					else if (i < m / 2) cout << inb << sep;
					else cout << outb << sep;
				}
			}

			cout << endl;
			return 0;
		}
	} 
	cout << "NO" << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}