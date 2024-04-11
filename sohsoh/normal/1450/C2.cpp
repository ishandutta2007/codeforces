#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
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

const ll MAXN = 1000 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, k;
vector<pll> v[4];
char G[MAXN][MAXN];

int xx(int x) {
	return (x + 1) % 3;
}

int solve() {
	for (int i = 0; i < 4; i++) v[i].clear();
	cin >> n;
	k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> G[i][j];
			if (G[i][j] == 'X') {
				v[(i + j) % 3].push_back({i, j}), k++;
			} else if (G[i][j] == 'O') {
				int x = (i + j) % 3;
				v[xx(x)].push_back({i, j});	
				k++;
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		if (v[i].size() <= k / 3) {
			for (pll e : v[i]) {
				if (G[e.X][e.Y] == 'X') G[e.X][e.Y] = 'O';
				else G[e.X][e.Y] = 'X';
			}
			break;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << G[i][j];
		}

		cout << endl;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}	
	return 0;
}