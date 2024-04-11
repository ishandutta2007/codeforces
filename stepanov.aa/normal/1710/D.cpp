#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#include <cstdlib>
#include <ctime>
#include <string>
#include <array>
#include <cassert>
#include <set>
#include <map>
#include <deque>


using namespace std;


#define ll long long
#define flt double
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define nlpt nullptr
#define prcs cout << fixed << setprecision(10)


mt19937 rnd(12123);
ll inf = 1e18;


int n;
vector<string> a;
vector<pair<int, int>> rs;
vector<pair<int, int>> t, sg;
vector<vector<int>> g;
vector<int> usd;


void dfs(int v, int l, int r) {
	usd[v] = true;
	for (auto to : g[v]) {
		if (!usd[to] && l <= to && to <= r) {
			dfs(to, l, r);
		}
	}
}


bool is_cncntd(int l, int r) {
	usd.assign(n, false);
	int cnt = 0;
	for (int i = l; i <= r; i += 1) {
		if (!usd[i]) {
			dfs(i, l, r);
			cnt += 1;
		}
	}
	return cnt <= 1;
}


bool check() {
	g.assign(n, vector<int>());
	if ((int)(rs.size()) != (n - 1)){
		return false;
	}
	for (auto [u, v] : rs) {
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 0; i < n; i += 1) {
		for (int j = 0; i + j < n; j += 1) {
			if (a[i][j] - '0' != (int)(is_cncntd(i, i + j))) {
				return false;
			}
		}
	}
	return true;
}


bool comp(const pair<int, int> &a, const pair<int, int> &b) {
	return (a.second - a.first) < (b.second - b.first);
}


void add_edge(int u, int v) {
	rs.emplace_back(u, v);
}


void solve() {
	rs.clear();
	rs.reserve(n - 1);
	t.clear();
	sg.clear();
	t.reserve(n * (n - 1) / 2);
	sg.reserve(n);
	for (int i = 0; i < n; i += 1) {
		for (int j = 1; i + j < n; j += 1) {
			if (a[i][j] == '1') {
				t.emplace_back(i, i + j);
			}
		}
	}
	sort(all(t), comp);
	for (int i = 0; i < n; i += 1) {
		sg.emplace_back(i, i);
	}
	for (auto [l, r] : t) {
		int tl = prev(lower_bound(all(sg), make_pair(l + 1, -1))) - sg.begin();
		int tr = prev(lower_bound(all(sg), make_pair(r + 1, -1))) - sg.begin();
		if (tl == tr) {
			continue;
		}
		vector<pair<int, int>> f;
		for (int i = tl; i <= tr; i += 1) {
			f.emplace_back(max(l, sg[i].first), min(r, sg[i].second));
		}
		add_edge(f[0].first, f.back().second);
		if (f.size() > 2) {
			for (int i = (int)(f.size()) - 2; i < (int)(f.size()) - 1; i += 1) {
				add_edge(f[0].first, f[i].second);
			}
			for (int i = 1; i < (int)(f.size()) - 2; i += 1) {
				add_edge(f[i].first, f.back().second);
			}
		}
		int ttl = sg[tl].first;
		int ttr = sg[tr].second;
		for (int i = 0; i < (tr - tl + 1); i += 1) {
			sg.erase(sg.begin() + tl);
		}
		sg.insert(sg.begin() + tl, make_pair(ttl, ttr));
	}
}


void gen_test(int mxn) {
	n = rnd() % mxn + 1;
	a.resize(n);

}


int32_t main() {
	if (1) {
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	}
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		a.resize(n);
		for (int i = 0; i < n; i += 1) {
			cin >> a[i];
		}
		solve();
		if (false && !check()) {
			break;
		}
		for (auto [u, v] : rs) {
			cout << u + 1 << " " << v + 1 << "\n";
		}
	}
	return 0;
}