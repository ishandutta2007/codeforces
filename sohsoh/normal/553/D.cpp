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

bool bilbilak[MAXN], is_in[MAXN];
int n, m, k, deg[MAXN], t_deg[MAXN];
vector<int> adj[MAXN];

inline ld calc(int v) {
	return ld(t_deg[v]) / ld(deg[v]);
}

inline bool check(ld x, bool print_ans = false) {
	set<pair<ld, int>> st;
	for (int v = 1; v <= n; v++) {
		is_in[v] = false;
		t_deg[v] = 0;
	}

	for (int v = 1; v <= n; v++) {
		for (int e : adj[v])
			if (!bilbilak[e]) t_deg[v]++;
	}
	for (int v = 1; v <= n; v++) 
		if (!bilbilak[v]) st.insert({calc(v), v}), is_in[v] = true;

	while (!st.empty()) {
		int v = st.begin() -> Y;
		if ((st.begin() -> X) < x) {	
			st.erase(st.begin());
			is_in[v] = false;
			for (int u : adj[v]) {
				if (bilbilak[u] || !is_in[u]) continue;
				st.erase(st.find({calc(u), u}));
				t_deg[u]--;
				st.insert({calc(u), u});
			}
		} else break;
	}
	
	if (st.empty()) return false;
	if (print_ans) {
		cout << st.size() << endl;
		for (auto e : st) cout << e.Y << sep;
		cout << endl;
		exit(0);
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int v;
		cin >> v;
		bilbilak[v] = true;
	}
	
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		deg[v]++;
		deg[u]++;
	}

	ld L = 0, R = 1;
	int T = 25; // 
	while (T--) {
		ld mid = (L + R) / ld(2);
		if (check(mid)) L = mid;
		else R = mid;
	}
	
	check(L, true);
	return 0;
}