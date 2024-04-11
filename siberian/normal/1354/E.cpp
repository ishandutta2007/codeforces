#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 5e3 + 10;
int n, m;
int n1, n2, n3;
vector<int> g[MAXN];

void read() {
	cin >> n >> m;	
	cin >> n1 >> n2 >> n3;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

void no() {
	cout << "NO\n";
	exit(0);
}

int used[MAXN];
vector<int> have[2][MAXN];

void dfs(int v, int c, int comp) {
	used[v] = c;
	have[c - 1][comp].push_back(v);
	for (auto i : g[v]) {
		if (!used[i]) {
			dfs(i, 3 - c, comp);
		} else {
			if (used[i] == used[v]) {
				no();
			}
		}
	}
}

int comps;

void precalc() {
	comps = 0;
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			comps++;
			dfs(i, 1, comps);
		}
	}
}

bool dp[MAXN][MAXN];
int par[MAXN][MAXN];

void calc_dp() {
	dp[0][0] = 1;
	for (int i = 1; i <= comps; i++) {
		for (int w = 0; w <= n; w++) {
			for (int j = 0; j < 2; j++) {
				int prev = w - have[j][i].size();
				if (prev < 0) continue;
				if (!dp[i - 1][prev]) continue;
				dp[i][w] = true;
				par[i][w] = j;
			}
		}
	}
}

string ans;

void make_ans() {
	if (!dp[comps][n2]) no();
	vector<bool> ans2(n);
	int now = n2;
	for (int i = comps; i >= 1; i--) {
		assert(dp[i][now]);
		for (auto x : have[par[i][now]][i]) {
			ans2[x] = true;
		}
		now -= have[par[i][now]][i].size();
	}
	for (int i = 0; i < n; i++) {
		if (ans2[i]) {
			ans += "2";
		} else {
			if (n1) {
				ans += "1";
				n1--;
			} else {
				ans += "3";
				n3--;
			}
		}
	}
}

void run() {
	precalc();
	calc_dp();
	make_ans();
}

void write() {
	cout << "YES\n";
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