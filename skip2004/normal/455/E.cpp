#include<bits/stdc++.h>
using std::cin;
using std::cout;
const int maxn = 100100;
int n, m;
int a[maxn];
struct ask { int id, cnt, i; };
std::vector<ask> vec;
int ans[maxn];
int pre[maxn], val[maxn];
inline void down(int & x, int y) {
	if(x > y) x = y;
}

inline int cmp0(const ask & x, const ask & y) {
	return x.cnt - x.i < y.cnt - y.i;
}
namespace EI {
	struct fc { int v, k; } tree[maxn << 2];
	int min[maxn << 2], add[maxn << 2];
	inline int get(const fc & x, const fc & y) {
		if(x.k <= y.k) return 2e9;
		return (y.v - x.v) / (x.k - y.k);
	}
	inline void update(int cur) {
		min[cur] = std::min(min[cur << 1], min[cur << 1 | 1]);
		if(tree[cur << 1].v < tree[cur << 1 | 1].v) {
			tree[cur] = tree[cur << 1];
			down(min[cur], get(tree[cur << 1], tree[cur << 1 | 1]));
		} else {
			tree[cur] = tree[cur << 1 | 1];
			down(min[cur], get(tree[cur << 1 | 1], tree[cur << 1]));
		}
	}
	inline void put(int cur, int v) {
		tree[cur].v += tree[cur].k * v;
		min[cur] -= v;
		add[cur] += v;
	}
	inline void build(int cur, int l, int r) {
		if(l == r) {
			tree[cur] = (fc) {val[l], a[l]};
			min[cur] = 2e9;
			return ;
		}
		int mid = l + r >> 1;
		build(cur << 1, l, mid);
		build(cur << 1 | 1, mid + 1, r);
		update(cur);
	}
	inline void pushdown(int cur) {
		if(add[cur] != 0) {
			put(cur << 1, add[cur]);
			put(cur << 1 | 1, add[cur]);
			add[cur] = 0;
		}
	}
	inline void upt(int v, int cur = 1, int l = 1, int r = n) {
		if(v <= min[cur]) return put(cur, v);
		int mid = l + r >> 1;
		pushdown(cur);
		upt(v, cur << 1, l, mid);
		upt(v, cur << 1 | 1, mid + 1, r);
		update(cur);
	}
	inline int ask(int ql, int qr, int cur = 1, int l = 1, int r = n) {
		if(ql <= l && r <= qr) return tree[cur].v;
		int mid = l + r >> 1, ans = 2e9;
		pushdown(cur);
		if(ql <= mid) down(ans, ask(ql, qr, cur << 1, l, mid));
		if(mid < qr) down(ans, ask(ql, qr, cur << 1 | 1, mid + 1, r));
		return ans;
	}
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;++i) {
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
	}
	cin >> m;
	for(int i = 1, x, y;i <= m;++i) {
		cin >> x >> y;
		vec.push_back((ask){ i, x, y });
	}
	sort(vec.begin(), vec.end(), cmp0);
	int last = vec.front().cnt - vec.front().i;
	for(int i = 1;i <= n;++i) {
		val[i] = (i - 1) * a[i] - pre[i - 1] + last * a[i];
	}
	EI::build(1, 1, n);
	for(const auto & x : vec) {
		const int L = x.i - x.cnt + 1, R = x.i;
		const int rem = x.cnt - R;
		if(rem != last) EI::upt(rem - last), last = rem;
		ans[x.id] = EI::ask(L, R) + pre[x.i];
	}
	for(int i = 1;i <= m;++i) {
		cout << ans[i] << '\n';
	}
}