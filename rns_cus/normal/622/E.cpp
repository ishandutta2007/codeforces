#include <bits/stdc++.h>
using namespace std;
#define N 500500

int n, dp[N], vis[N];
vector <int> v[N];
multiset <int> s;
multiset <int> :: iterator it;

void dfs(int x) {
	vis[x] = 1;
	if (v[x].size() == 1) s.insert(dp[x]);
	for (int i = 0; i < v[x].size(); i ++) {
		int y = v[x][i];
		if (vis[y]) continue;
		vis[y] = 1;
		dp[y] = dp[x] + 1;
		dfs(y);
	}
}

int main() {
//	freopen("e.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i < n; i ++) {
		int x, y;
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int ans = 0;
	vis[1] = 1;
	for (int i = 0; i < v[1].size(); i ++) {
		s.clear();
		dfs(v[1][i]);
		int rlt = -1;
		for (it = s.begin(); it != s.end(); it ++) {
			int x = *it;
			rlt = max(rlt + 1, x);
		}
		ans = max(ans, rlt + 1);
	}
	printf("%d\n", ans);
	return 0;
}