#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 4e5 + 500;
int n, q;
char s[N];
int pos[N];
struct Node { int ch[26], fa, len; } st[N];
int lst = 1, tot = 1;
vector<int> adj[N];
int fa[N][22], dep[N], dfn[N], tim, ed[N];
int book[N], key[N << 1], stk[N], cnt, tp, f[N][2];

void insert(int c) {
	int p = lst, np = lst = ++tot;
	st[np].len = st[p].len + 1;
	while(p && !st[p].ch[c]) st[p].ch[c] = np, p = st[p].fa;
	if(!p) st[np].fa = 1;
	else {
		int q = st[p].ch[c];
		if(st[q].len == st[p].len + 1) st[np].fa = q;
		else {
			int nq = ++tot; 
			st[nq] = st[q]; st[nq].len = st[p].len + 1;
			st[np].fa = st[q].fa = nq;
			while(p && st[p].ch[c] == q) st[p].ch[c] = nq, p = st[p].fa;
		} 
	}
}

#define v adj[u][i]
void dfs(int u, int pre) {
	dfn[u] = ++tim, dep[u] = dep[pre] + 1, fa[u][0] = pre;
	for(int i = 1; i <= 20; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for(int i = 0; i < adj[u].size(); i++) dfs(v, u);
	ed[u] = ++tim;
}
#undef v

int lca(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 20; i >= 0; i--) if(dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	if(x == y) return x;
	for(int i = 20; i >= 0; i--) if(fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

bool cmp(int x, int y) { return (x > 0? dfn[x] : ed[-x]) < (y > 0? dfn[y] : ed[-y]); }

long long solve(int x, int y) {
	for(int i = 1; i <= x; i++) {
		int now = pos[get()]; f[now][0]++;
		if(!book[now]) book[now] = 1, key[++cnt] = now;
	}
	for(int i = 1; i <= y; i++) {
		int now = pos[get()]; f[now][1]++;
		if(!book[now]) book[now] = 1, key[++cnt] = now;
	}
	sort(key + 1, key + 1 + cnt, cmp);
	for(int i = 1, lim = cnt; i < lim; i++) {
		int l = lca(key[i], key[i + 1]);
		if(!book[l]) key[++cnt] = l, book[l] = 1;
	}
	for(int i = 1; i <= cnt; i++) book[key[i]] = 0;
	for(int i = 1, lim = cnt; i <= lim; i++) key[++cnt] = -key[i];
	sort(key + 1, key + 1 + cnt, cmp);
	long long res = 0;
	for(int i = 1; i <= cnt; i++) {
		if(key[i] > 0) {
			int u = key[i];
			stk[++tp] = u, res += st[u].len * f[u][0] * f[u][1];
		}
		else {
			if(tp == 1) {
				f[stk[tp]][0] = f[stk[tp]][1] = 0, tp--;
			}
			else {
				int v = stk[tp--], u = stk[tp];
				res += 1ll * (1ll * f[u][0] * f[v][1] + 1ll * f[v][0] * f[u][1]) * st[u].len;
				f[u][0] += f[v][0], f[u][1] += f[v][1], f[v][0] = f[v][1] = 0;
			}
		}
	} 
	cnt = 0;
	return res;
}

signed main() {
	n = get(), q = get();
	scanf("%s", s + 1);
	for(int i = n; i >= 1; i--) insert(s[i] - 'a');
	int now = 1;
	for(int i = n; i >= 1; i--) now = st[now].ch[s[i] - 'a'], pos[i] = now;
	for(int i = 2; i <= tot; i++) adj[st[i].fa].push_back(i);
	dfs(1, 0);
	while(q--) {
		int x = get(), y = get();
		printf("%lld\n", solve(x, y));
	}
	return 0;
}

/*
7 1
abacaba
1 7
1
1 2 3 4 5 6 7
*/