#include <bits/stdc++.h>
using namespace std;

#define N 300010

int n, m, a[N], l, r, addv;
long long del[N];
int lx[N << 2], rx[N << 2], ans[N << 2];

bool con(long long x, long long y) {
    if (!x || !y) return false;
    if (x > 0) return true;
    if (x < 0 && y < 0) return true;
    return false;
}

void push_up(int id, int l, int r) {
	int idL = id << 1, idR = id << 1 ^ 1;
	int mid = l + r >> 1;
	int mx = max(ans[idL], ans[idR]);
	lx[id] = lx[idL];
	rx[id] = rx[idR];
    if (con(del[mid], del[mid + 1])) {
		mx = max(mx, rx[idL] + lx[idR]);
		if (lx[idL] == mid - l + 1) lx[id] += lx[idR];
		if (rx[idR] == r - mid) rx[id] += rx[idL];
    }
    ans[id] = mx;
}

void add(int l, int r, int idx, int d, int id) {
    if (l >= r) {
		del[idx] += d;
		if (!del[idx]) rx[id] = lx[id] = ans[id] = 0;
		else rx[id] = lx[id] = ans[id] = 1;
		return;
    }
    int mid = l + r >> 1;
    if (mid >= idx) add(l, mid, idx, d, id << 1);
    else add(mid + 1, r, idx, d, id << 1 ^ 1);
    push_up(id, l, r);
    return;
}

int main() {
    int ksh = 100000000;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i < n; i ++) add(1, n - 1, i, a[i] - a[i - 1], 1);
	scanf("%d", &m);
	while (m --) {
		scanf("%d%d%d", &l, &r, &addv);
        if (l > 1) add(1, n - 1, l - 1, addv, 1);
        if (r < n) add(1, n - 1, r, -addv, 1);
        printf("%d\n", ans[1] + 1);
	}
}