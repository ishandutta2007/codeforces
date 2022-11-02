#include <bits/stdc++.h>
using namespace std;

#define N 505050

int a[N], n;
int val[N<<3];

void push_up(int id) {
	val[id] = __gcd(val[id<<1], val[(id<<1)^1]);
}

void build(int le, int ri, int id) {
	if (le == ri) {
		val[id] = a[le];
		return;
	}
	int mid = (le + ri) >> 1;
	build(le, mid, id << 1);
	build(mid + 1, ri, (id << 1) ^ 1);
	push_up(id);
}

void update(int le, int ri, int id, int x, int y) {
	if (le > x || ri < x) return;
	if (le == ri) {
		assert(le == x);
		val[id] = y;
		return;
	}
	int mid = (le + ri) >> 1;
	update(le, mid, id << 1, x, y);
	update(mid + 1, ri, (id << 1) ^ 1, x, y);
	push_up(id);
}

int query(int le, int ri, int id, int st, int en, int x) {
	if (le > en || ri < st) return 0;
	if (val[id] % x == 0) return 0;
	if (le == ri) {
		if (val[id] % x != 0) return 1;
		return 0;
	}
	int mid = (le + ri) >> 1;
	int rlt = query(le, mid, id << 1, st, en, x);
	if (rlt > 1) return rlt;
	rlt += query(mid + 1, ri, (id << 1) ^ 1, st, en, x);
	return rlt;
}

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	build(1, n, 1);
	int q;
	scanf("%d", &q);
	while (q --) {
		int type, le, ri, x, y;
		scanf("%d", &type);
		if (type == 1) {
			scanf("%d %d %d", &le, &ri, &x);
			int ans = query(1, n, 1, le, ri, x);
			if (ans <= 1) puts("YES");
			else puts("NO");
		}
		else {
			scanf("%d %d", &x, &y);
			update(1, n, 1, x, y);
		}
	}


	return 0;
}