#include<bits/stdc++.h>
using std::cin;
using std::cout;
const int N = 100005;
using ll = long long;
int c[2];
int dp[2][2][1000][1000];
inline int dfs(int who, int s, int n, int m) {
	if(!n && !m) {
		return s ^ who ^ 1;
	}
	int & res = dp[who][s][n][m];
	if(~res) return res;
	res = 0;
	if(n) res = res || !dfs(who ^ 1, s ^ !who * 0, n - 1, m);
	if(m) res = res || !dfs(who ^ 1, s ^ !who * 1, n, m - 1);
	return res;
}
int main() {
	memset(dp, -1, sizeof(dp));
	std::ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	int n;
	for(int i = 0;i < t;++i) {
		cin >> n;
		int c[2] = {};
		for(int i = 0, x;i < n;++i) {
			cin >> x, ++ c[x & 1];
		}
		cout << (dfs(0, 0, c[0], c[1]) ? "Alice" : "Bob") << '\n';
	}
}