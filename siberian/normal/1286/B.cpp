#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 2010;
vector<int> g[MAXN];
int n;
int root;
int c[MAXN];

void read() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p >> c[i];
		if (p == 0) {
			root = i;
			continue;
		}
		p--;
		g[p].push_back(i);
	} 
}

void no() {
	cout << "NO\n";
	exit(0);
}

void check(vector<int> & ans, int v) {
	if (c[v] == ans.size()) 
		ans.push_back(v);
}

vector<int> dfs(int v) {
	vector<int> ans;
	for (auto i : g[v]) {
		auto fans = dfs(i);
		for (auto j : fans) {
			check(ans, v);
			ans.push_back(j);
		}
	}
	check(ans, v);
	return ans;
}

vector<int> ans;

void run() {
	auto fans = dfs(root);
	if (fans.size() != n)
		no();
	ans.resize(n);
	for (int i = 0; i < n; i++)
		ans[fans[i]] = i + 1;
}

void write() {
	cout << "YES\n";
	for (auto i : ans)
		cout << i << " ";
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