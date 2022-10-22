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

ll ind = 0, L, A[MAXN], n;
vector<ll> adj[MAXN], ans;

bool is_reachable(ll v, ll p, ll tar) {
	if (v == tar) return true;
	bool ans = false;
	for (ll u : adj[v]) if (u != p) ans |= is_reachable(u, v, tar);
	return ans;
}

void algo(ll v, ll p) {
	ans.push_back(v);
	if (ind < L && v == A[ind]) { ind++; return; }
	if (ans.size() > 2 * n - 1) return;
	while (ind < L && is_reachable(v, p, A[ind])) {
		if (ans.size() > 2 * n - 1) return;
		for (ll u : adj[v]) {
			if (ans.size() > 2 * n - 1) return;
			if (u != p && is_reachable(u, v, A[ind])) {
				algo(u, v);
				ans.push_back(v);
				break;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 2; i <= n; i++) if (adj[i].size() == 1) L++;
	for (int i = 0; i < L; i++) cin >> A[i];
	algo(1, 0);
	if (ans.size() > 2 * n - 1) return cout << -1 << endl, 0;
	for (ll u : ans) cout << u << sep;
	cout << endl;
	return 0;
}