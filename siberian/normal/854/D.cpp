#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()
#define find find228
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

int n, m, k;

struct edge{
	int from, to, cost;
	edge() {}
	edge(int _from, int _to, int _cost) {
		from = _from, to = _to, cost = _cost;
	}
};

const int MAXD = 1e6 + 10;

vector<edge> have[MAXD];
int cost[MAXD][2];

const int INF = 1e18;

void build() {
	vector<int> used(n, INF);
	int ans = INF;
	int cnt = n;
	bool flag = false;
	for (int i = 0; i < MAXD; i++) {
		for (auto ed : have[i]) {
			if (ed.to != 0) continue;
			if (used[ed.from - 1] == INF) cnt--;
			if (cnt == 0) ans -= used[ed.from - 1];
			chkmin(used[ed.from - 1], ed.cost);
			if (cnt == 0) ans += used[ed.from - 1];
		}
		if (cnt == 0 && !flag) {
			flag = true;
			ans = 0;
			for (auto i : used)
				ans += i;
		}
		cost[i][0] = ans;
	}

	used.assign(n, INF);
	ans = INF;
	cnt = n;
	flag = false;
	for (int i = MAXD - 1; i >= 0; i--) {
		for (auto ed : have[i]) {
			if (ed.from != 0) continue;
			if (used[ed.to - 1] == INF) cnt--;
			if (cnt == 0) ans -= used[ed.to - 1];
			chkmin(used[ed.to - 1], ed.cost);
			if (cnt == 0) ans += used[ed.to - 1];
		}
		if (cnt == 0 && !flag) {
			flag = true;
			ans = 0;
			for (auto i : used)
				ans += i;
		}
		cost[i][1] = ans;
	}
}

void solve() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int d, f, t, c;
		cin >> d >> f >> t >> c;
		have[d].emplace_back(f, t, c);
	}

	build();
	
	int ans = INF;
	for (int i = 0; i + k + 1 < MAXD; i++) {
		chkmin(ans, cost[i][0] + cost[i + k + 1][1]);
	}
	/*for (int i = 0; i < 10; i++) {
		cout << cost[i][0] << " " << cost[i][1] << endl;
	}
	cout << endl;*/
	if (ans == INF) ans = -1;
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}