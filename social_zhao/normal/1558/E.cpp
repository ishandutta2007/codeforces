#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2005;
int n, m, a[N], b[N];
struct Edge { int v, nxt; } edge[N << 1];
int head[N], tot;
int vis[N], inq[N];
queue<int> q;

void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot; }

void clear(int n) {
	for(int i = 1; i <= n; i++) head[i] = 0;
	tot = 0;
}

int dfs(int u, int lst, int &val) {
	if(val <= a[u]) return 0;
	if(vis[u] || inq[u]) return 1;
	inq[u] = 1, val += b[u];
	for(int i = head[u]; i; i = edge[i].nxt) if(edge[i].v != lst && dfs(edge[i].v, u, val)) return 1;
	inq[u] = 0, val -= b[u];
	return 0;
}

int chk(int x) {
	for(int i = 1; i <= n; i++) vis[i] = inq[i] = 0;
	vis[1] = 1, x += b[1];
	for(int i = 1; i <= n; i++) {
		int flag = 0;
		for(int u = 1; u <= n; u++) {
			if(!vis[u]) continue;
			for(int i = head[u]; i; i = edge[i].nxt) {
				int v = edge[i].v;
				if(!vis[v]) {
					if(dfs(v, u, x)) { flag = 1; break; }
				}
			}
			for(int i = 1; i <= n; i++) if(inq[i] && !vis[i]) vis[i] = 1, inq[i] = 0;
			if(flag) break;
		}
		if(!flag) return 0;
		int ans = 0;
		for(int i = 1; i <= n; i++) ans += vis[i];
		if(ans == n) return 1;
	}
	return 0;
}

void solve() {
	clear(n);
	n = get(), m = get();
	for(int i = 2; i <= n; i++) a[i] = get();
	for(int i = 2; i <= n; i++) b[i] = get();
	for(int i = 1, u, v; i <= m; i++) 
		u = get(), v = get(), add(u, v), add(v, u);
	int l = 1, r = 2e9, ans = -1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(chk(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans << endl;
}

signed main() {
	int T = get();
	while(T--) solve();
	return 0;
}

/*
1
6 6
692614746 578500738 24401752 579680567 708577295
76885409 19759255 1353752 57362219 166572898
1 4
5 2
4 5
6 2
1 3
6 3
*/