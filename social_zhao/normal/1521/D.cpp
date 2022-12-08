#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5, inf = 0x3f3f3f3f;
int n;
struct Edge { int v, nxt; } edge[N << 1];
int head[N], tot;
int f[N][2], pre[N][2];
vector<int> son[N], toc[N];
map<int, int> cut[N];
int bcut[N][2], blnk[N][2], tc, tl, vis[N], st[N][2], tim;

void clear(int n) {
	for(int i = 1; i <= tot; i++) edge[i] = (Edge){ 0, 0 };
	for(int i = 1; i <= n; i++) head[i] = 0, vis[i] = 0; tot = 0;
	for(int i = 1; i <= n; i++) f[i][0] = f[i][1] = inf, pre[i][0] = pre[i][1] = 0;
	for(int i = 1; i <= n; i++) son[i].clear(), toc[i].clear(), cut[i].clear();
	for(int i = 1; i <= tc; i++) bcut[i][0] = bcut[i][1] = blnk[i][0] = blnk[i][1] = 0; tc = tl = 0;
	for(int i = 1; i <= tim; i++) st[i][0] = st[i][1] = 0; tim = 0;
}

void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot; }

int GetDeltaF(int u, int i) { if(i == -1) return inf; else return min(f[son[u][i]][0], f[son[u][i]][1]) - f[son[u][i]][0]; }

void dfs(int u, int fa) {
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(v == fa) continue;
		dfs(v, u), son[u].push_back(v);
	}
	if(!son[u].size()) { f[u][0] = 1; return; }
	int fir = 0, sec = -1, sum = min(f[son[u][0]][0], f[son[u][0]][1]);
	for(int i = 1; i < (int)son[u].size(); i++) {
		sum += min(f[son[u][i]][0], f[son[u][i]][1]);
		if(GetDeltaF(u, i) >= GetDeltaF(u, fir)) sec = fir, fir = i;
		else if(GetDeltaF(u, i) >= GetDeltaF(u, sec)) sec = i;
	}
	f[u][0] = sum - GetDeltaF(u, fir);
	if(sec != -1) f[u][1] = sum - GetDeltaF(u, fir) - GetDeltaF(u, sec) - 1;
	pre[u][0] = fir, pre[u][1] = sec;
}

void GetToc(int u, int id) {
	for(int i = 0; i < (int)son[u].size(); i++) {
		int v = son[u][i];
		if(i == pre[u][0] || (id != 0 && i == pre[u][1])) 
			GetToc(v, 0);
		else 
			toc[u].push_back(v), GetToc(v, f[v][1] <= f[v][0]? 1 : 0);
	}
}

void GetST(int u, int fa) {
	int deg = 0; vis[u] = 1;
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(cut[u][v] || cut[v][u] || vis[v]) continue;
		GetST(v, u), ++deg;
	}
	if((u == fa && deg == 1) || (u != fa && deg == 0)) st[tim][1] = st[tim][0], st[tim][0] = u;
	else if(u == fa && deg == 0) st[tim][0] = st[tim][1] = u;
}

void solve() {
	n = get();
	clear(n);
	for(int i = 1, u, v; i < n; i++) u = get(), v = get(), add(u, v), add(v, u);
	dfs(1, 0);
	printf("%d\n", min(f[1][0], f[1][1]) - 1);
	GetToc(1, f[1][1] <= f[1][0]? 1 : 0);
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < (int)toc[i].size(); j++)
			cut[i][toc[i][j]] = 1, ++tc, bcut[tc][0] = i, bcut[tc][1] = toc[i][j];
	for(int i = 1; i <= n; i++) if(!vis[i]) ++tim, GetST(i, i);
	for(int i = 2; i <= tim; i++) ++tl, blnk[tl][0] = st[i - 1][1], blnk[tl][1] = st[i][0];
	for(int i = 1; i <= tc; i++)
		printf("%d %d %d %d\n", bcut[i][0], bcut[i][1], blnk[i][0], blnk[i][1]);
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}