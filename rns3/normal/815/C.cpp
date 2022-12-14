#include <bits/stdc++.h>
using namespace std;
#define N 5005

vector <int> v[N];
const int inf = 1e9 + 1;
int n, m;
int a[N][N], b[N][N], c[N], d[N], x[N], y[N], sz[N], ans;

void dfs1(int k) {
	sz[k] = 1;
	for (int i = 0; i < v[k].size(); i ++) {
		dfs1(v[k][i]);
		sz[k] += sz[v[k][i]];
	}
}

void dfs2(int k) {
	int i, j, xx, yy, l;
	for (i = 0; i < v[k].size();  i ++) dfs2(v[k][i]);
	for (i = 1; i <= sz[k]; i ++) x[i] = y[i] = inf;
	for (i = xx = 0; i < v[k].size(); i ++) {
		yy = v[k][i];
		for (j = xx; j >= 0; j --)
		for (l = sz[yy]; l >= 0; l --) {
			y[j + l] = min(y[j + l], y[j] + b[yy][l]);
			x[j + l] = min(x[j + l], x[j] + min(a[yy][l], b[yy][l]));
		}
		xx += sz[yy];
	}
	for(i = 1; i <= sz[k]; i ++) {
		a[k][i] = x[i - 1] + c[k] - d[k];
		b[k][i] = min(y[i], c[k] + y[i - 1]);
	}
}


int main() {
	int i, j, bb;
	scanf("%d %d", &n, &bb);
	scanf("%d %d", c + 1, d + 1);
	for(i = 2; i <= n; i ++) {
		scanf("%d %d %d", c + i, d + i, &j);
		v[j].push_back(i);
	}
	dfs1(1);
	dfs2(1);
	ans = sz[1];
	while(bb < min(a[1][ans], b[1][ans])) ans --;
	printf("%d", ans);
}