#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

const int MAXN = 110;
int n, m;
vector<int> g[MAXN];
bool used[MAXN];
int cnt = 0;
int cnt2 = 0;
void dfs(int v) {
	cnt++;
	cnt2 += g[v].size();
	used[v] = true;
	for (auto i : g[v])
		if (!used[i])
			dfs(i);
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int add = 0;
	int fans = 0;
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			cnt = 0, cnt2 = 0;
			dfs(i);
			if (cnt * 2 == cnt2) {
				if (cnt % 2 == 0) continue;
				add++;
				continue;
			}
			if (cnt % 2 == 0) continue;
			fans ^= 1;
		}
	}
	cout << add + fans;
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