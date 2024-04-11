#include <bits/stdc++.h>
using namespace std;

#define N 200200

int n, m, leaf, a[N], s[N];
vector <int> v[N], to[N];

void dfs(int x) {
	for (int i = 0; i < to[x].size(); i ++) {
		int y = to[x][i];
		printf("%d %d\n", x, y);
		dfs(y);
	}
}

int main() {
//	freopen("g.in", "r", stdin);
	scanf("%d %d %d", &n, &m, &leaf);
	for (int i = 1; i <= m; i ++) scanf("%d", &a[i]);
	int mx_leaf = 0;
	for (int i = m; i >= 1; i --) {
		s[i] = s[i+1];
		if (a[i] > a[i+1]) s[i] += a[i] - a[i+1];
		mx_leaf += a[i] - 1;
		if (i == m) mx_leaf ++;
	}
	if (leaf < s[1] || leaf > mx_leaf) {
		puts("-1"); return 0;
	}
	int node = 1;
	for (int i = 1; i <= a[1]; i ++) to[1].push_back(++node), v[1].push_back(node);
	for (int i = 1; i <= m; i ++) {
		int cnt = min(a[i] - 1, leaf - s[i+1]);
		leaf -= cnt;
		cnt = a[i] - cnt;
		for (int j = 0; j < a[i+1]; j ++) {
			to[v[i][j%cnt]].push_back(++node), v[i+1].push_back(node);
		}
	}
	printf("%d\n", n);
	dfs(1);
	return 0;
}