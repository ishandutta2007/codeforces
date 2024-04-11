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
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<ll> adj[MAXN];
ll C[MAXN], dp[MAXN][2] = {0}, dp2[MAXN][2];

void mkey(ll& a) {
	if (a >= MOD) a -= MOD;
}

void dfs(ll v, ll p) {
	if (adj[v].size() == 1 && p > 0) {
		dp[v][C[v]] = 1;
		return;
	}	

	for (ll u : adj[v]) if (u != p) dfs(u, v);
	if (C[v]) {
		ll ans = 1;
		for (ll u : adj[v]) if (u != p) ans = (dp[u][0] + dp[u][1]) % MOD * ans % MOD;	
		dp[v][1] = ans;
	} else {
		dp2[0][0] = 1;
		dp2[0][1] = 0;
		ll ind = 0;
		for (ll u : adj[v]) {
			if (u != p) {
				ind++;
				dp2[ind][1] = (dp2[ind - 1][1] * (dp[u][1] + dp[u][0]) % MOD + dp[u][1] * dp2[ind - 1][0]) % MOD;
				dp2[ind][0] = dp2[ind - 1][0] * ((dp[u][1] + dp[u][0]) % MOD) % MOD;
			}
		}
	
		dp[v][0] = dp2[ind][0];
		dp[v][1] = dp2[ind][1];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		ll u = i + 2, v;
		cin >> v;
		v++;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}

	for (int i = 1; i <= n; i++) cin >> C[i];
	dfs(1, 0);
//	for (int i = 1; i <= n; i++) cerr << "! " << i - 1 << sep << dp[i][0] << sep << dp[i][1] << endl;
	cout << dp[1][1] << endl;
	return 0;
}