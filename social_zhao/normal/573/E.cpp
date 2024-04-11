#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int n, a[N], ans = 0;

namespace Splay {
	#define lc c[x][0]
	#define rc c[x][1]
	int c[N][2], f[N], sze[N], val[N], A[N], B[N], rt, tot;
	
	int chk(int x) { return x == c[f[x]][1]; }
	int nroot(int x) { return f[x] != 0; }
	void pushup(int x) { sze[x] = sze[lc] + sze[rc] + 1; }
	void pusht(int x, int a, int b) { A[x] += a, B[x] += b, val[x] += a * (sze[lc] + 1) + b; } //  Ax + B 
	void pushdown(int x) { if(A[x] || B[x]) if(lc) pusht(lc, A[x], B[x]); if(rc) pusht(rc, A[x], B[x] + A[x] * (sze[lc] + 1)); A[x] = B[x] = 0; }
	void rotate(int x) {
		int y = f[x], z = f[y], k = chk(x), w = c[x][!k];
		if(nroot(y)) c[z][chk(y)] = x; c[x][!k] = y; c[y][k] = w;
		if(w) f[w] = y; f[y] = x; f[x] = z;
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
		rt = x;
	}
	int find(int x, int k) {
		if(sze[lc] + 1 == k) { splay(x); return val[x]; }
		else if(sze[lc] + 1 > k) return find(lc, k);
		else return find(rc, k - 1 - sze[lc]);
	}
	void dfs(int x) {
		pushdown(x);
		ans = max(ans, val[x]);
		if(lc) dfs(lc);
//		cout << val[x] << " ";
		if(rc) dfs(rc);
	}
}
using namespace Splay;

main() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	rt = tot = sze[1] = 1;
	for(int i = 1; i <= n; i++) {
		int l = 1, r = i - 1, res = i;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(find(rt, mid) + mid * a[i] > find(rt, mid + 1)) res = mid, r = mid - 1;
			else l = mid + 1;
		}
		find(rt, res);
		int tmp = rt;
		++tot;
		f[tot] = rt, f[c[rt][1]] = tot, c[tot][1] = c[rt][1], c[rt][1] = tot, val[tot] = val[rt], sze[tot] = 1;
		pushup(tot), pushup(rt);
		pusht(tot, a[i], (res - 1) * a[i]);
//		dfs(rt); puts("");
	}
	dfs(rt);
	cout << ans;
	return 0;
}