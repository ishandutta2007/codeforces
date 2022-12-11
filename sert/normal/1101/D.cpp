#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)2e5 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

struct G {
	int n;
	vector<vector<int>> es;

	G(int sz = 0) {
		n = sz;
		es.resize(n);
		for (int i = 0; i < n; i++) es[i].clear();
	}

	void addEdge(int v1, int v2) {
		es[v1].push_back(v2);
		es[v2].push_back(v1);
	}

	int bfs(int st, vector<int> &d) {
		queue<int> q;
		q.push(st);
		int lst = -1;
		while (!q.empty()) {
			int v = q.front();
			lst = v;
			q.pop();
			for (int w: es[v]) {
				if (d[w] == -1) {
					d[w] = d[v] + 1;
					q.push(w);
				}
			}
		}
		return lst;
	}

	int getDiam() {
		vector<int> d(n, -1);
		vector<int> lst;
		for (int i = 0; i < n; i++) {
			if (d[i] != -1) continue;
			d[i] = 0;
			lst.push_back(bfs(i, d));
		}
		for (int i = 0; i < n; i++) d[i] = -1;
		int ans = 0;
		for (int x: lst) {
			d[x] = 0;
			int w = bfs(x, d);
			ans = max(ans, d[w]);
		}
		return ans + 1;
	}
};

vector<pair<int, int>> cntB(int x, vector<int> &nums) {
	vector<pair<int, int>> ans;
	for (int i = 2; i * i <= x; i++) {
		if (x % i) continue;
		ans.emplace_back(i, nums[i]++);
		while (x % i == 0) x /= i;
	}
	if (x > 1) {
		ans.emplace_back(x, nums[x]++);		
	}
	sort(ans.begin(), ans.end());
	return ans;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> nums(N, 0);

	vector<vector<pair<int, int>>> b(n);
	for (int i = 0; i < n; i++) {
		b[i] = cntB(a[i], nums);
		if (D && false) {
			for (pair<int, int> x: b[i]) {
				cout << x.first << " " << x.second << " | "; 
			}
			cout << "\n";
		}
	}

	vector<G> g(N);
	for (int i = 0; i < N; i++) {
		if (nums[i] > 0) g[i] = G(nums[i]);
	}

	for (int i = 1; i < n; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--;
		v2--;

		int cur = 0;
		for (int j = 0; j < (int)b[v1].size(); j++) {
			while (cur < (int)b[v2].size() && b[v2][cur].first < b[v1][j].first) cur++;
			if (cur < (int)b[v2].size() && b[v2][cur].first == b[v1][j].first) {
				g[b[v1][j].first].addEdge(b[v1][j].second, b[v2][cur].second);
				//cout << b[v1][j].first << " " << b[v1][j].second << " " << b[v2][cur].second << "\n";
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (g[i].n > 0) ans = max(ans, g[i].getDiam());
	}

	cout << ans << "\n";
}

int main() {
#ifdef LOCAL
	freopen("a.in", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 3;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}