#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 4e5 + 5, P = 1e9 + 7;
int n, lim, ans = 1;
struct Edge { int v, nxt, w, c; } edge[N << 1];
int head[N], tot;
int mid = 0, sze[N], node, vis[N], mx[N];

struct SegmentTree {
	#define lc (u << 1)
	#define rc (u << 1 | 1)
	#define mid ((l + r) >> 1)
	int pro[N << 2], sum[N << 2];
	
	void pushup(int u) { pro[u] = pro[lc] * pro[rc] % P; }
	
	void build(int u, int l, int r) {
		pro[u] = 1, sum[u] = 0;
		if(l == r) return;
		build(lc, l, mid), build(rc, mid + 1, r);
	}
	
	void insert(int u, int l, int r, int x, int v) {
		sum[u] += v;
		if(l == r) return;
		if(x <= mid) insert(lc, l, mid, x, v);
		else insert(rc, mid + 1, r, x, v);
	}
	
	void update(int u, int l, int r, int x, int v) {
		if(l == r) return pro[u] = pro[u] * v % P, void();
		if(x <= mid) update(lc, l, mid, x, v);
		else update(rc, mid + 1, r, x, v);
		pushup(u);
	}
	
	int query(int u, int l, int r, int a, int b) {
		if(a > b) return 1;
		if(a == l && r == b) return pro[u];
		if(b <= mid) return query(lc, l, mid, a, b);
		else if(a > mid) return query(rc, mid + 1, r, a, b);
		else return query(lc, l, mid, a, mid) * query(rc, mid + 1, r, mid + 1, b) % P; 
	}
	
	int check(int u, int l, int r, int a, int b) {
		if(a > b) return 1;
		if(a == l && r == b) return sum[u];
		if(b <= mid) return check(lc, l, mid, a, b);
		else if(a > mid) return check(rc, mid + 1, r, a, b);
		else return check(lc, l, mid, a, mid) + check(rc, mid + 1, r, mid + 1, b);
	}
	#undef mid
} T1, T2;

int qpow(int x, int y) {
	int res = 1;
	while(y) res = res * ((y & 1)? x : 1) % P, x = x * x % P, y >>= 1;
	return res;
}

int inv(int x) { return qpow(x % P, P - 2); }

void add(int u, int v, int w, int c) { edge[++tot] = (Edge){ v, head[u], w, c }, head[u] = tot; } 

void GetMid(int u, int lst) {
	sze[u] = 1, mx[u] = 0;
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(v == lst || vis[v]) continue;
		GetMid(v, u), sze[u] += sze[v], mx[u] = max(mx[u], sze[v]);
	}
	mx[u] = max(mx[u], node - sze[u]);
	if(mx[u] < mx[mid]) mid = u;
}

void PushAns(int u, int lst, int noww, int now1, int now2) {
	ans = ans * qpow(noww, T1.sum[1]) % P * T1.pro[1] % P;
	ans = ans * inv(qpow(noww, T1.check(1, -lim, lim, 1 - now1, lim)) * T1.query(1, -lim, lim, 1 - now1, lim)) % P;
	ans = ans * inv(qpow(noww, T2.check(1, -lim, lim, 1 - now2, lim)) * T2.query(1, -lim, lim, 1 - now2, lim)) % P;
	if(now1 <= 0 && now2 <= 0) ans = ans * noww % P;
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v, w = edge[i].w, c = edge[i].c;
		if(v == lst || vis[v]) continue;
		PushAns(v, u, noww * w % P, now1 + (c == 0? 1 : -2), now2 + (c == 1? 1 : -2));
	}
}

void PushCon(int u, int lst, int noww, int now1, int now2) {
	T1.update(1, -lim, lim, now1, noww), T1.insert(1, -lim, lim, now1, 1);
	T2.update(1, -lim, lim, now2, noww), T2.insert(1, -lim, lim, now2, 1);
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v, w = edge[i].w, c = edge[i].c;
		if(v == lst || vis[v]) continue;
		PushCon(v, u, noww * w % P, now1 + (c == 0? 1 : -2), now2 + (c == 1? 1 : -2));
	}
}

void Clear(int u, int lst, int noww, int now1, int now2) {
	T1.update(1, -lim, lim, now1, inv(noww)), T1.insert(1, -lim, lim, now1, -1);
	T2.update(1, -lim, lim, now2, inv(noww)), T2.insert(1, -lim, lim, now2, -1);
	sze[u] = 1;
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v, w = edge[i].w, c = edge[i].c;
		if(v == lst || vis[v]) continue;
		Clear(v, u, noww * w % P, now1 + (c == 0? 1 : -2), now2 + (c == 1? 1 : -2)), sze[u] += sze[v];
	}
}

void solve(int u) {
	vis[u] = 1;
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v, w = edge[i].w, c = edge[i].c;
		if(vis[v]) continue;
		PushAns(v, u, w, c == 0? 1 : -2, c == 1? 1 : -2);
		PushCon(v, u, w, c == 0? 1 : -2, c == 1? 1 : -2); 
	}
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v, w = edge[i].w, c = edge[i].c;
		if(vis[v]) continue;
		Clear(v, u, w, c == 0? 1 : -2, c == 1? 1 : -2);
	} 
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(vis[v]) continue;
		mid = 0, node = sze[v], GetMid(v, u), solve(mid);
	}
}

main() {
	n = get(), lim = n * 2;
	for(int i = 1, u, v, w, c; i < n; i++) 
		u = get(), v = get(), w = get(), c = get(), add(u, v, w, c), add(v, u, w, c);
	T1.build(1, -lim, lim), T2.build(1, -lim, lim);
	mx[0] = n, node = n, GetMid(1, 0), solve(mid);
	printf("%lld\n", ans);
	return 0;
}