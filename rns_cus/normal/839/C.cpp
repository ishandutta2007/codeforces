#include <bits/stdc++.h>
using namespace std;

#define N 100010

int n;
vector <int> v[N];
double dp[N];

void dfs(int x, int pre) {
	int sz = v[x].size();
	for (auto y : v[x]) {
		if (y == pre) { sz --; continue; }
		dfs(y, x);
		dp[x] += dp[y] + 1;
	}
	if (sz) dp[x] /= sz;
}

int x, y;

int main() {
	///freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i < n; i ++) {
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1, 0);
	printf("%.11lf\n", dp[1]);
}