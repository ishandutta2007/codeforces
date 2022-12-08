#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 15005, S = 305;
int n, a[N], rev[N], f[N][S], g[N][S], mn[N], mx[N], ans = 1;

struct BITx {
	int mx[N];
	void clear() { for(int i = 1; i <= n; i++) mx[i] = 0; }
	int lowbit(int x) { return x & (-x); }
	void add(int x, int v) { while(x) mx[x] = max(mx[x], v), x -= lowbit(x); }
	int ask(int x) { int r(0); while(x <= n) r = max(r, mx[x]), x += lowbit(x); return r; }
} Mx;

struct BITn {
	int mn[N];
	void clear() { for(int i = 1; i <= n; i++) mn[i] = n + 1; }
	int lowbit(int x) { return x & (-x); }
	void add(int x, int v) { while(x) mn[x] = min(mn[x], v), x -= lowbit(x); }
	int ask(int x) { int r(n + 1); while(x <= n) r = min(r, mn[x]), x += lowbit(x); return r; }
} Mn;

vector<int> binn[N], binx[N];

void solve() {
	n = get(), ans = 1;
	for(int i = 1; i <= n; i++) a[i] = get(), rev[a[i]] = i;
	
	for(int i = 1; i <= n; i++) f[i][1] = n + 1, g[i][1] = 0;
	f[a[n]][1] = g[a[n]][1] = a[n];
	for(int t = 2; t <= min(300, n); t++) {
		Mx.clear(), Mn.clear();
		for(int i = n; i >= 1; i--) 
			f[i][t] = Mn.ask(rev[i] + 1), Mn.add(rev[i], f[i][t - 1]);
		for(int i = 1; i <= n; i++) 
			g[i][t] = Mx.ask(rev[i] + 1), Mx.add(rev[i], g[i][t - 1]);
		Mx.clear(), Mn.clear();
		for(int i = 1; i <= n; i++) binn[i].clear(), binx[i].clear();
		for(int i = 1; i <= n; i++) {
			if(f[i][t - 1] <= n) binn[f[i][t - 1]].emplace_back(rev[i]);
			if(g[i][t - 1] >= 1) binx[g[i][t - 1]].emplace_back(rev[i]);
		}
		for(int i = n; i >= 1; i--) {
			f[i][t] = min(f[i][t], Mn.ask(rev[i] + t - 1));
			for(auto v : binx[i]) Mn.add(v, a[v]);
		}
		for(int i = 1; i <= n; i++) {
			g[i][t] = max(g[i][t], Mx.ask(rev[i] + t - 1));
			for(auto v : binn[i]) Mx.add(v, a[v]);
		}
		for(int i = 1; i <= n; i++) if(f[i][t] <= n || g[i][t] >= 1) ans = max(ans, t);
	}
	
	for(int i = 1; i <= n; i++) f[i][1] = n + 1, g[i][1] = 0;
	for(int i = 1; i < n; i++) f[a[i]][2] = a[i], g[a[i]][2] = a[i];
	for(int t = 3; t <= min(300, n); t++) {
		Mx.clear(), Mn.clear();
		for(int i = n; i >= 1; i--) 
			f[i][t] = Mn.ask(rev[i] + 1), Mn.add(rev[i], f[i][t - 1]);
		for(int i = 1; i <= n; i++) 
			g[i][t] = Mx.ask(rev[i] + 1), Mx.add(rev[i], g[i][t - 1]);
		Mx.clear(), Mn.clear();
		for(int i = 1; i <= n; i++) binn[i].clear(), binx[i].clear();
		for(int i = 1; i <= n; i++) {
			if(f[i][t - 1] <= n) binn[f[i][t - 1]].emplace_back(rev[i]);
			if(g[i][t - 1] >= 1) binx[g[i][t - 1]].emplace_back(rev[i]);
		}
		for(int i = n; i >= 1; i--) {
			f[i][t] = min(f[i][t], Mn.ask(rev[i] + t - 1));
			for(auto v : binx[i]) Mn.add(v, a[v]);
		}
		for(int i = 1; i <= n; i++) {
			g[i][t] = max(g[i][t], Mx.ask(rev[i] + t - 1));
			for(auto v : binn[i]) Mx.add(v, a[v]);
		}
		for(int i = 1; i <= n; i++) if(f[i][t] <= n || g[i][t] >= 1) ans = max(ans, t - 1);
	}
	
	cout << ans << endl;
}

int main() {
	int T = get();
	while(T--) solve();
}