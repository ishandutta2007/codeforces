// Sohsoh84 O_o //
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

const ll MAXN = 500 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

char G[MAXN][MAXN];

inline int solve() {
	int n, m;
	cin >> n >> m;
	pll p = {-1, -1};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			G[i][j] = c;
			if (c != '.') p = {i, j};
		}
	}

	if (p.X == -1) p = {0, 0}, G[0][0] = 'R';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char t = G[p.X][p.Y];
			if (abs(i + j - p.X - p.Y) & 1) {
				if (t == 'R') t = 'W';
				else t = 'R';
			}
		
			if (G[i][j] == '.') G[i][j] = t;
			else if (G[i][j] != t) return cout << "NO" << endl, 0;
		}
	}

	cout << "YES" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << G[i][j];
		cout << endl;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}