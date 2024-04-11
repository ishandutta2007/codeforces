
#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;
 
typedef unsigned long long u64;
typedef double db;
typedef long long ll;
typedef unsigned u32;
 
typedef std::bitset<105> set;
const int N = 105;
 
std::unordered_map<u64, std::pair<int, int>> map;
 
int n;
struct edge { int to, nxt; } e[N << 1];
int h[N], num = 1;
inline void link(int x, int y) {
	e[++num] = {y, h[x]}, h[x] = num;
	e[++num] = {x, h[y]}, h[y] = num;
}
 
u64 hsh[N];
inline u64 gen(u64 x) {
	x ^= x << 13;
	x ^= x >> 7;
	x ^= x << 17;
	return x;
}
inline void dfs2(int x, int fa, const set & s) {
	hsh[x] = 1428781;
	for(int i = h[x];i;i = e[i].nxt) if(e[i].to != fa && s.test(e[i].to)) {
		dfs2(e[i].to, x, s);
		hsh[x] += gen(hsh[e[i].to]) + 124;
	}
}
u64 min;
inline void dfs3(int x, int fa, const set & s) {
	min = std::min(min, hsh[x]);
	for(int i = h[x];i;i = e[i].nxt) if(e[i].to != fa && s.test(e[i].to)) {
		const int to = e[i].to;
		hsh[x] -= gen(hsh[to]) + 124;
		hsh[to] += gen(hsh[x]) + 124;
		dfs3(e[i].to, x, s);
		hsh[to] -= gen(hsh[x]) + 124;
		hsh[x] += gen(hsh[to]) + 124;
	}
}
inline u64 gethash(const set & x) {
	min = -1;
	dfs2(x._Find_first(), 0, x);
	dfs3(x._Find_first(), 0, x);
	return min;
}
 
set vis;
inline void dfs0(int x, int fa, const set & s) {
	vis.set(x);
	for(int i = h[x];i;i = e[i].nxt) if(e[i].to != fa && s.test(e[i].to))
		dfs0(e[i].to, x, s);
}
struct pr { int id, v; };
inline int operator < (const pr & x, const pr & y) { return x.v < y.v; }
int size[N];
inline void dfs1(int x, int fa, const set & s, int all, std::vector<pr>&edge) {
	size[x]=1;
	for(int i = h[x];i;i = e[i].nxt) if(e[i].to != fa && s.test(e[i].to)) {
		dfs1(e[i].to, x, s, all, edge);
		edge.push_back((pr){i,std::max(size[e[i].to],all-size[e[i].to])});
		size[x]+=size[e[i].to];
	}
}
std::mt19937 g;
inline std::pair<int, int> calc_min(set x, int could = 1) {
	static std::vector<pr> mem[N],*it=mem;
	if(x.count() == 1) return {0, 0};
	const set & st = x;
	u64 v = gethash(x);
	auto iter = map.find(v);
	if(could && iter != map.end()) return iter -> second;
	std::vector<pr>&edge = *it; ++ it;
	edge.clear(), dfs1(x._Find_first(), 0, x, x.count(), edge);
	sort(edge.begin(), edge.end());
	int best = 1e9, who = -1;
	const int M = x.count() >= 20 ? 6 : 10;
	if(edge.size()>M)edge.resize(M);
	for(pr id : edge) {
		const int x = e[id.id].to, y = e[id.id ^ 1].to;
		vis.reset(), dfs0(x, y, st);
		int value = calc_min(vis).first + 1;
		if(value >= best) continue;
		vis.reset(), dfs0(y, x, st);
		value = std::max(calc_min(vis).first + 1, value);
		if(value < best) {
			best = value;
			who = id.id;
		}
	}
	--it;
	return map[v] = {best, who};
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for(int i = 1, x, y;i < n;++i) {
		cin >> x >> y, link(x, y);
	}
	set may;
	for(int i = 1;i <= n;++i) may.set(i);
	// cout << calc_min(may, 0).second << '\n';;
	for(;may.count() > 1;) {
		int id = calc_min(may, 0).second;
 
		const int x = e[id].to, y = e[id ^ 1].to;
		cout << "? " << x << ' ' << y << std::endl;
		int who;
		cin >> who;
		vis.reset();
		dfs0(who, who ^ x ^ y, may);
		may = vis;
	}
	cout << "! " << may._Find_first() << '\n';
}