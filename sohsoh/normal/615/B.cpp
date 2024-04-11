/*
	:O
*/
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
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 2e5 + 10;
const ll MAXK = 900;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, m, dp[MAXN];
vector<ll> adj[MAXN];

int main() {
	cin >> n >> m;
	dp[1] = 1;
	for (int i = 0; i < m; i++) {
		ll x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	ll ans = adj[1].size();
	for (int i = 2; i <= n; i++) {
		dp[i] = 1;
		for (ll e : adj[i]) if (e < i) dp[i] = max(dp[i], dp[e] + 1);
		ans = max(ans, dp[i] * ll(adj[i].size()));
	} 

	cout << ans << endl;
}