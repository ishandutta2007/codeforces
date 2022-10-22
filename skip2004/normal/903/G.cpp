#include<bits/stdc++.h>
const int maxn = 200200;
typedef long long ll;
using std::cin;
using std::cout;
int n, m, q;
int v0[maxn], v1[maxn];
ll min[maxn << 2], tag[maxn << 2];
inline void put(int cur, ll v) {
	min[cur] += v;
	tag[cur] += v;
}
inline void update(int cur) {
	min[cur] = std::min(min[cur << 1], min[cur << 1 | 1]);
}
inline void pushdown(int cur) {
	if(tag[cur] != 0) {
		put(cur << 1, tag[cur]);
		put(cur << 1 | 1, tag[cur]);
		tag[cur] = 0;
	}
}
template<class ptr>
inline void build(int cur, int l, int r, ptr v1) {
	tag[cur] = 0;
	if(l == r) {
		min[cur] = v1[l];
		return ;
	}
	int mid = (l + r) >> 1;
	build(cur << 1, l, mid, v1);
	build(cur << 1 | 1, mid + 1, r, v1);
	update(cur);
}
inline void upt(int ql, int qr, int v, int cur = 1, int l = 1, int r = n) {
	if(ql <= l && r <= qr) return put(cur, v);
	int mid = l + r >> 1; pushdown(cur);
	if(ql <= mid) upt(ql, qr, v, cur << 1, l, mid);
	if(mid < qr) upt(ql, qr, v, cur << 1 | 1, mid + 1, r);
	update(cur);
}

struct edge { int x, y, v; };
inline int cmp0(const edge & x, const edge & y) {
	return x.x < y.x;
}
ll min_cost[maxn];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m >> q;
	for(int i = 1;i < n;++i) cin >> v0[i] >> v1[i + 1];
	std::vector<edge> vector;
	for(int i = 0, x, y, z;i < m;++i) {
		cin >> x >> y >> z;
		vector.push_back((edge){x, y, z});
	}
	build(1, 1, n, v1);
	sort(vector.begin(), vector.end(), cmp0);
	for(int i = 1;i <= n;++i) {
		static auto iter = vector.begin();
		for(;iter != vector.end() && iter -> x <= i;++iter) upt(1, iter -> y, iter -> v);
		min_cost[i] = min[1] + v0[i];
	}
	build(1, 1, n, min_cost);
	cout << min[1] << '\n';
	for(int i = 1, v, w;i <= q;++i) {
		cin >> v >> w;
		w -= v0[v], upt(v, v, w), v0[v] += w;
		cout << min[1] << '\n';
	}
}