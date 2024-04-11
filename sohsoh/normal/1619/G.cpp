#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int n, k, T[MAXN], cmpid;
map<int, vector<pll>> C, R;
vector<int> cmp[MAXN], adj[MAXN];
bool vis[MAXN];

void dfs(int v) {
	cmp[cmpid].push_back(v);
	vis[v] = true;

	for (int u : adj[v])
		if (!vis[u])
			dfs(u);
}

inline void solve() {
	// claerrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr
	R.clear();
	C.clear();
	cmpid = 0;
	for (int i = 0; i < n + 5; i++) {
		adj[i].clear();
		cmp[i].clear();
		T[i] = 0;
		vis[i] = false;
	}

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int x, y, t;
		cin >> x >> y >> t;
		T[i] = t;

		R[x].push_back({y, i});
		C[y].push_back({x, i});
	}

	for (auto f : R) {
		vector<pll> vec = f.Y;
		sort(all(vec));
		for (int i = 0; i < int(vec.size()) - 1; i++) {
			if (vec[i].X >= vec[i + 1].X - k) {
				adj[vec[i].Y].push_back(vec[i + 1].Y);
				adj[vec[i + 1].Y].push_back(vec[i].Y);
			}
		}
	}

	for (auto f : C) {
		vector<pll> vec = f.Y;
		sort(all(vec));
		for (int i = 0; i < int(vec.size()) - 1; i++) {
			if (vec[i].X >= vec[i + 1].X - k) {
				adj[vec[i].Y].push_back(vec[i + 1].Y);
				adj[vec[i + 1].Y].push_back(vec[i].Y);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			cmpid++;
			dfs(i);
		}
	}

	int l = 0, r = 1e9 + 7; // change ////////////////
	while (l < r) {
		int mid = (l + r) >> 1, cnt = cmpid;
		for (int i = 1; i <= cmpid; i++) {
			for (int e : cmp[i]) {
				if (T[e] <= mid) {
					cnt--;
					break;
				}
			}
		}

		if (cnt <= mid + 1) r = mid;
		else l = mid + 1;
	}

	cout << l << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();


	return 0;
}