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

const ll MAXN = 100 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, state[MAXN][MAXN];
bool vis[MAXN];

inline void GO(int k) {
	memset(vis, false, sizeof vis);
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		vis[i] = true;
		int v = i;
		while (true) {
			int u = v + k - 1;
			u = u % n + 1;
			state[v][u] = 1;
			state[u][v] = -1;
			if (vis[u]) break;
			vis[u] = true;
			v = u;
		}
	}
}

inline int solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) memset(state[i], 0, sizeof state[i]);
	if (n & 1) for (int i = 1; i <= n / 2; i++) GO(i);	
	else for (int i = 1; i < n / 2; i++) GO(i);
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			cout << state[i][j] << sep;
		}
	}

	cout << endl;

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}