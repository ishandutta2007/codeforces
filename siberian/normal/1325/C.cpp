#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 1e5 + 10;
int n;
vector<pair<int, int>> g[MAXN];

void read() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back({v, i});
		g[v].push_back({u, i});
	}
}

vector<int> ans;

void run() {
	ans.assign(n - 1, -1);
	set<int> have;
	for (int i = 0; i < n; i++) {
		have.insert(i);
	}
	for (int i = 0; i < n; i++) {
		if (g[i].size() <= 2) continue;
		ans[g[i][0].second] = 0;
		ans[g[i][1].second] = 1;
		ans[g[i][2].second] = 2;
		have.erase(0);
		have.erase(1);
		have.erase(2);
		break;
	}
	for (int i = 0; i < n - 1; i++) {
		if (ans[i] != -1) continue;
		ans[i] = *have.begin();
		have.erase(have.begin());
	}
}

void write() {
	for (auto i : ans)
		cout << i << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}