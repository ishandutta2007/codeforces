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
 
const ll MAXN = 1e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, k, A[5][MAXN], pos[5][MAXN], dp[MAXN];
vector<ll> adj[MAXN];

ll mem(ll v) {
	if (dp[v] >= 0) return dp[v];
	dp[v] = 1;
	for (ll u : adj[v]) dp[v] = max(dp[v], mem(u) + 1);
	return dp[v];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fill(dp, dp + MAXN, -1);
	cin >> n >> k;
	for (int i = 0; i < k; i++) for (int j = 1; j <= n; j++) cin >> A[i][j], pos[i][A[i][j]] = j;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			bool ok = true;
			for (int kk = 1; kk < 5; kk++) if (pos[kk][A[0][i]] > pos[kk][A[0][j]]) ok = false;
			if (ok) adj[i].push_back(j);
		}
	}

	for (int i = 0; i <= n; i++) mem(i);
	cout << *max_element(dp, dp + MAXN) << endl;

	return 0;
}