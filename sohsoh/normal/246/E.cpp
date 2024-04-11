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

const ll MAXN = 1e5 + 10;

int n, q, H[MAXN], ans[MAXN], sz[MAXN];
string S[MAXN];
vector<string> vec;
deque<set<int>> st[MAXN];
vector<pll> Q[MAXN];
vector<int> r, adj[MAXN];

inline void s_merge(int v, int u) {
	bool flag = false;
	if (sz[v] < sz[u]) {
		swap(v, u);
		flag = true;
	}

	for (int i = 0; i < (int) st[u].size(); i++) {
		if (i >= (int) st[v].size()) st[v].push_back({});
		st[v][i].insert(st[u][i].begin(), st[u][i].end());
	}

	if (flag) st[v].swap(st[u]);
}

void dfs(int v) {
	int ind = lower_bound(all(vec), S[v]) - vec.begin();
	st[v].push_back({ind});
	sz[v] = 1;

	for (int u : adj[v]) {
		dfs(u);

		st[u].push_front({});
		s_merge(v, u);
		sz[v] += sz[u];
	}


	for (pll e : Q[v])
		ans[e.X] = (e.Y >= int(st[v].size()) ? 0 : st[v][e.Y].size());
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int p;
		cin >> S[i] >> p;

		vec.push_back(S[i]);
		if (p) adj[p].push_back(i);
		else r.push_back(i);
	}

	sort(all(vec));

	cin >> q;
	for (int i = 1; i <= q; i++) {
		int v, h;
		cin >> v >> h;
		Q[v].push_back({i, h});
	}

	for (int e : r) dfs(e);
	for (int i = 1; i <= q; i++) cout << ans[i] << endl;
	return 0;
}