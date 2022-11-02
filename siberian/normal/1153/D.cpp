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

//#define int ll

const int MAXN = 3e5 + 10;

int n;
vector<int> g[MAXN];
int op[MAXN];

int dp[MAXN];

// dp[i] -  - ,   ,      1

void dfs(int v, int val) {
	if (g[v].empty()) {
		dp[v] = 1; return;
	}
	int sum = 0;
	int Min = n + 1;
	for (auto i : g[v]) {
		dfs(i, val);
		if (op[v] == 0) {
			sum += dp[i];
		} else {
			chkmin(Min, dp[i]);
		}
	}
	//cout << v << " " << sum << " " << Min << endl;
	if (op[v] == 0) dp[v] = sum;
	else dp[v] = Min;
}

bool check(int val) {
	dfs(0, val);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += g[i].empty();
	}
	cnt -= val - 1;
	/*cout << "cnt = " << cnt << endl;
	cout << "dp = " << endl;
	for (int i = 0; i < n; i++)
		cout << dp[i] << " ";
	cout << endl;*/
	return dp[0] <= cnt;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> op[i];
	for (int i = 1; i < n; i++) {
		int p;
		cin >> p;
		p--;
		g[p].push_back(i);
	//	cout << i << " " << p << endl;
	}
	//cout << check(2);
	//return;
	int l = 1, r = n + 1;
	while (l < r - 1) {
		int mid = (l + r) / 2;
		if (check(mid))
			l = mid;
		else
			r = mid;
	}
	cout << l << "\n";
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