#include<bits/stdc++.h>
const int maxn = 500100;
typedef long long ll;
using std::cin;
using std::cout;
struct T {
	int x, y, c;
} a[maxn];
int n;
inline int cmp0(const T & x, const T & y) {
	return x.x > y.x;
}
std::vector<int> vec;

int id[maxn << 3];
ll max[maxn << 3], add[maxn << 3];

inline void put(int cur, ll v) {
	max[cur] += v;
	add[cur] += v;
}

inline void pushdown(int cur) {
	if(add[cur] != 0) {
		put(cur << 1, add[cur]);
		put(cur << 1 | 1, add[cur]);
		add[cur] = 0;
	}
}

inline void update(int cur) {
	if(max[cur << 1] < max[cur << 1 | 1]) {
		max[cur] = max[cur << 1 | 1];
		id[cur] = id[cur << 1 | 1];
	} else {
		max[cur] = max[cur << 1];
		id[cur] = id[cur << 1];
	}
}
inline void build(int cur, int l, int r) {
	if(l == r) {
		max[cur] = id[cur] = -vec[l - 1];
		return ;
	}
	int mid = l + r >> 1;
	build(cur << 1, l, mid);
	build(cur << 1 | 1, mid + 1, r);
	update(cur);
}

inline void upt(int ql, int qr, int v, int cur = 1, int l = 1, int r = vec.size()) {
	if(ql <= l && r <= qr) return put(cur, v);
	int mid = l + r >> 1; pushdown(cur);
	if(ql <= mid) upt(ql, qr, v, cur << 1, l, mid);
	if(mid < qr) upt(ql, qr, v, cur << 1 | 1, mid + 1, r);
	update(cur);
}
ll mx, idx;
inline void ask(int ql, int qr, int cur = 1, int l = 1, int r = vec.size()) {
	if(ql <= l & r <= qr) {
		if(max[cur] >= mx) {
			mx = max[cur];
			idx = id[cur];
		}
		return ;
	}
	int mid = l + r >> 1; pushdown(cur);
	if(ql <= mid) ask(ql, qr, cur << 1, l, mid);
	if(mid < qr) ask(ql, qr, cur << 1 | 1, mid + 1, r);
}
inline int get(int x) {
	return std::lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;
}
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;++i) {
		cin >> a[i].x >> a[i].y >> a[i].c;
		if(a[i].y < a[i].x) std::swap(a[i].x, a[i].y);
		vec.push_back(a[i].x);
		vec.push_back(a[i].y);
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	std::sort(a + 1, a + n + 1, cmp0);
	build(1, 1, vec.size());
	ll ans = 0;
	std::mt19937 rd(time(0));
	int ax = rd() % (int) 1e9 + 1, ay = -ax;
	for(int i = 1;i <= n;) {
		int j = i;
		for(;j <= n && a[j].x == a[i].x;++j) {
			upt(get(a[j].y), vec.size(), a[j].c);
		}
		mx = -1e18, ask(get(a[i].x), vec.size());
		if(mx + a[i].x >= ans) {
			ans = mx + a[i].x;
			ax = a[i].x;
			ay = idx;
		}
		i = j;
	}
	cout << ans << '\n';
	cout << ax << ' ' << ax << ' ' << -ay << ' ' << -ay << '\n';
}