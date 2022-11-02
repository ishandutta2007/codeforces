#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

const int MAXN = 2e5 + 10;
vector<int> g[MAXN];
int n;
int a[MAXN], b[MAXN], c[MAXN];

void read() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

void no() {
	cout << -1 << endl;
	exit(0);
}

int cnt[MAXN][2];

ll ans = 0;

void dfs(int v, int p, int mn_val) {
	for (auto i : g[v]) {
		if (i == p) continue;
		dfs(i, v, min(mn_val, a[v]));
		cnt[v][0] += cnt[i][0];
		cnt[v][1] += cnt[i][1];
	}
	if (b[v] != c[v]) {
		if (b[v] == 0) {
			cnt[v][0]++;
		} else {
			cnt[v][1]++;
		}
	}
	if (a[v] <= mn_val) {
		int add = min(cnt[v][0], cnt[v][1]);
		ans += (ll) a[v] * add * 2;
		cnt[v][0] -= add;
		cnt[v][1] -= add;
	}
}

void run() {
	dfs(0, 0, 1e9 + 228 + 1337);
	if (cnt[0][0] > 0 || cnt[0][1] > 0) {
		no();
	}
}

void write() {
	cout << ans << endl;
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