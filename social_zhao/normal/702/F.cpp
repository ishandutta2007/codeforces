#include<bits/stdc++.h>
#define lc ch[x][0]
#define rc ch[x][1]
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e7 + 5;
int n, m; 
struct T {
	int c, q;
	friend bool operator <(T x, T y) { return x.q == y.q? x.c < y.c : x.q > y.q; }
} s[N];

int rt, ch[N][2], val[N], p[N], tag[N], id[N], tot, cnt[N], add[N], ans[N];

void pusha(int x, int v) {
	if(!x) return;
	val[x] += v, tag[x] += v;
}

void pushc(int x, int v) {
	if(!x) return;
	cnt[x] += v, add[x] += v;
}

void pushdown(int x) {
	if(tag[x]) pusha(lc, tag[x]), pusha(rc, tag[x]);
	if(add[x]) pushc(lc, add[x]), pushc(rc, add[x]);
	tag[x] = 0, add[x] = 0;
}

void split(int x, int k, int &u, int &v) {
	if(x) pushdown(x);
	if(!x) return (void)(u = v = 0);
	else if(val[x] <= k) u = x, split(rc, k, rc, v);
	else v = x, split(lc, k, u, lc);
}

int merge(int x, int y) {
	if(!x || !y) return x + y;
	pushdown(x), pushdown(y);
	if(p[x] < p[y]) { ch[x][1] = merge(ch[x][1], y); return x; }
	else { ch[y][0] = merge(x, ch[y][0]); return y; }
}

void insert(int x, int k, int shit = 0) {
	int a;
	split(rt, k, rt, a);
	tot++, val[tot] = k, id[tot] = x, p[tot] = rand(), cnt[tot] = shit;
	rt = merge(rt, tot), rt = merge(rt, a);
}

void qwq(int x, int c) {
	if(!x) return;
	pushdown(x);
	insert(id[x], val[x] - c, cnt[x] + 1);
	qwq(lc, c), qwq(rc, c);
}

void dfs(int x) {
	if(!x) return;
	pushdown(x);
	ans[id[x]] = val[x] >= 0? cnt[x] : -1;
	dfs(lc), dfs(rc);
}

int main() {
	srand(114514);
	n = get(); 
	for(int i = 1; i <= n; ++i) s[i].c = get(), s[i].q = get();
	sort(s + 1, s + 1 + n);
	m = get();
	for(int i = 1; i <= m; ++i) {
		int v = get();
		insert(i, v);
	}
	for(int i = 1; i <= n; ++i) {
		int a, b;
		split(rt, 2 * s[i].c - 1, rt, a), split(rt, s[i].c - 1, rt, b);
		if(a) pusha(a, -s[i].c), pushc(a, 1), rt = merge(rt, a);
		qwq(b, s[i].c);
	}
	dfs(rt);
	for(int i = 1; i <= m; ++i) printf("%d ", ans[i]);
	return 0;
}