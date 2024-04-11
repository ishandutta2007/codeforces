//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
using namespace std;
typedef long long ll;
const int N = 1e5+5, inf = 0x3f3f3f3f;

int n, a[N], tot, rt, L, M, R;
struct Node {
	int id, val, rnd, sz, fa, lc, rc;
	Node(int a=0, int b=0, int c=0) : val(a), rnd(rand()), sz(b), id(c), fa(0), lc(0), rc(0) {}
	~Node() {}
}t[N];
int newNode(int w, int id) {t[++tot] = Node(w, 1, id); return tot;}
void pushup(int u) {t[u].sz = t[t[u].lc].sz + t[t[u].rc].sz + 1;}
void split(int u, int w, int &x, int &y) {
	if(!u) return x = y = 0, void();
	if(t[u].val <= w) {x = u; split(t[u].rc, w, t[u].rc, y);}
	else {y = u; split(t[u].lc, w, x, t[u].lc);}
	pushup(u);
}
int merge(int u, int v) {
	if(!u || !v) return u | v;
	if(t[u].rnd < t[v].rnd) {t[u].rc = merge(t[u].rc, v); pushup(u); return u;}
	t[v].lc = merge(u, t[v].lc); pushup(v); return v;
}
void ins(int w, int id) {
	split(rt, w, L, R);
	rt = merge(merge(L, newNode(w, id)), R);
}
void del(int w) {
	split(rt, w-1, L, R);
	split(R, w, M, R);
	M = merge(t[M].lc, t[M].rc);
	rt = merge(merge(L, M), R);
}
int rk(int w) {
	split(rt, w-1, L, R);
	int res = t[L].sz + 1;
	rt = merge(L, R);
	return res;
}
int kth(int u, int k) {
	loop {
		if(k <= t[t[u].lc].sz) {u = t[u].lc; continue;}
		if(k == t[t[u].lc].sz + 1) return u;
		k -= t[t[u].lc].sz + 1;
		u = t[u].rc;
	}
}
int pre(int w) {
	split(rt, w-1, L, R);
	int res = kth(L, t[L].sz);
	rt = merge(L, R);
	return res;
}
int suc(int w) {
	split(rt, w, L, R);
	int res = kth(R, 1);
	rt = merge(L, R);
	return res;
}
int calc(int w) {
	int qwq = pre(w), qaq = suc(w);
	if(!qwq || !qaq) return qwq | qaq;
	if(t[qwq].id < t[qaq].id) return t[qaq].val;
	return t[qwq].val;
}

int main() {
	ins(inf, 0); ins(-inf, 0);
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		if(i != 1) printf("%d%c", calc(a[i]), " \n"[i==n]);
		ins(a[i], i);
	}
    return 0;
}