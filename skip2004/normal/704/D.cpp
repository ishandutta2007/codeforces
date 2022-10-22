#include<bits/stdc++.h>
const int maxn = 300100;
struct T { int to, nxt, v; } way[maxn << 4];
int h[maxn], head[maxn], num = 1;
inline void adde(int x,int y,int v) {
	if(v < 0) std::cerr << "edge val less than 0" << '\n', std::cout << -1 << '\n', exit(0);
    way[++num] = {y, h[x], v}, h[x] = num;
    way[++num] = {x, h[y], 0}, h[y] = num;
}
int dis[maxn];
inline bool bfs(int s,int t) {
    std::queue<int> q;
    for(int i = 0;i <= t;++i) dis[i] = - 1, head[i] = h[i];
    for(q.push(s), dis[s] = 0;!q.empty();) {
        int t = q.front(); q.pop();
        for(int i = h[t];i;i = way[i].nxt) if(way[i].v && dis[way[i].to] < 0) 
            dis[way[i].to] = dis[t] + 1, q.push(way[i].to);
    }
    return dis[t] >= 0;
}
inline int dfs(int s,int t,int lim) {
    if(s == t || !lim) return lim;
    int ans = 0, mn;
    for(int & i = head[s];i;i = way[i].nxt)
        if(dis[way[i].to] == dis[s] + 1 && (mn = dfs(way[i].to, t, std::min(lim, way[i].v)))) {
            way[i].v -= mn;
            way[i ^ 1].v += mn;
            ans += mn; lim -= mn;
            if(!lim) break;
        }
    return ans;
}
inline int dinic(int s,int t) {
    int ans = 0;
    for(;bfs(s,t);) ans += dfs(s,t,1e9);
    return ans;
}
int n, m;
int r, b, rev;
int x[maxn], y[maxn];
int tp[maxn], l[maxn], d[maxn];
std::map<int, int> map0, map1;
int tot0, tot1;
int min[maxn];
int deg[maxn];
int c0[maxn], c1[maxn];
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m >> r >> b;
	if(r < b) std::swap(r, b), rev ^= 1;
	for(int i = 1;i <= n;++i) { 
		std::cin >> x[i] >> y[i];
		if(!map0.count(x[i])) map0[x[i]] = ++tot0;
		if(!map1.count(y[i])) map1[y[i]] = ++tot1;
		x[i] = map0[x[i]], y[i] = map1[y[i]];
		++c0[x[i]], ++c1[y[i]];
		adde(x[i], i + n, 1), adde(i + n, y[i] + n + n, 1);
	}
	for(int i = 1;i <= m;++i) std::cin >> tp[i] >> l[i] >> d[i], l[i] = (tp[i] == 1 ? map0 : map1)[l[i]];
	for(int i = 1;i <= n;++i) min[i] = c0[i];
	for(int i = 1;i <= m;++i) if(tp[i] == 1) min[l[i]] = std::min(min[l[i]], d[i]);
	int ss = 0, s = n + n + n + 1, t = s + 1, tt = t + 1;
	for(int i = 1;i <= n;++i) {
		int l = c0[i] - min[i] + 1 >> 1, r = c0[i] + min[i] >> 1;
		adde(s, i, r - l), deg[s] += l, deg[i] -= l;
	}
	for(int i = 1;i <= n;++i) min[i] = c1[i];
	for(int i = 1;i <= m;++i) if(tp[i] == 2) min[l[i]] = std::min(min[l[i]], d[i]);
	for(int i = 1;i <= n;++i) {
		int l = c1[i] - min[i] + 1 >> 1, r = c1[i] + min[i] >> 1;
		adde(i + n + n, t, r - l), deg[i + n + n] += l, deg[t] -= l;
	}
	adde(t, s, 1e9);
	for(int i = 1;i <= t;++i) {
		if(deg[i] < 0) adde(ss, i, -deg[i]);
		if(deg[i] > 0) adde(i, tt, deg[i]);
	}
	dinic(ss, tt);
	for(int i = h[ss];i;i=way[i].nxt)
		if(way[i].v) return puts("-1"), 0;
	for(int i = h[ss];i;i=way[i].nxt) way[i].v = way[i ^ 1].v = 0;
	for(int i = h[tt];i;i=way[i].nxt) way[i].v = way[i ^ 1].v = 0;
	dinic(s, t);
	long long sum = 0;
	for(int i = 1;i <= n;++i) sum += way[h[i + n]].v ? r : b;
	std::cout << sum << '\n';
	for(int i = 1;i <= n;++i) std::cout << "br"[way[h[i + n]].v ^ rev];
}