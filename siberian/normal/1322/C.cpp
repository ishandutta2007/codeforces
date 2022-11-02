#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

ll gcd(ll a, ll b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

const int MAXN = 5e5 + 10;
vector<int> g[MAXN];
int n, m;
ll c[MAXN];

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		g[i].clear();
		cin >> c[i];
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[v].push_back(u);
	}
	map<vector<int>, ll> fans;
	for (int i = 0; i < n; i++) {
		sort(all(g[i]));
		if (g[i].empty()) continue;
		fans[g[i]] += c[i];
	}
	ll ans = 0;
	for (auto i : fans) {
		ans = gcd(ans, i.second);
	}
	cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    	solve();
    return 0;
}