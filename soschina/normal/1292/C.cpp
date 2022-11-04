#include <cstdio>
#include <iostream>
using namespace std;
const int N = 3001;

int n, u[N], v[N], head[N], nxt[N << 1], to[N << 1], eid = 1;
void addedge(const int &u, const int &v){
	to[eid] = v;
	nxt[eid] = head[u];
	head[u] = eid++;
}

int size[N], dist[N], in[N], out[N], idx;
void dfs(int i, int fa){
	dist[i] = dist[fa] + 1;
	size[i] = 1;
	in[i] = ++idx;
	for(int e = head[i]; e; e = nxt[e]) if(to[e] != fa){
		dfs(to[e], i);
		size[i] += size[to[e]];
	}
	out[i] = idx;
}

long long f[N][N], ans;
long long dp(int u, int v){
	if(f[u][v]) return f[u][v];
	if(dist[u] > dist[v]) swap(u, v);
	for(int e = head[v]; e; e = nxt[e])
		if(dist[to[e]] > dist[v]) f[u][v] = max(f[u][v], dp(u, to[e]));
	if(in[v] >= in[u] && in[v] <= out[u]){
		int son;
		for(int e = head[u]; e; e = nxt[e]){
			if(dist[to[e]] > dist[u] && in[v] >= in[to[e]] && in[v] <= out[to[e]]) son = to[e];
			else f[u][v] = max(f[u][v], dp(to[e], v));
		}
		f[u][v] += 1ll * size[v] * (n - size[son]);
	}else{
		for(int e = head[u]; e; e = nxt[e])
			if(dist[to[e]] > dist[u]) f[u][v] = max(f[u][v], dp(to[e], v));
		f[u][v] += 1ll * size[v] * size[u];
	}
	return f[v][u] = f[u][v];
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		scanf("%d%d", u + i, v + i);
		addedge(u[i], v[i]), addedge(v[i], u[i]);
	}
	dfs(1, 0);
	for(int i = 1; i < n; i++)
		ans = max(ans, dp(u[i], v[i]));
	printf("%lld", ans);
	return 0;
}