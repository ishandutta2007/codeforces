#include<bits/stdc++.h>
const int maxn = 200200;
struct T { int to, nxt, v; } way[maxn << 1];
int h[maxn], num;
inline void link(int x,int y) {
	way[++num] = {y,h[x]}, h[x] = num;
	way[++num] = {x,h[y]}, h[y] = num;
}
int sum[maxn];
int n, m;
int fa[maxn], vis[maxn], dep[maxn];
int in[maxn];
inline void dfs(int x,int f = 0) {
	fa[x] = f, vis[x] = 1,dep[x] = dep[f] + 1;
	for(int i = h[x];i;i=way[i].nxt) if(!vis[way[i].to]){
		way[i].v = 1, dfs(way[i].to, x), sum[x] += sum[way[i].to];
	} else {
		if(way[i].to != f && dep[way[i].to] < dep[x]) ++ sum[x], --sum[way[i].to];
	}
}
int node = 1, p = -1;
inline void dfs0(int x) {
	in[x] = 1;
	for(int i = h[x];i;i=way[i].nxt) if(way[i].to != fa[x]){
		if(dep[way[i].to] < dep[x]) {
			if(dep[way[i].to] > dep[node] && dep[way[i].to] < dep[p]){ 
				node = way[i].to;
			}
		} else if(way[i].v) {
			dfs0(way[i].to);
		}
	}
}
inline void output(std::vector<int> & v) {
	std::cout << v.size();
	for(auto i : v) std::cout << ' ' << i;
	std::cout << '\n', v.clear();
}
inline void update(int u,int f,std::vector<int> & v) {
	for(int i = u;i != f;i = fa[i]) v.push_back(i);
	v.push_back(f);
}
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	for(int i = 1,x,y;i <= m;++i)
		std::cin >> x >> y, link(x, y);
	for(int i = 1;i <= n;++i) if(!vis[i]) dfs(i);
	for(int i = 1;i <= n;++i) if(fa[i] && sum[i] >= 2) 
		if(p == -1 || dep[i] > dep[p]) p = i;
	if(p == -1) return puts("NO"), 0;
	std::cout << "YES" << '\n';
	dfs0(p);
	std::vector<int> v;
	update(p, node, v), output(v);
	for(int i = h[node];i;i = way[i].nxt) if(in[way[i].to] && fa[way[i].to] != node) {
		update(way[i].to, p, v), std::reverse(v.begin(), v.end()), v.push_back(node), output(v);
		break;
	}
	for(int x = node;x;x = fa[x]) {
		static int first = 1;
		for(int i = h[x];i;i=way[i].nxt) if(in[way[i].to] && fa[way[i].to] != x) {
			if(first) { first = 0; continue; }
			update(node, x, v), update(way[i].to, p, v);
			std::reverse(v.begin(), v.end());
			output(v);
			return 0;
		}
		first = 0;
	}
}