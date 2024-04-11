#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 6e5 + 5;
int n, m, cnt, _x[N], _y[N], _w[N], ins[N];
priority_queue<pair<int, int>> q;

namespace LCT {
	#define lc c[x][0]
	#define rc c[x][1]
	int f[N], c[N][2], s[N], si[N], r[N], mx[N];
	
	void init() { for(int i = 1; i <= n; i++) s[i] = 1; }
	int chk(int x) { return c[f[x]][1] == x; }
	int nroot(int x) { return c[f[x]][chk(x)] == x; }
	void pushup(int x) {
		s[x] = s[lc] + s[rc] + si[x] + (x <= n);
		mx[x] = _w[mx[lc]] > _w[mx[rc]]? mx[lc] : mx[rc];
		if(x > n) mx[x] = _w[x - n] > _w[mx[x]]? (x - n) : mx[x];
	}
	void pushr(int x) { swap(lc, rc), r[x] ^= 1; }
	void pushdown(int x) { if(!r[x]) return; if(lc) pushr(lc); if(rc) pushr(rc); r[x] = 0; }
	void rotate(int x) {
		int y = f[x], z = f[y], k = chk(x), w = c[x][!k];
		if(nroot(y)) c[z][chk(y)] = x; c[x][!k] = y, c[y][k] = w;
		if(w) f[w] = y; f[y] = x, f[x] = z;
		pushup(y), pushup(x);
	}
	void pushall(int x) { if(nroot(x)) pushall(f[x]); pushdown(x); } 
	void splay(int x) {
		pushall(x);
		while(nroot(x)) {
			int y = f[x];
			if(nroot(y)) rotate(chk(x) ^ chk(y)? x : y);
			rotate(x);
		}
	}
	void access(int x) { 
		for(int y = 0; x; x = f[y = x]) 
			splay(x), si[x] += s[rc], si[x] -= s[rc = y], pushup(x); 
	}
	void makeroot(int x) { 
		access(x);
		splay(x);
		pushr(x); 
	}
	void link(int x, int y) { 
		makeroot(x), access(y), splay(y); 
		si[y] += s[x], f[x] = y, pushup(y); 
	}
	void cut(int x, int y) { 
		makeroot(x);
		access(y), splay(y);
		f[x] = c[y][0] = 0, pushup(y); 
	}
	void split(int x, int y) { makeroot(x), access(y), splay(y); }
	int query(int x, int y) { split(x, y); return mx[y]; }
	int findroot(int x) { access(x), splay(x); while(lc) pushdown(lc), x = lc; return x; }
	
	void insert(int id) {
		int x = _x[id], y = _y[id], w = _w[id];
		if(findroot(x) == findroot(y)) {
			int lst = query(x, y);
			if(_w[lst] > w) {
				cut(_x[lst], lst + n), cut(_y[lst], lst + n);
				ins[lst] = 0;
				link(x, id + n), link(y, id + n), ins[id] = 1, q.push(make_pair(w, id));
			}
		}
		else {
			makeroot(x), makeroot(y), cnt -= s[x] & 1, cnt -= s[y] & 1;
			ins[id] = 1, link(x, id + n), link(id + n, y);
			makeroot(id + n), cnt += s[id + n] & 1, q.push(make_pair(w, id));
		}
		
		while(q.size()) {
			int nw = q.top().second, x = _x[nw], y = _y[nw], tmp = cnt;
			if(!ins[nw]){ q.pop(); continue; }
			makeroot(x), cnt -= s[x] & 1;
			cut(x, nw + n), cut(y, nw + n);
			makeroot(x), makeroot(y), cnt += s[x] & 1, cnt += s[y] & 1;
			if(cnt) { cnt = tmp, link(x, nw + n), link(y, nw + n); break; }
			ins[nw] = 0, q.pop();
		}
	}
}

int main() {
	n = get(), m = get();
	cnt = n;
	LCT::init();
	for(int i = 1; i <= m; i++) {
		_x[i] = get(), _y[i] = get(), _w[i] = get();
		LCT::insert(i);
		if(cnt) printf("-1\n");
		else printf("%d\n", q.top().first);
	}
	return 0;
}