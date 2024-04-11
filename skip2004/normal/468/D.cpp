#include<bits/stdc++.h>
using std::cin;
using std::cout;
const int maxn = 100100;
typedef long long ll;
int n;
struct edge {
	int to, nxt, v;
} way[maxn << 1];
int h[maxn], num;
inline void link(int x, int y, int v) {
	way[++num] = {y, h[x], v}, h[x] = num;
	way[++num] = {x, h[y], v}, h[y] = num;
}
int size[maxn];
std::vector<int> roots;
ll yhx12243 = 0;
inline void dfs0(int x, int fa = 0) {
	size[x] = 1;
	int max = 0;
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa) {
		dfs0(way[i].to, x);
		size[x] += size[way[i].to];
		max = std::max(max, size[way[i].to]);
		yhx12243 += std::min<ll>(size[way[i].to], n - size[way[i].to]) * way[i].v;
	}
	max = std::max(max, n - size[x]);
	if(max <= n / 2) {
		roots.push_back(x);
	}
}
int from[maxn];

int max_size[maxn << 2], min_pos[maxn << 2], M;
std::vector<std::vector<int>> vector;
inline void update(int cur) {
	max_size[cur] = std::max(max_size[cur << 1], max_size[cur << 1 | 1]);
	min_pos[cur] = std::min(min_pos[cur << 1], min_pos[cur << 1 | 1]);
}
inline void mdf(int pos, int v, int cur = 1, int l = 0, int r = M) {
	if(l == r) {
		max_size[cur] = v;
		min_pos[cur] = vector[pos].size() ? vector[pos].back() : int(1e9);
		return ;
	}
	int mid = l + r >> 1;
	pos <= mid ? mdf(pos, v, cur << 1, l, mid) : mdf(pos, v, cur << 1 | 1, mid + 1, r);
	update(cur);
}
inline void remove(int pos, int cur = 1, int l = 0, int r = M) {
	if(l == r) {
		min_pos[cur] = 1e9;
		return ;
	}
	int mid = l + r >> 1;
	pos <= mid ? remove(pos, cur << 1, l, mid) : remove(pos, cur << 1 | 1, mid + 1, r);
	update(cur);
}
inline int find(int * val, int cur = 1, int l = 0, int r = M) {
	if(l == r) return l;
	int mid = l + r >> 1;
	return val[cur << 1] == val[cur] ? find(val, cur << 1, l, mid) : find(val, cur << 1 | 1, mid + 1, r);
}
int to[maxn], del[maxn];
inline void solve(std::vector<std::vector<int>> & vec, int root) {
	static int idx;
	for(auto&x:vec) {
		sort(x.rbegin(), x.rend());
		size[idx] = x.size() * 2;
		for(int v : x) from[v] = idx;
		++ idx;
	}
	M = idx - 1;
	for(int i = 0;i <= M;++i) mdf(i, size[i]);
	for(int i = 1;i <= n;++i) {
		mdf(from[i], -- size[from[i]]);
		if(i != root) remove(from[i]);
		int pos = find(max_size[1] != n - i + 1 || (n - i + 1 == 2 && root == n && size[from[n]] == 2) ? min_pos : max_size);
		to[i] = vec[pos].back();
		del[to[i]] = 1;
		vec[pos].pop_back();
		mdf(from[i], size[from[i]]);
		mdf(pos, -- size[pos]);
	}
}
std::vector<int> numbers;
inline void dfs1(int x, int fa = 0) {
	numbers.push_back(x);
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa) {
		dfs1(way[i].to, x);
	}
}
int main() {
	cin >> n;
	for(int i = 1, x, y, v;i < n;++i) {
		cin >> x >> y >> v;
		link(x, y, v);
	}
	dfs0(1);
	if(roots.size() == 1) {
		int x = roots.back();
		vector = {{x}};
		for(int i = h[x];i;i = way[i].nxt) {
			dfs1(way[i].to, x);
			vector.push_back(numbers);
			numbers.clear();
		}
	} else {
		int x = roots.front(), y = roots.back();
		dfs1(x, y), vector = {numbers}, numbers.clear();
		dfs1(y, x), vector.push_back(numbers);
	}
	solve(vector, roots.size() == 1 ? roots[0] : -1);
	cout << yhx12243 * 2 << '\n';
	for(int i = 1;i <= n;++i) {
		cout << to[i] << " \n"[i == n];
	}
}