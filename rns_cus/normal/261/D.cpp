#include <bits/stdc++.h>

using namespace std;

#define N 100100
#define M 4500

int a[N], n, mx, t, q, tmp[N];
int f[N], fen[N];

void add(int x, int y) {
	while(x <= mx) {
		fen[x] = max(fen[x], y);
		x += x & -x;
	}
}

int calc(int x) {
	int rt = 0;
	while(x) {
		rt = max(rt, fen[x]);
		x -= x & -x;
	}
	return rt;
}

int run() {
	if(t >= mx) return mx;
	memset(fen, 0, sizeof(fen));
	memset(f, 0, sizeof(f));
	for(int j = 0; j < t; j ++) {
		for(int i = 1; i <= n; i ++) {
			int x = a[i];
			int tp = calc(x - 1) + 1;
			add(x, tp);
			if(f[x] < tp) f[x] = tp;
		}
	}
	int rt = 0;
	for(int i = 1; i <= mx; i ++) if(rt < f[i]) rt = f[i];
	return rt;
}

int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d%d%d%d", &q, &n, &mx, &t);
	while(q --) {
		for(int i = 1; i <= n; i ++) {
			scanf("%d", a + i);
			tmp[i - 1] = a[i];
		}
		mx = n;
		sort(tmp, tmp + mx); mx = unique(tmp, tmp + mx) - tmp;
		for(int i = 1; i <= n; i ++) {
			a[i] = lower_bound(tmp, tmp + mx, a[i]) - tmp + 1;
		}
		printf("%d\n", run());
	}
	return 0;
}