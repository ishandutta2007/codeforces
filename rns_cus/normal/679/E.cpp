#include <bits/stdc++.h>
using namespace std;
#define M 100010
#define INF (1LL << 60)
#define lft (id << 1)
#define rgt (id << 1 | 1)

typedef long long LL;

int n;

struct segment_tree {
	LL val;
	LL v[M << 2], mx[M << 2], mn[M << 2], addv[M << 2], setv[M << 2];
	void push(int id) {
		mx[id] = max(mx[lft], mx[rgt]);
		mn[id] = min(mn[lft], mn[rgt]);
	}
	void build(int id, int l, int r) {
		if (l == r) {
			if (v[l] > val) {
				mx[id] = -INF, mn[id] = INF; return;
			}
			mx[id] = mn[id] = v[l]; return;
		}
		int mid = (l + r) >> 1;
		build(lft, l, mid);
		build(rgt, mid + 1, r);
		push(id);
	}

	void down(int id) {
		if (setv[id]) {
			if (setv[id] > val) {
				mx[lft] = mx[rgt] = -INF;
				mn[lft] = mn[rgt] = INF;
			}
			else {
				mx[lft] = mn[lft] = mx[rgt] = mn[rgt] = setv[id];
			}
			setv[lft] = setv[rgt] = setv[id];
			addv[lft] = addv[rgt] = 0;
			setv[id] = 0;
		}
		if (addv[id]) {
			if (mx[lft] != -INF) {
				mx[lft] += addv[id], mn[lft] += addv[id];
				if (mn[lft] > val) {
					mx[lft] = -INF, mn[lft] = INF;
				}
			}
			if (mx[rgt] != -INF) {
				mx[rgt] += addv[id], mn[rgt] += addv[id];
				if (mn[rgt] > val) {
					mx[rgt] = -INF, mn[rgt] = INF;
				}
			}
			addv[lft] += addv[id]; addv[rgt] += addv[id];
			addv[id] = 0;
		}
	}

	int updateAdd(int id, int l, int r, int st, int en, int x) {
		if (st <= l && r <= en) {
			if (mx[id] == -INF) return 0;
			if (l == r) {
				mx[id] += x; mn[id] += x;
				if (mx[id] == val) return 1;
				else if (mx[id] > val) {
					mx[id] = -INF; mn[id] = INF;
				}
				return 0;
			}
			if (mx[id] + x <= val) {
				mx[id] += x, mn[id] += x; addv[id] += x;
				return (mx[id] == val);
			}
			if (mn[id] + x > val) {
				mx[id] = -INF, mn[id] = INF; addv[id] += x;
				return 0;
			}
		}
		down(id);
		int mid = (l + r) >> 1;
		int t = 0;
		if (st <= mid) {
			t |= updateAdd(lft, l, mid, st, en, x);
		}
		if (mid < en) {
			t |= updateAdd(rgt, mid + 1, r, st, en, x);
		}
		push(id);
		return t;
	}

	void updateSet(int id, int l, int r, int st, int en, int x) {
		if (st <= l && r <= en) {
			if (x > val) {
				mx[id] = -INF, mn[id] = INF;
			}
			else mx[id] = mn[id] = x;
			setv[id] = x; addv[id] = 0;
			return;
		}
		down(id);
		int mid = (l + r) >> 1;
		if (st <= mid) updateSet(lft, l, mid, st, en, x);
		if (mid < en) updateSet(rgt, mid + 1, r, st, en, x);
		push(id);
	}

	LL calc(int id, int l, int r, int x) {
		if (l == r) return mx[id];
		down(id);
		int mid = (l + r) >> 1;
		if (x <= mid) {
			return calc(lft, l, mid, x);
		}
		else return calc(rgt, mid + 1, r, x);
		push(id);
	}
} tr[10];

int main() {
	//freopen("in.txt", "r", stdin);
	LL tp = 1;

	for (int i = 1; i <= 9; i++) tp *= 42, tr[i].val = tp;

	int type, x, y, z, Q;
	scanf("%d %d", &n, &Q);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		for (int j = 1; j <= 9; j++) tr[j].v[i] = x;
	}
	for (int j = 1; j <= 9; j++) tr[j].build(1, 1, n);
	while (Q--) {
		scanf("%d", &type);
    if (type == 1) {
    	scanf("%d", &x);
    	printf("%I64d\n", tr[9].calc(1, 1, n, x));
    }
    else if (type == 3) {
    	scanf("%d %d %d", &x, &y, &z);
    	int bf = 1;
			while (bf) {
				bf = 0;
				for (int i = 1; i <= 9; i++) {
					bf |= tr[i].updateAdd(1, 1, n, x, y, z);
				}
			}
    }
    else {
    	scanf("%d %d %d", &x, &y, &z);
			for (int i = 1; i <= 9; i++) tr[i].updateSet(1, 1, n, x, y, z);
    }
	}
}