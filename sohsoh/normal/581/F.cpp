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

const ll N = 5005 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
 
int dp[N][N][2], sz[N], n;
vector <int> al[N];
 
void dfs(int v, int p = -1) {
	sz[v] = 1;
	for (int i = 0; i < al[v].size(); ++i) {
        int u = al[v][i];
        if (u != p)
		dfs(u, v), sz[v] += sz[u];
    }
	for (int i = 0; i < 2; ++i)
		dp[v][(int) al[v].size() == 1 && i == 0][i] = 0;
	int mx = 1;
	for (int i = 0; i < al[v].size(); ++i) {
        int u = al[v][i];
        if (u != p) {
              mx += sz[u];
		for (int fp = mx; ~fp; --fp) {
			for (int f = 0; f < 2; ++f) {
				if (dp[v][fp][f] < n) {
					int was = dp[v][fp][f];
					dp[v][fp][f] = 1000000000;
					for (int sp = 0; sp <= sz[u]; ++sp) {
						for (int s = 0; s < 2; ++s) {
							dp[v][fp + sp][f] = min(dp[v][fp + sp][f], dp[u][sp][s] + was + (f != s));
						}
					}
				}
			}
		}
	//	mx += sz[u];
	   }
    }
	return;
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin >> n;
	memset(dp, 63, sizeof dp);
	for (int i = 0; i < n - 1; ++i) {
		int u, v; cin >> u >> v; --u, --v;
		al[u].push_back(v);
		al[v].push_back(u);	
	}
	int leaf_cnt = 0;
	for (int i = 0; i < n; ++i)
		if ((int) al[i].size() == 1)
			leaf_cnt++;
	dfs(0);
	cout << min(dp[0][leaf_cnt >> 1][0], dp[0][leaf_cnt >> 1][1]) << '\n';
	return 0;
}