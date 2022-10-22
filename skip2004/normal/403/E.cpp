#include<bits/stdc++.h>
using std::cin;
using std::cout;
using vec = std::vector<int>;
#define pb push_back
const int maxn = 200200;
int n;
struct tree {
	struct edge {
		int to, nxt;
	} way[maxn << 1];
	int h[maxn], num;
	inline void link(int x, int y) {
		way[++num] = {y, h[x]}, h[x] = num;
		way[++num] = {x, h[y]}, h[y] = num;
	}
	vec seg[maxn << 2];
	int dfn[maxn], size[maxn], son[maxn], top[maxn], fa[maxn], dep[maxn];
	int tot;
	inline void dfs0(int x, int fa = 0) {
		size[x] = 1, dep[x] = dep[fa] + 1, this -> fa[x] = fa;
		for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa) {
			dfs0(way[i].to, x);
			size[x] += size[way[i].to];
			if(size[son[x]] < size[way[i].to]) {
				son[x] = way[i].to;
			}
		}
	}
	inline void dfs1(int x, int top, int fa = 0) {
		this -> top[x] = top, dfn[x] = ++ tot;
		if(son[x]) dfs1(son[x], top, x);
		for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa && way[i].to != son[x]) {
			dfs1(way[i].to, way[i].to, x);
		}
	}
	inline void emplace(int ql, int qr, int v, int cur = 1, int l = 1, int r = n) {
		if(ql <= l && r <= qr) {
			seg[cur].pb(v);
			return ;
		}
		int mid = l + r >> 1;
		if(ql <= mid) emplace(ql, qr, v, cur << 1, l, mid);
		if(mid < qr) emplace(ql, qr, v, cur << 1 | 1, mid + 1, r);
	}
	inline void clear(int pos, vec& vc, int cur = 1, int l = 1, int r = n) {
		vc.insert(vc.end(), seg[cur].begin(), seg[cur].end()), seg[cur].clear();
		if(l == r) return ;
		int mid = l + r >> 1;
		pos <= mid ? clear(pos, vc, cur << 1, l, mid) : clear(pos, vc, cur << 1 | 1, mid + 1, r);
	}
	inline void put(int x, int y, int id) {
		for(;top[x] != top[y];) {
			if(dep[top[x]] < dep[top[y]]) std::swap(x, y);
			emplace(dfn[top[x]], dfn[x], id), x = fa[top[x]];
		}
		if(x != y) emplace(std::min(dfn[x], dfn[y]) + 1, std::max(dfn[x], dfn[y]), id);
	}
} t[2];
using pr = std::pair<int, int>;
pr a0[maxn], a1[maxn];
int v0[maxn], v1[maxn];
std::vector<int> set[maxn];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for(int i = 2, fa;i <= n;++i) cin >> fa, t[0].link(fa, i), a0[i - 1] = pr(fa, i);
	for(int i = 2, fa;i <= n;++i) cin >> fa, t[1].link(fa, i), a1[i - 1] = pr(fa, i);
	t[0].dfs0(1), t[0].dfs1(1, 1);
	t[1].dfs0(1), t[1].dfs1(1, 1);
	for(int i = 1;i < n;++i) {
		t[1].put(a0[i].first, a0[i].second, i);
		t[0].put(a1[i].first, a1[i].second, i);
	}
	int id; cin >> id;
	set[1].emplace_back(id), v0[id] = 1;
	for(int i = 1;;++i) {
		if(set[i].empty()) break;
		cout << (i & 1 ? "Blue" : "Red") << '\n';
		tree & t0 = t[i + 1 & 1], & t1 = t[i & 1];
		pr* edge = i & 1 ? a0 : a1;
		int* vis = i & 1 ? v1 : v0;
		sort(set[i].begin(), set[i].end());

		for(int x : set[i]) {
			cout << x << ' ';
			std::vector<int> vector;
			t0.clear(t0.dfn[t0.dep[edge[x].first] < t0.dep[edge[x].second] ? edge[x].second : edge[x].first], vector);
			for(int cur : vector) if(!vis[cur]) {
				vis[cur] = 1;
				set[i + 1].emplace_back(cur);
			}
		}
		cout << '\n';
	}
}