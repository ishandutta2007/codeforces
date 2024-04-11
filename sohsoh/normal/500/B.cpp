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

ll n, P[MAXN];
vector<ll> adj[MAXN], ind, vec;
bool vis[MAXN];

void dfs(ll v) {
	if (vis[v]) return;
	vis[v] = true;
	ind.push_back(v);
	vec.push_back(P[v]);
	for (ll u : adj[v]) dfs(u);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> P[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char c;
			cin >> c;
			if (c == '1') adj[i].push_back(j);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vec.clear();
			ind.clear();
			dfs(i);
			sort(all(vec));
			sort(all(ind));
			for (int i = 0; i < ind.size(); i++) P[ind[i]] = vec[i];
		}
	}

	for (int i = 1; i <= n; i++) cout << P[i] << sep;
	cout << endl;
	return 0;
}