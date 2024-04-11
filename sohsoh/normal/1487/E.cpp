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

const ll MAXN = 2e5 + 10;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll m[5], n[5], C[5][MAXN], dp[5][MAXN];
vector<int> adj[5][MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n[1] >> n[2] >> n[3] >> n[4];
	for (int i = 1; i < 5; i++)
		for (int j = 1; j <= n[i]; j++) 
			cin >> C[i][j];

	for (int i = 2; i < 5; i++) {
		cin >> m[i];
		for (int j = 1; j <= m[i]; j++) {
			int u, v;
			cin >> u >> v;
			adj[i][v].push_back(u);
		}
	}

	for (int i = 1; i < 5; i++) fill(dp[i], dp[i] + MAXN, INF);
	for (int i = 1; i <= n[1]; i++) dp[1][i] = C[1][i];

	ll ans = INF;
	for (int i = 2; i <= 4; i++) {
		multiset<ll> st;
		for (int j = 1; j <= n[i - 1]; j++) st.insert(dp[i - 1][j]);
		for (int v = 1; v <= n[i]; v++) {
			for (int u : adj[i][v]) st.erase(st.find(dp[i - 1][u]));
			ll c = INF;
			if (!st.empty()) c = *st.begin();
			dp[i][v] = C[i][v] + c;
			for (int u : adj[i][v]) st.insert((dp[i - 1][u]));
			if (i == 4) ans = min(ans, dp[i][v]);
		}
	}

	if (ans == INF) ans = -1;
	cout << ans << endl;
	return 0;
}