#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 3e5 + 5;
int n, ans;
int in[N], out[N], lst[N], tim;
vector<int> t1[N], t2[N];

namespace BIT {
	int sum[N];
	int lowbit(int x) { return x & (-x); }
	void add(int x, int v) { while(x <= n) sum[x] += v, x += lowbit(x); }
	int ask(int x) { int r(0); while(x) r += sum[x], x -= lowbit(x); return r; }
	void add(int l, int r, int x) { add(l, x), add(r + 1, -x); }
	void clear(int n) { for(int i = 0; i <= n; i++) sum[i] = 0; }
}

void clear(int n) {
	BIT::clear(n);
	for(int i = 1; i <= n; i++) t1[i].clear(), t2[i].clear(), lst[i] = in[i] = out[i] = 0;
	tim = 0, ans = 0;
}

void dfs(int u, int cnt) {
	lst[u] = BIT::ask(in[u]);
	if(!lst[u]) ++cnt;
	else BIT::add(in[lst[u]], out[lst[u]], -lst[u]);
	BIT::add(in[u], out[u], u);
	ans = max(ans, cnt);
	for(int i = 0; i < t1[u].size(); i++) dfs(t1[u][i], cnt);
	BIT::add(in[u], out[u], -u);
	if(lst[u]) BIT::add(in[lst[u]], out[lst[u]], lst[u]);
}

void df5(int u) {
	in[u] = ++tim;
	for(int i = 0; i < t2[u].size(); ++i) df5(t2[u][i]);
	out[u] = tim;
}

void solve() {
	clear(n);
	n = get();
	for(int i = 2, f; i <= n; i++) f = get(), t1[f].push_back(i);
	for(int i = 2, f; i <= n; i++) f = get(), t2[f].push_back(i);
	df5(1), dfs(1, 0);
	printf("%d\n", ans);
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}

/*
1
4
1 2 3
1 2 3
*/