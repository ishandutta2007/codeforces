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

const ll MAXN = 1030;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dp[MAXN][MAXN], n, m, k;
vector<ll> adj[MAXN];
bool M[11][11];

inline void Debug(vector<int> v1, vector<int> v2) {
	int msk1 = 0, msk2 = 0;
	for (int e : v1) msk1 |= (1 << (e - 1));
	for (int e : v2) msk2 |= (1 << (e - 1));
	debug(msk1);
	debug(msk2);
	debug(dp[msk1][msk2])	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
		M[u][v] = M[v][u] = true;
	}

	int MSK = 1 << n;
	for (int msk1 = 1; msk1 < MSK; msk1++) {
		for (int msk2 = 1; msk2 < MSK; msk2++) {
			if (((msk1 ^ msk2) & msk1) != (msk1 ^ msk2)) continue;
			if (__builtin_popcount(msk1) == 1) {
				dp[msk1][msk2] = 1;
			       	continue;
			}
			
			if (__builtin_popcount(msk2) < 2) continue;
			if (__builtin_popcount(msk1) == 2) {
				vector<int> v;
				for (int j = 0; j < n; j++) if (msk2 & (1 << j)) v.push_back(j);
				if (v.size() != 2 || !M[v[0]][v[1]]) continue;
				dp[msk1][msk2] = 1;
				continue;
			}
	
			int v = __builtin_ctz(msk2);	
			
			for (int u : adj[v]) {	
				if (((msk1 & (1 << u)) == 0) || (msk2 & (1 << u))) continue;		
				dp[msk1][msk2] += dp[msk1 ^ (1 << v)][msk2 ^ (1 << v)];
				dp[msk1][msk2] += dp[msk1 ^ (1 << v)][(msk2 ^ (1 << v)) ^ (1 << u)];
			}
		}

	}

	ll ans = 0;
	for (int msk = 1; msk < MSK; msk++)
		if (__builtin_popcount(msk) == k) ans += dp[MSK - 1][msk];
	cout << ans << endl;
	return 0;
}