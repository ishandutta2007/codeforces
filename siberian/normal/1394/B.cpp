#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

const int N = 2e5 + 10;
int n, m, k;
vector<pair<int, int>> g[N];

void read() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;
		u--;
		v--;
		g[u].push_back({cost, v});
	}
}

const int K = 10;

bool good[K][K];
bool ok[K][K][K][K];

bool used[N];

bool check(int pos, int val) {
	fill(used, used + n, false);
	for (int i = 0; i < n; i++) {
		if (g[i].size() != pos) continue;
		int v = g[i][val - 1].second;
		if (used[v]) return false;
		used[v] = true;
	}
	return true;
}

bool check(int pos1, int val1, int pos2, int val2) {
	fill(used, used + n, false);
	for (int i = 0; i < n; i++) {
		int v = -1;
		if (g[i].size() == pos1) {
			v = g[i][val1 - 1].second;
		} else if (g[i].size() == pos2) {
			v = g[i][val2 - 1].second;
		}
		if (v == -1) continue;
		if (used[v]) return false;
		used[v] = true;
	}
	return true;
}

void build() {
	for (int i = 0; i < n; i++) {
		sort(all(g[i]));
	}
	for (int pos1 = 1; pos1 <= k; pos1++) {
		for (int val1 = 1; val1 <= pos1; val1++) {
			good[pos1][val1] = check(pos1, val1);
		}
	}
	for (int pos1 = 1; pos1 <= k; pos1++) {
		for (int val1 = 1; val1 <= pos1; val1++) {
			for (int pos2 = pos1 + 1; pos2 <= k; pos2++) {
				for (int val2 = 1; val2 <= pos2; val2++) {
					ok[pos1][val1][pos2][val2] = ok[pos2][val2][pos1][val1] = check(pos1, val1, pos2, val2);
				}
			}
		}
	}
}

int ans;
int now[K];

bool check(int pos2) {
	if (!good[pos2][now[pos2]]) return false;
	for (int pos1 = 1; pos1 < pos2; pos1++) {
		if (!ok[pos1][now[pos1]][pos2][now[pos2]]) return false;
	}
	return true;
}

void solve(int pos) {
	if (pos == k + 1) {
		ans++;
		return;
	}
	for (int i = 1; i <= pos; i++) {
		now[pos] = i;
		if (!check(pos)) continue;
		solve(pos + 1);
	}
}

void solve() {
	solve(1);
}

void run() {
	build();
	solve();
}

void write() {
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
	read();
	run();
	write();
	return 0;
}