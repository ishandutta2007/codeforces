#include <bits/stdc++.h>
using namespace std;
#define N 101000
vector<int> v[N];
int a[N], b[N], A[N], B[N], col[N];

void DFS(int x) {
	for(int i = 0; i < v[x].size(); i ++) {
		int y = v[x][i];
		if(col[y]) continue;
		col[y] = col[x];
		DFS(y);
	}
}
int main() {
	//freopen("E.in", "r", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i ++) {
		scanf("%d%d", &a[i], &b[i]);
		v[a[i]].push_back(b[i]);
		v[b[i]].push_back(a[i]);
	}
	int cnt = 0;
	for(int i = 1; i <= n; i ++) if(!col[i]) {
		cnt ++;
		col[i] = cnt;
		DFS(i);
	}
	for(int i = 0; i < m; i ++) {
		int x = a[i];
		int y = b[i];
		A[col[x]] ++;
	}
	for(int i = 1; i <= n; i ++) B[col[i]] ++;
	int ans = 0;
	for(int i = 1; i <= cnt; i ++) {
		if(A[i] >= B[i]) continue;
		ans ++;
	}
	printf("%d\n", ans);
	return 0;
}