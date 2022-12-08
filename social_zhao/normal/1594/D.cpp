#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e6 + 5;
int n, m, fa[N], cnt[N][2], vis[N];

int find(int x) { return x == fa[x]? x : fa[x] = find(fa[x]); }
void merge(int u, int v) { fa[find(u)] = find(v); }

void solve() {
	n = get(), m = get();
	for(int i = 1; i <= 2 * n; i++) fa[i] = i, cnt[i][0] = cnt[i][1] = vis[i] = 0;
	for(int i = 1; i <= m; i++) {
		int u, v;
		char s[10];
		u = get(), v = get(), cin >> s;
		if(s[0] == 'i') merge(u, v + n), merge(u + n, v);
		else merge(u, v), merge(u + n, v + n);
	}
	for(int i = 1; i <= n; i++) if(find(i) == find(i + n)) return cout << -1 << endl, void();
	for(int i = 1; i <= 2 * n; i++) ++cnt[find(i)][i > n];
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(vis[find(i)]) continue;
		ans += max(cnt[find(i)][1], cnt[find(i + n)][1]);
		vis[find(i)] = vis[find(i + n)] = 1;
	}
	cout << ans << endl;
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}