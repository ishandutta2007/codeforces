#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int n, k, a[N];
struct Edge { int v, nxt; } edge[N << 1];
int head[N], tot, sum = 0, fr, to, sze[N], cnt = 0;

void clear(int n) {
	for(int i = 1; i <= n; i++) sze[i] = head[i] = 0;
	tot = sum = cnt = 0;
} 

void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot; }

void dfs(int u, int lst) {
	sze[u] = a[u];
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(v == lst) continue;
		dfs(v, u);
		if(sze[v] == sum) ++cnt;
		else sze[u] ^= sze[v];
	}
}

void solve() {
	n = get(), k = get();
	clear(n);
	for(int i = 1; i <= n; i++) a[i] = get(), sum ^= a[i];
	for(int i = 1, u, v; i < n; i++) u = get(), v = get(), add(u, v), add(v, u);
	if(sum == 0) return cout << "YES" << endl, void();
	dfs(1, 0);
	if(k == 2) cout << "NO" << endl;
	else if(cnt >= 2) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}

/*
1
5 3
1 6 4 1 2
1 2
2 3
1 4
4 5
*/