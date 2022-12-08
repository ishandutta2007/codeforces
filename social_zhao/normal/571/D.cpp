#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 5e5 + 5, S = N * 20;
int n, q, f1[N], f2[N], s1[N], s2[N], mt[N], t1[N], t2[N];
long long sum[S];
int lc[S], rc[S], tot, T[N];

int find1(int x) { return x == f1[x]? x : find1(f1[x]); }
int find2(int x) { return x == f2[x]? x : find2(f2[x]); } 

void merge1(int x, int y, int t) {
	x = find1(x), y = find1(y);
	assert(x != y);
	if(s1[x] < s1[y]) swap(x, y);
	s1[x] += s1[y], f1[y] = x, t1[y] = t;
}

void merge2(int x, int y, int t) {
	x = find2(x), y = find2(y);
	assert(x != y);
	if(s2[x] < s2[y]) swap(x, y);
	s2[x] += s2[y], f2[y] = x, t2[y] = t;
}

void update(int &u, int l, int r, int x, int v) {
	if(!u) u = ++tot;
	sum[u] += v;
	if(l == r) return;
	int mid = (l + r) >> 1;
	if(x <= mid) update(lc[u], l, mid, x, v);
	else update(rc[u], mid + 1, r, x, v);
}

long long query(int u, int l, int r, int a, int b) {
	if(!u) return 0;
	if(a == l && r == b) return sum[u];
	int mid = (l + r) >> 1;
	if(b <= mid) return query(lc[u], l, mid, a, b);
	else if(a > mid) return query(rc[u], mid + 1, r, a, b);
	else return query(lc[u], l, mid, a, mid) + query(rc[u], mid + 1, r, mid + 1, b);
}

void add(int x, int t) {
	x = find1(x);
	update(T[x], 1, q, t, s1[x]);
}

void reset(int x, int t) {
	x = find2(x);
	mt[x] = t;
}

long long query(int x) {
	int now = x, mxt = mt[x];
	long long res = 0;
	while(now != f2[now]) {
		if(t2[now] < mt[f2[now]]) mxt = max(mxt, mt[f2[now]]);
		now = f2[now];
	}
	++mxt;
	now = x, res = query(T[now], 1, q, mxt, q);
	while(now != f1[now]) {
		res += query(T[f1[now]], 1, q, max(mxt, t1[now]), q);
		now = f1[now];
	}
	return res;
}

int main() {
	n = get(), q = get();
	for(int i = 1; i <= n; i++) f1[i] = f2[i] = i, s1[i] = s2[i] = 1;
	for(int t = 1; t <= q; t++) {
		char c; int x, y;
		scanf("%s", &c);
		if(c == 'U') x = get(), y = get(), merge1(x, y, t);
		else if(c == 'M') x = get(), y = get(), merge2(x, y, t);
		else if(c == 'A') x = get(), add(x, t);
		else if(c == 'Z') x = get(), reset(x, t);
		else if(c == 'Q') x = get(), printf("%lld\n", query(x));
	}
	return 0;
}