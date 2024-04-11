#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(X) X.begin(), X.end()
#define sz(X) ((int)X.size())
#define fst first
#define snd second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef string str;

typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<ll> vl;
typedef vector<pll> vpll;
typedef vector<ld> vld;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vbb;

const int INT_INF = 2e9;

bool is_prime(int n) {
	for (int i = 2; i * i <= n; i++) if (n % i == 0) return false;
	return true;
}

void dfs(vector<vi> &gr, vi &path, vb &vis, int v) {
	if (vis[v]) return;
	path.pb(v);
	vis[v] = true;
	for (auto u : gr[v]) dfs(gr, path, vis, u);
}

int maxflow_dfs(vector<vpii> &gr, vi &path, vb &vis, int s, int t) {
	if (s == t) {
		path.pb(s);
		return INT_INF;
	}
	if (vis[s]) return 0;
	vis[s] = true;
	int flow_size;
	for (auto e : gr[s]) {
		if (e.snd > 0) {
			if (flow_size = maxflow_dfs(gr, path, vis, e.fst, t)) {
				path.pb(s);
				return min(flow_size, e.snd);
			}
		}
	}
	return 0;
}

int maxflow(vector<vpii> &gr, int s, int t) {
	vi path;
	vb vis(sz(gr));
	int flow_size;
	int ans = 0;
	while (flow_size = maxflow_dfs(gr, path, vis, s, t)) {
		ans += flow_size;
		reverse(all(path));
		for (int i = 1; i < sz(path); i++) {
			for (auto &e : gr[path[i - 1]]) if (e.fst == path[i]) e.snd -= flow_size;
			for (auto &e : gr[path[i]]) if (e.fst == path[i - 1]) e.snd += flow_size;
		}
		path.clear();
		vis = vb(sz(gr));
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vi a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	// n is start
	// n + 1 is end
	vector<vpii> gr(n + 2);
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) gr[i].eb(n + 1, 2);
		else gr[n].eb(i, 2);
		for (int j = i + 1; j < n; j++) {
			if (a[i] % 2 != a[j] % 2 && is_prime(a[i] + a[j])) gr[i].eb(j, a[i] % 2), gr[j].eb(i, a[j] % 2);
		}
	}

	int mf = maxflow(gr, n, n + 1);
	if (mf == n) {
		vector<vi> gr_norm(n);
		for (int i = 0; i < n; i++) {
			for (auto e : gr[i]) {
				if (e.fst < n && e.snd != (a[i] % 2)) gr_norm[i].pb(e.fst);
			}
		}

		vector<vi> paths;

		vb vis(n);
		vi path;

		for (int i = 0; i < n; i++) {
			dfs(gr_norm, path, vis, i);
			if (sz(path) > 0) paths.pb(path);
			path.clear();
		}

		cout << sz(paths) << endl;
		for (auto path : paths) {
			cout << sz(path);
			for (auto el : path) cout << ' ' << el + 1;
			cout << endl;
		}
	}
	else {
		cout << "Impossible" << endl;
	}
}