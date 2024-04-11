#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 6e5 + 5, P = 998244353;
int fac[N], inv[N], _x[N], _y[N];
int n, m;

int qpow(int x, int y) {
	int res = 1;
	while(y) res = 1ll * res * ((y & 1)? x : 1) % P, x = 1ll * x * x % P, y >>= 1;
	return res;
}

void init(int n) {
	fac[0] = 1;
	for(int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % P;
	inv[n] = qpow(fac[n], P - 2);
	for(int i = n; i >= 1; i--) inv[i - 1] = 1ll * inv[i] * i % P;
}

int C(int n, int m) { return (n >= m)? 1ll * fac[n] * inv[m] % P * inv[n - m] % P : 0; }

namespace FHQ {
	#define lc ch[x][0]
	#define rc ch[x][1]
	int p[N], type[N], sze[N], cnt[N], ch[N][2], tot, rt;
	
	void clear() {
		for(int i = 1; i <= tot; i++) p[i] = type[i] = sze[i] = cnt[i] = ch[i][0] = ch[i][1] = 0;
		tot = rt = 0;
	}
	
	void pushup(int x) { sze[x] = sze[lc] + sze[rc] + cnt[x]; }
	
	int merge(int x, int y) {
    	if(!x || !y) return x + y;
    	if(p[x] < p[y]) { ch[x][1] = merge(ch[x][1], y), pushup(x); return x; }
    	else { ch[y][0] = merge(x, ch[y][0]), pushup(y); return y; }
	}

	void split(int x, int k, int &u, int &v) {
	    if(!x) { u = v = 0; return; }
	    if(sze[lc] + cnt[x] <= k) u = x, split(rc, k - (sze[lc] + cnt[x]), rc, v);
	    else v = x, split(lc, k, u, lc);
	    pushup(x);
	}
	
	int GetRight(int x) {
		while(rc) x = rc;
		return cnt[x];
	}
	
	int GetLeft(int x) {
		while(lc) x = lc;
		return cnt[x];
	}
	
	int newnode(int x, int v) {
		++tot;
		sze[tot] = cnt[tot] = v, type[tot] = x, ch[tot][0] = ch[tot][1] = 0, p[tot] = rand();
		return tot;
	}
	
	void insertRight(int v) { //  v  
		if(!rt) return rt = newnode(0, v), void();
		int szer = GetRight(rt), lst = 0;
		split(rt, sze[rt] - szer, rt, lst);
		if(type[lst] == 0) cnt[lst] += v, sze[lst] += v;
		else lst = merge(lst, newnode(0, v));
		rt = merge(rt, lst);
	}
	
	void insertMid(int x) { //  x  <= < 
		int a = 0, b = 0, c = 0; 
		split(rt, x - 1, rt, a);
		int szep = sze[rt], szel = GetLeft(a);
		split(a, szel, a, b);
		int rem = x - 1 - szep;
		c = newnode(1, 1);
		ch[c][0] = newnode(0, rem + 1);
		if(sze[a] - rem - 1) ch[c][1] = newnode(0, sze[a] - rem - 1);
		pushup(c), c = merge(c, b), rt = merge(rt, c);
	}
	
	int dfs(int x) {
		int res = type[x];
		if(lc) res += dfs(lc);
		if(rc) res += dfs(rc);
		return res;
	}
	
	int GetAns() {
		return dfs(rt);
	}
}

void solve() {
	n = get(), m = get();
	FHQ::clear();
	for(int i = 1; i <= m; i++) _x[i] = get(), _y[i] = get();
	for(int i = 1; i <= m; i++) {
		if(_x[i] - _x[i - 1] - 1) FHQ::insertRight(_x[i] - _x[i - 1] - 1);
		FHQ::insertMid(_y[i]);
	}
	int cnt = FHQ::GetAns();
	printf("%d\n", C(2 * n - cnt - 1, n));
}

int main() {
	init(4e5 + 5);
	int T = get();
	while(T--) solve();
	return 0;
}

/*
1
3 2
2 1
3 1
*/