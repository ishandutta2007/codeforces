#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 1e6 + 10;

int n;
vector<pair<char, int> > g[MAXN];
bool term[MAXN];
int a[MAXN];
int k;

void read() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int p;
		char x;
		cin >> p >> x;
		g[p].push_back({x, i});
	}	
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> a[i];
		term[a[i]] = true;
	}
}

int ans[MAXN];

void build() {
	for (int i = 0; i < MAXN; i++) {
		sort(all(g[i]));
		for (int j = 1; j < g[i].size(); j++)
			assert(g[i][j].first != g[i][j - 1].first);
	}
}

int h[MAXN];

int sz[MAXN];
int my_cnt[MAXN];
int now = 0;

void dfs_sz(int v) {
	now += term[v];
	my_cnt[v] = now;
	sz[v] = term[v];
	for (auto [lett, to] : g[v]) {
		dfs_sz(to);
		sz[v] += sz[to];
	}	
}

multiset<int> Cnt, Len;

void dfs(int v, int len) {
	ans[v] = len;
	h[v] = len;

	if (!Cnt.empty()) {
	    if (term[v])
		chkmin(ans[v], *Cnt.begin() + now + 1);
	
		chkmin(ans[v], *Len.begin() + len);
	}
	now += term[v];

	Cnt.insert(ans[v] - my_cnt[v] + term[v]);
	Len.insert(ans[v] - len);

	for (auto [lett, to] : g[v]) {
		dfs(to, len + 1);
	}

	Cnt.erase(Cnt.find(ans[v] - my_cnt[v] + term[v]));
	Len.erase(Len.find(ans[v] - len));
}

void run() {
	build();
	dfs_sz(0);
	now = 0;
	dfs(0, 0);
}

void write() {
	for (int i = 0; i < k; i++) {
		cout << ans[a[i]] << " ";
	}
	cout << endl;
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