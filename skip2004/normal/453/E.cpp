#include<bits/stdc++.h>
const int maxn = 100100;
typedef long long ll;
using std::cin;
using std::cout;
int n, m;
std::map<int, int> map;
inline std::map<int, int>::iterator split(int r) {
	auto iter = map.lower_bound(r);
	return iter -> first == r ? iter : map.emplace_hint(iter, r, prev(iter) -> second);
}
int start[maxn], max[maxn], add[maxn];
struct ask { int l, r, t, id; };
ll ans[maxn];
std::vector<ask> vec;
inline int cmp0(const ask & x, const ask & y) { return x.t < y.t; }

inline void calc0(int l, int r, int t, int id) { vec.push_back((ask){l, r, t, id}); }
inline void calc1(int l, int r, int t, int id) { for(int i = l;i <= r;++i) ans[id] += std::min<ll>(max[i], start[i] + (ll) add[i] * t); }

inline void make(int l, int r, int t, int id) {
	auto R = split(r + 1), L = split(l);
	for(auto i = L;i != R;++i) {
		if(i -> second != -1)
			calc0(i -> first, next(i) -> first - 1, t - i -> second, id);
		else
			calc1(i -> first, next(i) -> first - 1, t, id);
	}
	map.erase(L, R), map[l] = t;
}

ll sum[maxn << 2], rem[maxn << 2], min_add[maxn << 2], tag[maxn << 2];

inline void update(int cur) {
	sum[cur] = sum[cur << 1] + sum[cur << 1 | 1];
	rem[cur] = rem[cur << 1] + rem[cur << 1 | 1];
	min_add[cur] = std::min(min_add[cur << 1], min_add[cur << 1 | 1]);
}
inline void build(int cur, int l, int r) {
	if(l == r) {
		rem[cur] = add[l];
		min_add[cur] = add[l] ? max[l] / add[l] : int(1e9);
		return ;
	}
	int mid = l + r >> 1;
	build(cur << 1, l, mid);
	build(cur << 1 | 1, mid + 1, r);
	update(cur);
}
inline void put(int cur, ll v) {
	sum[cur] += rem[cur] * v;
	tag[cur] += v;
	min_add[cur] -= v;
}
inline void pushdown(int cur) {
	if(tag[cur] != 0) {
		put(cur << 1, tag[cur]);
		put(cur << 1 | 1, tag[cur]);
		tag[cur] = 0;
	}
}
inline void upt(int v, int cur = 1, int l = 1, int r = n) {
	if(v <= min_add[cur]) return put(cur, v);
	if(l == r) {
		sum[cur] = max[l];
		rem[cur] = 0;
		min_add[cur] = 1e9;
		return ;
	}
	int mid = l + r >> 1; pushdown(cur);
	upt(v, cur << 1, l, mid);
	upt(v, cur << 1 | 1, mid + 1, r);
	update(cur);
}
inline ll ask(int ql, int qr, int cur = 1, int l = 1, int r = n) {
	if(ql <= l && r <= qr) return sum[cur];
	int mid = l + r >> 1; pushdown(cur);
	ll ans = 0;
	if(ql <= mid) ans += ask(ql, qr, cur << 1, l, mid);
	if(mid < qr) ans += ask(ql, qr, cur << 1 | 1, mid + 1, r);
	return ans;
}

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;++i) {
		cin >> start[i] >> max[i] >> add[i];
	}
	cin >> m;
	map[0] = map[n + 1] = -1;
	for(int i = 1, t, l, r;i <= m;++i) {
		cin >> t >> l >> r;
		make(l, r, t, i);
	}
	sort(vec.begin(), vec.end(), cmp0);
	int last_time = 0;
	build(1, 1, n);
	for(const auto & x : vec) {
		if(x.t != last_time) {
			upt(x.t - last_time), last_time = x.t;
		}
		ans[x.id] += ask(x.l, x.r);
	}
	for(int i = 1;i <= m;++i) {
		cout << ans[i] << '\n';
	}
}