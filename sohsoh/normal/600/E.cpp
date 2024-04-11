#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

map<int, int> mp[MAXN];
ll ans[MAXN], cnt[MAXN], C[MAXN], n;
vector<int> adj[MAXN];

inline pll merge(map<int, int>& mp_v, map<int, int>& mp_u, ll ans_v, ll ans_u, ll cnt_v, ll cnt_u) {
	bool b = false;
	if (mp_v.size() < mp_u.size()) {
		mp_v.swap(mp_u); //
		swap(ans_v, ans_u);
		swap(cnt_v, cnt_u);
	}

	for (pll e : mp_u) {
		int c = mp_v[e.X];
		if (c + e.Y > cnt_v) {
			cnt_v = c + e.Y;
			ans_v = e.X;
		} else if (c + e.Y == cnt_v) ans_v += e.X;
		
		mp_v[e.X] += e.Y; 
	}

	mp_u.clear();
	if (b) mp_v.swap(mp_u);
	return {ans_v, cnt_v};
}

void dfs(int v, int p) {
	mp[v] = {{C[v], 1}};
	cnt[v] = 1;
	ans[v] = C[v];

	for (int u : adj[v]) {
		if (u == p) continue;
		dfs(u, v);
		pll e = merge(mp[v], mp[u], ans[v], ans[u], cnt[v], cnt[u]);
		ans[v] = e.X;
		cnt[v] = e.Y;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> C[i];

	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	for (int i = 1; i <= n; i++) cout << ans[i] << sep;
	cout << endl;
	return 0;
}