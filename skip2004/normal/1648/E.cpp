#include<vector>
#include<assert.h>
#include<set>
#include<iostream>
#include<algorithm>

using std::cin;
using std::cout;
const int N = 400005;
int t, n, m;
struct e { int u, v, w, id; };
inline bool cmp(const e & x, const e & y) {
	return x.w < y.w;
}
int anc[N], w[N], ls[N], rs[N], id[N], cnt, tot;
std::set<int> set[N];
std::vector<int> edge[N];
int ans[N];
inline void clear() {
	for(int i = 0;i <= n + n;++i) {
		anc[i] = w[i] = ls[i] = rs[i] = id[i] = ans[i] = 0;
		set[i].clear(), edge[i].clear();
	}
	cnt = tot = 0;
}
namespace big {
	int anc[N];
	inline int find(int x) {
		return anc[x] == x ? x : anc[x] = find(anc[x]);
	}
	std::set<int> ap;
	inline void init() {
		for(int i = 1;i < n;++i) ap.insert(i);
		for(int i = 1;i <= n;++i) anc[i] = i;
	}
	int cnt;
	struct qrys { int x, y, id; };
	std::vector<qrys> ss[N];
	inline void clear() {
		for(int i = 0;i <= n;++i) ss[i].clear(), anc[i] = 0;
		cnt = 0, ap.clear();
	}
	inline void link(int x, int y, int w) {
		if(find(x) != find(y)) {
			auto & A = ss[find(x)];
			auto & B = ss[find(y)];
			anc[find(x)] = find(y);
			if(A.size() > B.size()) A.swap(B);
			for(auto & i : A) {
				if(ans[i.id] == -1) {
					if(find(i.x) == find(i.y)) {
						ans[i.id] = w;
					}
				}
			}
			B.insert(B.end(), A.begin(), A.end());
			if(ss[find(x)].size() != B.size()) A.swap(B);
		}
	}
	inline void ins(int p, int l, int r, int w) {
		link(p, l, w);
		auto L = ap.lower_bound(l);
		auto R = ap.upper_bound(r - 1);
		for(auto i = L;i != R;++i) link(*i + 1, *i, w);
		ap.erase(L, R);
	}
}
inline void un(int x, int y, int W) {
	if(set[x].size() > set[y].size()) std::swap(x, y);
	int L = *set[y].begin(), R = *set[y].rbegin();
	assert(R - L + 1 == set[y].size());
	for(int p : set[x]) {
		auto l = lower_bound(edge[p].begin(), edge[p].end(), L);
		auto r = upper_bound(edge[p].begin(), edge[p].end(), R);
		int lst = L - 1;
		for(auto i = l;i != r;++i) {
			int w = *i;
			if(lst + 1 < w) big::ins(p, lst + 1, w - 1, W);
			lst = w;
		}
		if(lst < R) big::ins(p, lst + 1, R, W);
	}
	set[y].insert(set[x].begin(), set[x].end());
	anc[x] = y;
}
inline int find(int x) {
	return anc[x] == x ? x : anc[x] = find(anc[x]);
}
inline void dfs(int x) {
	if(x <= n) id[x] = ++ tot;
	else dfs(ls[x]), dfs(rs[x]);
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> t;
	for(int i = 0;i < t;++i) {
		cin >> n >> m;
		std::vector<e> o(m);
		for(int i = 0;i < m;++i) {
			e & x = o[i];
			cin >> x.u >> x.v >> x.w;
			x.id = i;
		}
		sort(o.begin(), o.end(), cmp);
		for(int i = 1;i <= n;++i) anc[i] = i, w[i] = i;
		cnt = n;
		for(e x : o) {
			if(find(x.u) != find(x.v)) {
				ls[++cnt] = w[find(x.u)];
				rs[cnt] = w[find(x.v)];
				anc[find(x.u)] = find(x.v);
				w[find(x.u)] = cnt;
			}
		}
		tot = 0, dfs(cnt);
		for(e & x : o) x.u = id[x.u], x.v = id[x.v], edge[x.u].push_back(x.v), edge[x.v].push_back(x.u);
		for(int i = 1;i <= n + n;++i) {
			anc[i] = w[i] = ls[i] = rs[i] = 0;
		}
		for(int i = 1;i <= n;++i) sort(edge[i].begin(), edge[i].end());
		for(e x : o) {
			big::ss[x.u].push_back({x.u, x.v, x.id});
			big::ss[x.v].push_back({x.u, x.v, x.id});
		}
		for(int i = 0;i < m;++i) ans[i] = -1;
		big::init();
		for(int i = 1;i <= n;++i) anc[i] = i, set[i].emplace(i);
		for(e x : o) {
			if(find(x.u) != find(x.v)) {
				un(find(x.u), find(x.v), x.w);
			}
		}
		for(int i = 0;i < m;++i) {
			cout << ans[i] << " \n"[i == m - 1];
		}
		big::clear();
		clear();
	}
}