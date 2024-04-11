#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define N 100100

int n, m;
LL a[N];
int x, y;
LL setv[N << 2], mx[N << 2];

void up(int id) {
	mx[id] = max(mx[id<<1], mx[id<<1|1]);
}

void down(int id) {
	if(setv[id]) {
		mx[id << 1] = setv[id << 1] = setv[id];
		mx[id << 1 | 1] = setv[id << 1 | 1] = setv[id];
		setv[id] = 0;
	}
}

void build(int l, int r, int id) {
	if(l == r) {
		mx[id] = a[l];
		return;
	}
    int md = (l + r) >> 1;
    build(l, md, id << 1);
    build(md + 1, r, id << 1 | 1);
    up(id);
}

void update(int l, int r, int id, int L, int R, LL v) {
	if(L <= l && r <= R) {
		setv[id] = mx[id] = v;
		return;
	}
	down(id);
	int md = (l + r) >> 1;
	if(L <= md) update(l, md, id << 1, L, R, v);
	if(R > md) update(md + 1, r, id << 1 | 1, L, R, v);
	up(id);
}

LL query(int l, int r, int id, int L, int R) {
	if(L <= l && r <= R) {
		return mx[id];
	}
	down(id);
	int md = (l + r) >> 1;
	LL rt = 0;
	if(L <= md) rt = max(rt, query(l, md, id << 1, L, R));
	if(R > md) rt = max(rt, query(md + 1, r, id << 1 | 1, L, R));
	return rt;
}

void run() {
	LL rt = query(1, n, 1, 1, x);
	printf("%I64d\n", rt);
	update(1, n, 1, 1, x, rt + y);
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%I64d", a + i);
	build(1, n, 1);
	scanf("%d", &m);
	for(int i = 1; i <= m; i ++) {
		scanf("%d%d", &x, &y);
		run();
	}
	return 0;
}