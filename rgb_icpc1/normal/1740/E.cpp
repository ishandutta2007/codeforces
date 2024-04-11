#include <bits/stdc++.h>
using namespace std;

template<typename hd, typename tl> void chkmin(hd& a, tl b) { if(b < a) a = b; }
template<typename hd, typename tl> void chkmax(hd& a, tl b) { if(a < b) a = b; }

#define endl '\n'

using LL = long long;
using PII = pair<int, int>;
using VI = vector<int>;
using VPII = vector <PII>;

const int MN = 1000005;
int p[MN], dp[MN], _dp[MN], s[MN], dep[MN];
int n;

vector <int> con[MN];
int ans = 0;

void dfs(int u, int d) {
	int mx = 0; s[u] = 0; dep[u] = d;
	for (auto v : con[u]) {
		dfs(v, d + 1);
		s[u] += dp[v];
		dep[u] = max(dep[u], dep[v]);
	}
	dp[u] = max(s[u], dep[u] - d + 1);
}

void _dfs(int u) {
	for (auto v : con[u]) {
		_dp[v] = _dp[u] + s[u] - dp[v];
		ans = max(ans, dp[v] + _dp[v]);
		_dfs(v);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 2; i <= n; i ++) {
		cin >> p[i];
		con[p[i]].push_back(i);
	}
	dfs(1, 0); 
	ans = dp[1];
	_dfs(1);
	cout << ans;
	return 0;
}