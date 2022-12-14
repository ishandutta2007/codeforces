#include <bits/stdc++.h>
using namespace std;

#define N 1010

vector <int> v[N];

int n, c[N];

bool vis[N];
int q[N], sz[N];
int m, k;

int bfs(int st) {
	int e = 0;
	q[++e] = st;
	vis[st] = 1;
	for (int f = 1; f <= e; f ++) {
		int now = q[f];
		for (int i = 0; i < v[now].size(); i ++) {
			int h = v[now][i];
			if (vis[h]) continue;
			q[++e] = h;
			vis[h] = 1;
		}
	}
	return e;
}

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= k; i ++) scanf("%d", &c[i]), vis[c[i]] = 1;
	for (int i = 1, x, y; i <= m; i ++) scanf("%d %d", &x, &y), v[x].push_back(y), v[y].push_back(x);
	for (int i = 1; i <= k; i ++) sz[i] = bfs(c[i]);
	int mx = 0, ii = -1, rest = n;
	for (int i = 1; i <= k; i ++) rest -= sz[i];
	for (int i = 1; i <= k; i ++) if (sz[i] > mx) mx = sz[i], ii = i;
	sz[ii] += rest;
	int rlt = 0;
	for (int i = 1; i <= k; i ++) rlt += sz[i] * (sz[i] - 1) / 2;
	rlt -= m;
	printf("%d\n", rlt);

	return 0;
}