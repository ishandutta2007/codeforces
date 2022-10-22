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

const ll MAXN = 62;
const ll MAXK = 1002;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int ans[MAXK][MAXN][MAXN], n, m, r, T[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> r;
	for (int i = 1; i < MAXN; i++) for (int j = 1; j < MAXN; j++) ans[0][i][j] = INF;
	for (int t = 0; t < m; t++) {
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= n; j++)
				cin >> T[i][j];
		for (int k = 1; k <= n; k++) 
			for (int i = 1; i <= n; i++) 
				for (int j = 1; j <= n; j++) 
					T[i][j] = min(T[i][j], T[i][k] + T[k][j]);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				ans[0][i][j] = min(ans[0][i][j], T[i][j]);
	}

	for (int tk = 1; tk < MAXK; tk++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				ans[tk][i][j] = ans[tk - 1][i][j];
				for (int k = 1; k <= n; k++) {
					ans[tk][i][j] = min(ans[tk][i][j], ans[tk - 1][i][k] + ans[0][k][j]);
				}
			}	
		}
	}


	while (r--) {
		int u, v, k;
		cin >> u >> v >> k;
		cout << ans[k][u][v] << endl;
	}
	return 0;
}