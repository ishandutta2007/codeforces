#include <bits/stdc++.h>
using namespace std;
const int N = 5002;
int n, m, n1, n2, n3, col[N];
vector< pair< vector<int>, vector<int> > > res;
vector<int> v1, v2;
vector<int> g[N];
bool dp[N][N];
int pre[N][N], flag[N];
void dfs(int u) {
	if (col[u] == 1) {
		v1.push_back(u);
	} else {
		v2.push_back(u);
	}
	for (auto v: g[u]) {
		if (col[v] == 0) {
			col[v] = 3 - col[u];
			dfs(v);
		} else { 
			if (col[u] == col[v]) {
				printf("NO\n"); exit(0);
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	scanf("%d%d%d", &n1, &n2, &n3);
	for (int i = 1; i <= m; i ++) {
		int u, v; scanf("%d%d", &u, &v);
		g[u].push_back(v); g[v].push_back(u);
	}
	for (int i = 1; i <= n; i ++) {
		if (col[i] == 0) {
			col[i] = 1; 
			v1.clear(); v2.clear();
			dfs(i);
			/*
			printf("i = %d\n", i);
			for (auto x: v1) printf("%d ", x); printf("\n");
			for (auto x: v2) printf("%d ", x); printf("\n");
			*/
			res.push_back(make_pair(v1, v2));
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i < res.size(); i ++) {
		for (int j = 0; j <= n; j ++) {
			if (dp[i][j]) {
				dp[i+1][j + res[i].first.size()] = 1;
				pre[i+1][j + res[i].first.size()] = -1;
				
				dp[i+1][j + res[i].second.size()] = 1;
				pre[i+1][j + res[i].second.size()] = +1;
			} 
		}
	}
	if (dp[res.size()][n2]) {
		printf("YES\n");
		int x = res.size(), y = n2;
		while (x > 0) {
			//printf("x = %d, y = %d\n", x, y);
			if (pre[x][y] == -1) {
				vector<int> vec = res[x-1].first;
				y -= res[x-1].first.size();
				for (auto val: res[x-1].first) flag[val] = 1;
			} else
			if (pre[x][y] == +1) {
				vector<int> vec = res[x-1].second;
				y -= res[x-1].second.size();
				for (auto val: res[x-1].second) flag[val] = 1;
			}
			x --;
		}
		for (int i = 1; i <= n; i ++) {
			if (flag[i] == 0) {
				if (n1) {
					printf("1"); n1 --;
				} else {
					printf("3");
				}
			} else {
				printf("2");
			}
		}
	} else {
		printf("NO\n");
	}
}