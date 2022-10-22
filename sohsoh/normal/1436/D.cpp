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
const ll INF = 8e16;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<ll> adj[MAXN];
ll n, A[MAXN], R = 0;

ll dfs(ll v, ll p, ll x) {
	if (p && adj[v].size() == 1) return x - A[v];
	ll tot = -A[v];
	for (ll u : adj[v]) {
		if (u != p) {
			ll ad = dfs(u, v, x);
			if (ad < 0) return -INF;
			tot = min(tot + ad, INF);
		}
	}	

	return tot;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 2; i <= n; i++) {
		ll p;
		cin >> p;
		adj[p].push_back(i);
		adj[i].push_back(p);
	}
	
	for (int i = 1; i <= n; i++) cin >> A[i], R += A[i];

	ll L = 0;
	while (L < R) {
		ll mid = (L + R) / 2;
		if (dfs(1, 0, mid) >= 0) R = mid;
		else L = mid + 1;
	}

	cout << L << endl;
	return 0;
}