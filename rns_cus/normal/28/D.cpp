///	D : Coded by Choe Kwang

#include <bits/stdc++.h>
using namespace std;
#define N 100100

int n, v, c, l, r, x, w, m, prt[N], f[N], p[N];
map <int, int> h[N];

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d %d %d %d", &v, &c, &l, &r);
		if (c + r < N) {
			x = h[l][c+r];
			if (x || !l) {
				f[i] = f[x] + v;
				p[i] = x;
				if (!r && f[i] > f[w]) w = i;
				if (f[i] > f[h[l+c][r]]) h[l+c][r] = i;
			}
		}
	}
	for (m; w; w = p[w]) prt[++m] = w;
	printf("%d\n", m);
	for (int i = m; i; i --) printf("%d ", prt[i]); puts("");
	return 0;
}