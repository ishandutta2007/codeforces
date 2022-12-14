#include <bits/stdc++.h>
using namespace std;

#define N 7070
#define M 140140
const int C = 25;
const int D = 60;
const int E = 150;
const int F = 400;
const int G = 1000;

int n, m, e, t[N], le[N], ri[N], x[N], bb[N], u, v, type, g[M], h[M][5];
int vis[1000001], viss;

int func(int a, int b) {
	if (!b) return a;
	if (a == 1) return 1;
	if (b > G) return func(h[a][4], b - G);
	if (b > F) return func(h[a][3], b - F);
	if (b > E) return func(h[a][2], b - E);
	if (b > D) return func(h[a][1], b - D);
	if (b > C) return func(h[a][0], b - C);
    int d = a - g[a], k = (a - (1 << (d - 1))) / d;
    if (k >= b) return a - b * d;
    return func(a - k * d, b - k);
}

int main() {
	for (int i = 1, tag = 0; i + tag < M; i ++) {
		g[i+tag] = i;
		if (i == 1 << tag) tag ++;
		g[i+tag] = i;
	}
	for (int i = 1; i < M; i ++) h[i][0] = func(i, C);
	for (int i = 1; i < M; i ++) h[i][1] = func(i, D);
	for (int i = 1; i < M; i ++) h[i][2] = func(i, E);
	for (int i = 1; i < M; i ++) h[i][3] = func(i, F);
	for (int i = 1; i < M; i ++) h[i][4] = func(i, G);
	scanf("%d %d", &n, &m);
	while (m --) {
		scanf("%d", &type);
		if (type == 1) e ++, scanf("%d %d %d %d", &t[e], &le[e], &ri[e], &x[e]);
        else {
        	viss ++;
			scanf("%d %d", &u, &v);
            int now = 0, rlt = 0, rmh, ris;
			for (int i = 1; i <= e; i ++) {
                if (t[i] < u) continue;
                rmh = func(le[i], t[i] - u);
                ris = func(ri[i], t[i] - u);
                if (rmh <= v && v <= ris) {
                	if (vis[x[i]] < viss) rlt ++;
					vis[x[i]] = viss;
                }
			}
			printf("%d\n", rlt);
        }
	}
	return 0;
}