#include<bits/stdc++.h>
const int maxn = 500500;
const int mod = 1e9 + 7;
typedef long long ll;
using std::cin;
using std::cout;
int n;

int buf[maxn << 4], * end = buf + (maxn << 4);
int fac[maxn];

void error() {
	puts("0");
	exit(0);
}
struct list {
	std::vector<int> vector;
	std::unordered_map<int, int> index;
	int * nxt, * pre, * fa, * size;
	int first, last, is;
	inline int calc() {
		int cnt = 0;
		for(int i = 1;i <= is;++i)
			cnt += fa[i] == i;
		if(first)
			-- cnt;
		if(last && find(last) != find(first))
			-- cnt;
		return fac[cnt];
	}
	inline void init(std::vector<int> & vec) {
		vector = vec;
		sort(vector.begin(), vector.end());
		nxt = end -= vec.size() + 1;
		pre = end -= vec.size() + 1;
		fa = end -= vec.size() + 1;
		size = end -= vec.size() + 1;
		is = vec.size();
		for(int i = 1;i <= vec.size();++i) fa[i] = i, size[i] = 1;
		for(int i = 0;i < vec.size();++i) {
			index[vec[i]] = i + 1;
		}
	}
	inline void set_first(int x) {
		if(!can_first(x)) error();
		first = index[x];
	}
	inline void set_last(int x) {
		if(!can_last(x)) error();
		last = index[x];
	}
	inline int can_first(int x){
		x = index[x];
		if(first) return x == first;
		if(pre[x]) return 0;
		return find(x) == find(last) ? size[find(x)] == is : 1;
	}
	inline int can_last(int x){
		x = index[x];
		if(last) return x == last;
		if(nxt[x]) return 0;
		return find(x) == find(first) ? size[find(x)] == is : 1;
	}
	inline int find(int x){ return fa[x] == x ? x : fa[x] = find(fa[x]); }
	inline int after(int a,int b){
		a = index[a];
		b = index[b];
		if(nxt[a] == b) return 1;
		if(a == last || b == first || nxt[a] || pre[b] || find(a) == find(b)) return 0;
		if(find(a) == find(first) && find(b) == find(last)) return size[find(a)] + size[find(b)] == is;
		return 1;
	}
	inline void set_after(int a,int b){
		if(!after(a, b)) error();
		a = index[a], b = index[b];
		nxt[a] = b; pre[b] = a;
		int vx = find(a),vy = find(b);
		if(size[vx] > size[vy]) std::swap(vx,vy);
		fa[vx] = vy; size[vy] += size[vx];
	}
} s[maxn];

struct edge {
	int to, nxt;
} way[maxn << 1];
int h[maxn], num = 1;

inline void link(int x, int y) {
	way[++num] = {y, h[x]}, h[x] = num;
	way[++num] = {x, h[y]}, h[y] = num;
}

int a[maxn], ia[maxn];

int fa[maxn], fa_edge[maxn], dfn[maxn], tot;

int st[20][maxn];

inline int min(int x, int y) {
	return dfn[x] < dfn[y] ? x : y;
}

inline int lca(int x, int y) {
	if(dfn[x] > dfn[y]) std::swap(x, y);
	const int lg = std::__lg(dfn[y] - dfn[x]);
	return min(st[lg][dfn[x]], st[lg][dfn[y] - (1 << lg)]);
}
inline void dfs0(int x, int fa = 0) {
	st[0][tot] = fa, dfn[x] = ++ tot;
	::fa[x] = fa;
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa) {
		dfs0(way[i].to, x);
		fa_edge[way[i].to] = i >> 1;
	}
}
inline void go(int x, int y) {
//	cout << "go : " << x << " -> " << y << std::endl;
	if(x == y) {
		error();
	}
	std::vector<int> edge_list, rev, node_list, rev_node;
	int lca = :: lca(x, y);
	for(int i = x;i != lca;i = fa[i]) {
		edge_list.push_back(fa_edge[i]);
		node_list.push_back(i);
	}
	for(int i = y;i != lca;i = fa[i]) {
		rev.push_back(fa_edge[i]);
		rev_node.push_back(i);
	}
	node_list.push_back(lca);

	edge_list.insert(edge_list.end(), rev.rbegin(), rev.rend());
	node_list.insert(node_list.end(), rev_node.rbegin(), rev_node.rend());

	s[x].set_first(edge_list.front());
	s[y].set_last(edge_list.back());
	for(int i = 0;i + 1 < edge_list.size();++i) {
		s[node_list[i + 1]].set_after(edge_list[i], edge_list[i + 1]);
	}
}

std::vector<int> edge[maxn];

int main() {
	*fac = 1;
	for(int i = 1;i < maxn;++i) {
		fac[i] = (ll) fac[i - 1] * i % mod;
	}
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1, x, y;i < n;++i) {
		cin >> x >> y;
		link(x, y);
	}

	for(int i = 1;i <= n;++i) {
		cin >> a[i];
	}

	for(int i = 2;i <= num;++i) {
		edge[way[i].to].emplace_back(i / 2);
	}
	for(int i = 1;i <= n;++i) {
		s[i].init(edge[i]);
	}
	dfs0(1);
	for(int i = 1;i < 20;++i) {
		for(int j = 1;j + (1 << i) - 1 < n;++j) {
			st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
		}
	}


	for(int i = 1;i <= n;++i) {
		if(a[i]) {
			go(a[i], i);
		}
	}
	int ans = 1;
	for(int i = 1;i <= n;++i) {
		ans = (ll) ans * s[i].calc() % mod;
	}
	cout << ans << '\n';
}