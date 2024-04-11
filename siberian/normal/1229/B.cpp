#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;
int n;
int x[MAXN];
vector<int> g[MAXN];
int ans;

void read() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
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

int add(int a, int b) {
	a += b;
	if (a >= MOD)
		a -= MOD;
	return a;
}

int mul(int a, int b) {
	return a * b % MOD;
}

void make(vector<pair <int, int> > & a) {
	sort(a.begin(), a.end());
	vector<pair <int, int> > b;
	for (auto i : a) {
		if (!b.empty() && b[b.size() - 1].first == i.first) {
			b[b.size() - 1].second += i.second;
		}
		else {
			b.push_back(i);
		}
	}
	a = b;
}

void dfs(int v, int p, vector<pair <int, int> > help) {
	help.push_back({x[v], 1});
	for (auto &i : help) {
		i.first = __gcd(i.first, x[v]);
		ans = add(ans, mul(i.second, i.first));
	}
	make(help);
	for (auto i : g[v]) {
		if (i != p) {
			dfs(i, v, help);
		}
	}
}

void run() {
	dfs(0, 0, {});
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