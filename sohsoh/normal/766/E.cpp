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
 
const ll MAXN = 1e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll LOG = 22;

ll cnt[MAXN][LOG][2], n, ans, A[MAXN];
vector<ll> adj[MAXN];

void dfs(int v, int p) {
	for (int i = 0; i < LOG; i++) {
		if (A[v] & (1 << i)) cnt[v][i][1]++, ans += (1 << i);	
		else cnt[v][i][0]++;
	}

	for (int u : adj[v]) {
		if (u != p) {
			dfs(u, v);
			for (int i = 0; i < LOG; i++) {
				ans += (cnt[v][i][1] * cnt[u][i][0] + cnt[v][i][0] * cnt[u][i][1]) * (1ll << i);	
			}
			
			for (int i = 0; i < LOG; i++) {
				if (A[v] & (1 << i)) cnt[v][i][0] += cnt[u][i][1], cnt[v][i][1] += cnt[u][i][0];
				else cnt[v][i][0] += cnt[u][i][0], cnt[v][i][1] += cnt[u][i][1];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i < n; i++) {
		ll v, u;
		cin >> u >> v;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}

	dfs(1, 0);
	cout << ans << endl;
	return 0;
}