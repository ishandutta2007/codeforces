#include<bits/stdc++.h>
#define lc (u << 1)
#define rc (u << 1 | 1)
#define mid ((l + r) >> 1)
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 150005, inf = 0x3f3f3f3f;
int n, len, h, a[N], b[N], ans;
int mx[N << 2], sze[N << 2];

void pushup(int u) {
	sze[u] = sze[lc] + sze[rc];
	if(mx[rc] == -inf) return mx[u] = mx[lc], void();
	if(mx[lc] == -inf) return mx[u] = mx[rc], void();
	mx[u] = min(mx[lc], mx[rc] - sze[lc]);
}

void build(int u, int l, int r) {
	if(l == r) return mx[u] = -inf, void();
	build(lc, l, mid), build(rc, mid + 1, r);
	pushup(u);
}

void update(int u, int l, int r, int x, int v) {
	if(l == r) {
		sze[u] += v;
		if(!sze[u]) mx[u] = -inf;
		else mx[u] = l - sze[u];
		return;
	}
	if(x <= mid) update(lc, l, mid, x, v);
	else update(rc, mid + 1, r, x, v);
	pushup(u);
}

int main() {
	n = get(), len = get(), h = get();
	for(int i = 1; i <= len; i++) b[i] = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	sort(b + 1, b + 1 + len);
	for(int i = 1; i <= n; i++) 
		a[i] = (len - (lower_bound(b + 1, b + 1 + len, h - a[i]) - b)) + 1;
	build(1, 0, len);
	for(int r = 1, l = 2 - len; r <= n; r++, l++) {
		update(1, 0, len, a[r], 1);
		if(l >= 1) 
			ans += mx[1] >= 0, update(1, 0, len, a[l], -1);
	}
	cout << ans;
	return 0;
}

/*
10 9 30535
23453 29305 25145 13874 20491 740 25635 8759 5365 
32380 25235 25207 29639 3217 7410 22727 9937 7876 7333 
*/