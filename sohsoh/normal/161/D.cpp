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
 
const ll MAXN = 5e4 + 10;
const ll MAXK = 5e2 + 5;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll cnt[MAXN][MAXK], n, k, ans = 0, ans_tmp[MAXK];
vector<ll> adj[MAXN];

void dfs(int v, int p) {
	cnt[v][0] = 1;
	ans += cnt[v][k];
	for (ll u : adj[v]) {
		if (u != p) {
			dfs(u, v);
	
			memset(ans_tmp, 0, sizeof ans_tmp);
			for (int i = 0; i <= k; i++) {	
				if (i + 1 < k) ans += cnt[u][i] * cnt[v][k - i - 1];
				ans_tmp[i + 1] += cnt[u][i];
			}

			for (int i = 0; i <= k; i++) cnt[v][i] += ans_tmp[i];
		}
	}

	ans += cnt[v][k];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++) {
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}

	dfs(1, 0);
	cout << ans << endl;
	return 0;
}