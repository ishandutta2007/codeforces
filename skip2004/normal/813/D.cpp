#include<bits/stdc++.h>
const int maxn = 100100;
using std::cin;
using std::cout;
struct T {
	int to, nxt, v, f;
} way[maxn << 1];
int h[maxn], num = 1;
inline void link(int x, int y, int v, int f) {
	way[++num] = {y, h[x], v, f}, h[x] = num;
	way[++num] = {x, h[y], 0, -f}, h[y] = num;
}
int dis[maxn], vis[maxn], fr[maxn];
std::queue<int> q;
inline bool relax(int x, int d) {
	if(d > dis[x]) {
		dis[x] = d;
		if(!vis[x]) vis[x] = 1, q.push(x);
		return true;
	}
	return false;
}
inline int bellmanford(int s, int t) {
	for(int i = s;i <= t;++i) dis[i] = -1;
	for(relax(s, 0);!q.empty();) {
		int x = q.front(); q.pop(); vis[x] = 0;
		for(int i = h[x];i;i = way[i].nxt) if(way[i].v)
			if(relax(way[i].to, dis[x] + way[i].f))
				fr[way[i].to] = i;
	}
	return dis[t] >= 0;
}
inline int ek(int s, int t) {
	int ans = 0;
	for(int c = 0;c < 2 && bellmanford(s, t);++c) {
		ans += dis[t];
		for(int i = t;i != s;i = way[fr[i] ^ 1].to) {
			way[fr[i]].v -= 1;
			way[fr[i] ^ 1].v += 1;
		}
	}
	return ans;
}
int n, tot;
int a[maxn];
int is[maxn];
int flg[7];
inline void add(int & x, int y) {
	int og = x;
	link(x = ++ tot, y, 1, 0);
	if(og) link(x, og, 1, 0);
}
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	cin >> n;
	tot = n + n;
	for(int i = 1;i <= n;++i) {
		cin >> a[i];
		link(0, i, 1, 0);
		link(i, i + n, 1, 1);
		if(is[a[i] - 1]) link(i + n, is[a[i] - 1], 1, 0);
		if(is[a[i] + 1]) link(i + n, is[a[i] + 1], 1, 0);
		if(is[a[i]]) link(i + n, is[a[i]], 1, 0);
		if(flg[a[i] % 7]) link(i + n, flg[a[i] % 7], 1, 0);
		add(is[a[i]], i);
		add(flg[a[i] % 7], i);
	}
	++ tot;
	for(int i = 1;i <= n;++i) {
		link(i + n, tot, 1, 0);
	}
	cout << ek(0, tot) << '\n';
}