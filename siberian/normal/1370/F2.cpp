#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

pair<int, int> query(vector<int> a) {
	cout << "? " << a.size();
	for (auto i : a) {
		cout << " " << i + 1;
	}
	cout << endl;
	pair<int, int> ans;
	cin >> ans.first >> ans.second;
	ans.first--;
	return ans;
}

void outAns(int u, int v) {
	cout << "! " << u + 1 << " " << v + 1 << endl;
	string s;
	cin >> s;
	assert(s == "Correct");
}

int n;
vector<vector<int>> g;
vector<int> h;

void dfsH(int v, int p) {
	for (auto i : g[v]) {
		if (i == p) continue;
		h[i] = h[v] + 1;
		dfsH(i, v);
	}
}

int findRoot() {
	int ans = -1;
	int maxH = n;
	for (int i = 0; i < n; i++) {
		h.assign(n, 0);
		dfsH(i, -1);
		if (*max_element(all(h)) < maxH) {
			maxH = *max_element(all(h));
			ans = i;
		}
	}
	return ans;
}

void solve() {
	cin >> n;
	g.assign(n, {});
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int root = findRoot();
	h.assign(n, 0);
	dfsH(root, -1);
	vector<int> q(n);
	iota(all(q), 0);
	auto have = query(q); 
	int dist = have.second;
	int l = h[have.first];
	int r = *max_element(all(h)) + 1;
	int lastL = have.first;
	while (l < r - 1) {
		int mid = (l + r) / 2;
		vector<int> q;
		for (int i = 0; i < n; i++) {
			if (h[i] == mid) {
				q.push_back(i);
			}
		}
		have = query(q);
		if (have.second == dist) {
			l = mid;
			lastL = have.first;
		} else {
			r = mid;
		}
	}
	h.assign(n, 0);
	dfsH(lastL, -1);
	q = {};
	for (int i = 0; i < n; i++) {
		if (h[i] == dist) {
			q.push_back(i);
		}
	}
	outAns(lastL, query(q).first);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}