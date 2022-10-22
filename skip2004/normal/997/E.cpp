#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
typedef long long ll;
const int mod = 998244353;
int a[maxn], n, q;
ll sum[maxn << 2], tag[maxn << 2];
int min[maxn << 2], add[maxn << 2], cnt[maxn << 2];
inline void put(int x, int v) {
	min[x] += v;
	add[x] += v;
}
inline void put_min(int x, int v) {
	tag[x] += v;
	sum[x] += (ll) cnt[x] * v;
}
inline void down(int cur) {
	put(cur << 1, add[cur]);
	put(cur << 1 | 1, add[cur]);
	if(min[cur << 1] == min[cur]) put_min(cur << 1, tag[cur]);
	if(min[cur << 1 | 1] == min[cur]) put_min(cur << 1 | 1, tag[cur]);
	tag[cur] = add[cur] = 0;
}
inline void up(int cur) {
	sum[cur] = sum[cur << 1] + sum[cur << 1 | 1];
	min[cur] = std::min(min[cur << 1], min[cur << 1 | 1]);
	cnt[cur] = 0;
	if(min[cur << 1] == min[cur]) cnt[cur] += cnt[cur << 1];
	if(min[cur << 1 | 1] == min[cur]) cnt[cur] += cnt[cur << 1 | 1];
}
inline void upt(int ql, int qr, int v, int cur = 1, int l = 1, int r = n) {
	if(ql <= l && r <= qr) return put(cur, v);
	int mid = l + r >> 1; down(cur);
	if(ql <= mid) upt(ql, qr, v, cur << 1, l, mid);
	if(mid < qr) upt(ql, qr, v, cur << 1 | 1, mid + 1, r);
	up(cur);
}
inline ll qry(int ql, int qr, int cur = 1, int l = 1, int r = n) {
	if(ql <= l && r <= qr) return sum[cur];
	int mid = l + r >> 1; down(cur); ll ret = 0;
	if(ql <= mid) ret += qry(ql, qr, cur << 1, l, mid);
	if(mid < qr) ret += qry(ql, qr, cur << 1 | 1, mid + 1, r);
	return ret;
}
inline void build(int cur = 1, int l = 1, int r = n) {
	if(l == r) {
		min[cur] = l;
		cnt[cur] = 1;
	} else {
		int mid = l + r >> 1;
		build(cur << 1, l, mid);
		build(cur << 1 | 1, mid + 1, r);
		up(cur);
	}
}
std::vector<std::pair<int, int>> vc[maxn];
ll ans[maxn];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	rep(i, 1, n) {
		cin >> a[i];
	}
	cin >> q;
	rep(i, 1, q) {
		int l, r;
		cin >> l >> r;
		vc[r].emplace_back(l, i);
	}
	build();
	int t0 = 0, t1 = 0;
	rep(i, 1, n) {
		static int st0[maxn], st1[maxn];
		for(;t0 && a[st0[t0]] > a[i];-- t0) {
			upt(st0[t0 - 1] + 1, st0[t0], a[st0[t0]]);
		}
		for(;t1 && a[st1[t1]] < a[i];-- t1) {
			upt(st1[t1 - 1] + 1, st1[t1], - a[st1[t1]]);
		}
		upt(st0[t0] + 1, i, - a[i]);
		upt(st1[t1] + 1, i, a[i]);
		st0[++t0] = i;
		st1[++t1] = i;
		upt(1, n, -1);
		put_min(1, 1);
		for(auto x : vc[i]) {
			ans[x.second] = qry(x.first, i);
		}
	}
	rep(i, 1, q) {
		cout << ans[i] << '\n';
	}
}