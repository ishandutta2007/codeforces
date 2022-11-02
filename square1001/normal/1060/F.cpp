#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<vector<int> > G;
double comb[55][55];
int c[55];
void dfs(int pos, int pre) {
	c[pos] = 1;
	for(int i : G[pos]) {
		if(i == pre) continue;
		dfs(i, pos);
		c[pos] += c[i];
	}
}
vector<double> solve(int pos, int pre) {
	vector<double> dp(c[pos]);
	dp[0] = 1.0;
	for(int i : G[pos]) {
		if(i == pre) continue;
		vector<double> res = solve(i, pos);
		vector<double> ndp(c[pos]);
		for(int j = 0; j < c[pos]; ++j) {
			for(int k = 0; k <= c[i] && k <= j; ++k) {
				ndp[j] += dp[j - k] * res[k] * comb[c[i]][k];
			}
		}
		dp = ndp;
	}
	for(int i = 0; i < c[pos]; ++i) {
		dp[i] /= comb[c[pos] - 1][i];
	}
	vector<double> ans(c[pos] + 1);
	for(int i = 0; i <= c[pos]; ++i) {
		for(int j = 0; j < c[pos]; ++j) {
			ans[i] += dp[min(i, j)] * (i > j ? 0.5 : 1);
		}
		ans[i] /= c[pos];
	}
	return ans;
}
int main() {
	int N;
	cin >> N;
	for(int i = 0; i <= N; ++i) {
		comb[i][0] = 1.0;
		for(int j = 1; j <= i; ++j) {
			comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
		}
	}
	G = vector<vector<int> >(N);
	for(int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b; --a, --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	cout.precision(15);
	for(int i = 0; i < N; ++i) {
		dfs(i, -1);
		double mul = 1.0;
		for(int j : G[i]) {
			vector<double> ans = solve(j, i);
			mul *= ans[c[j]];
		}
		cout << mul << endl;
	}
	return 0;
}