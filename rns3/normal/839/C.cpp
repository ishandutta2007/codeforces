#include <bits/stdc++.h>
using namespace std;

#define N 101010

int n;

double val[N];

bool vis[N];

vector <int> v[N];

void dfs(int rt, int d) {
	vis[rt] = 1;
	int cnt = 0;
	double tot = 0;
	for (int i = 0; i < v[rt].size(); i ++) if (!vis[v[rt][i]]) {
		cnt ++;
		dfs(v[rt][i], d + 1);
		tot += 1 + val[v[rt][i]];
	}
	if (cnt == 0) val[rt] = 0;
	else val[rt] = tot / cnt;
}


int main() {
	scanf("%d", &n);
	for (int i = 1, x, y; i < n; i ++) {
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	if (n == 1) {
		puts("0");
		return 0;
	}
	dfs(1, 0);
	printf("%.8lf\n", val[1]);
	return 0;
}