#include <bits/stdc++.h>
using namespace std;

#define N 300030

int x[N], y[N], type[N];

vector <int> v[N];

int dt[N], dtime;

void dfs(int x) {
	dt[x] = ++ dtime;
	for (auto y : v[x]) {
		if (dt[y]) continue;
		dfs(y);
	}
}

void init() {
	dtime = 0;
	memset(dt, 0, sizeof dt);
	for (int i = 0; i < N; i ++) v[i].clear();
}


int n, m, src;

int main() {
///	freopen("in.txt", "r", stdin);
	scanf("%d %d %d", &n, &m, &src);
	for (int i = 0; i < m; i ++) {
		scanf("%d %d %d", type + i, x + i, y + i);
		v[x[i]].push_back(y[i]);
		if (type[i] == 2) v[y[i]].push_back(x[i]);
	}

	dfs(src);
	printf("%d\n", dtime);
	for (int i = 0; i < m; i ++) {
		if (type[i] == 2) {
			if (dt[x[i]] < dt[y[i]]) putchar('+');
			else putchar('-');
		}
	} puts("");

	init();
	for (int i = 0; i < m; i ++) {
		if (type[i] == 1) v[x[i]].push_back(y[i]);
	}

	dfs(src);
	printf("%d\n", dtime);
	for (int i = 0; i < m; i ++) {
		if (type[i] == 2) {
			if (dt[x[i]] == 0) putchar('+');
			else putchar('-');
		}
	} puts("");
}