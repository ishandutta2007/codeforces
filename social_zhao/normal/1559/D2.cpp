#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 3e5 + 5, S = N * 25;
int n, m1, m2;
int f1[N], f2[N];

struct SGT {
	#define mid (l + r >> 1)
	int T[S], lc[S], rc[S], tot, sze[S];
	
	void update(int &u, int l, int r, int x) {
		if(!u) u = ++tot;
		++sze[u];
		if(l == r) return;
		if(x <= mid) update(lc[u], l, mid, x);
		else update(rc[u], mid + 1, r, x);
	}
	
	int merge(int u, int v, int l, int r) {
		if(!u || !v) return u + v;
		sze[u] += sze[v];
		lc[u] = merge(lc[u], lc[v], l, mid), rc[u] = merge(rc[u], rc[v], mid + 1, r);
		return u;
	}
} T1, T2;

int find1(int x) { return x == f1[x]? x : f1[x] = find1(f1[x]); }
int find2(int x) { return x == f2[x]? x : f2[x] = find2(f2[x]); }

void merge1(int x, int y) {
	x = find1(x), y = find1(y);
	f1[y] = x, T1.T[x] = T1.merge(T1.T[x], T1.T[y], 1, n);
}

void merge2(int x, int y) {
	x = find2(x), y = find2(y);
	f2[y] = x, T2.T[x] = T2.merge(T2.T[x], T2.T[y], 1, n);
}

int GetMex(int x, int y, int l, int r) {
	if(!x && !y) return l;
	if(l == r) return 0;
	int lenl = (mid - l + 1);
	if(T1.sze[T1.lc[x]] != lenl && T2.sze[T2.lc[y]] != lenl) return GetMex(T1.lc[x], T2.lc[y], l, mid);
	else return GetMex(T1.rc[x], T2.rc[y], mid + 1, r);
}

int main() {
	n = get(), m1 = get(), m2 = get();
	for(int i = 1; i <= n; i++) f1[i] = i, f2[i] = i, T1.update(T1.T[i], 1, n, i), T2.update(T2.T[i], 1, n, i);
	for(int i = 1, u, v; i <= m1; i++) u = get(), v = get(), merge1(u, v);
	for(int i = 1, u, v; i <= m2; i++) u = get(), v = get(), merge2(u, v);
	printf("%d\n", n - 1 - max(m1, m2));
	for(int i = 1; i <= n; i++) {
		while(1) {
			int res = GetMex(T1.T[find1(i)], T1.T[find2(i)], 1, n);
			if(!res) break;
			merge1(i, res), merge2(i, res);
			printf("%d %d\n", i, res);
		}
	}
	return 0;
}