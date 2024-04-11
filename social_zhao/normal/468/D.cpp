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
int n, mx[N], sze[N], rt, dis[N], ans, p[N], rev[N];
struct Edge { int v, nxt, w; } edge[N << 1];
int head[N], tot;
int node, col[N], cnt, sum[N];
set<pair<int, int>> st[N], sz, mn; 

void add(int u, int v, int w) { edge[++tot] = (Edge){ v, head[u], w }, head[u] = tot; }

int GetMid(int u, int lst) {
	sze[u] = 1, mx[u] = 0;
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(v == lst) continue;
		GetMid(v, u), sze[u] += sze[v], mx[u] = max(mx[u], sze[v]);
	}
	mx[u] = max(mx[u], n - sze[u]);
	if(mx[u] < mx[rt]) rt = u; 
}

void dfs(int u, int lst){
	ans += dis[u] * 2, sze[u] = 1;
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v, w = edge[i].w;
		if(v == lst) continue;
		dis[v] = dis[u] + w, dfs(v, u), sze[u] += sze[v];
	}
}

void PushCol(int u, int lst, int der) {
	col[u] = der, st[der].insert(make_pair(u, der));
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(v == lst) continue;
		PushCol(v, u, der); 
	}
}

main() {
	n = get(), node = n;
	for(int i = 1, u, v, w; i < n; i++) u = get(), v = get(), w = get(), add(u, v, w), add(v, u, w);
	mx[0] = n, GetMid(1, 0);
	dfs(rt, 0);
	printf("%lld\n", ans);
	++cnt, col[rt] = cnt, sz.insert(make_pair(-2, 1)), sum[1] = 2, st[1].insert(make_pair(rt, 1));
	for(int i = head[rt]; i; i = edge[i].nxt) {
		int v = edge[i].v; 
		PushCol(v, rt, ++cnt), sz.insert(make_pair(-sze[v] - sze[v], cnt)), sum[cnt] = sze[v] * 2;
	}
	for(int i = 1; i <= cnt; i++) mn.insert(*st[i].begin());
	for(int i = 1; i <= n; i++, --node) {
		if(sz.begin() -> first == -node && sz.begin() -> second != col[i] && sz.begin() -> second != 1) {
			int tar = sz.begin() -> second;
			p[i] = st[tar].begin() -> first;
		} 
		else {
			set<pair<int, int>>::iterator it = mn.begin();
			if(it -> second == col[i] && col[i] != 1) ++it;
			p[i] = it -> first;
		}
		mn.erase(make_pair(p[i], col[p[i]]));
		st[col[p[i]]].erase(st[col[p[i]]].begin());
		if(st[col[p[i]]].size()) mn.insert(*st[col[p[i]]].begin());
		sz.erase(make_pair(-sum[col[p[i]]], col[p[i]])), --sum[col[p[i]]];
		sz.insert(make_pair(-sum[col[p[i]]], col[p[i]]));
		
		sz.erase(make_pair(-sum[col[i]], col[i])), --sum[col[i]];
		sz.insert(make_pair(-sum[col[i]], col[i]));
	}
	for(int i = 1; i <= n; i++) printf("%d ", p[i]);
	return 0;
}