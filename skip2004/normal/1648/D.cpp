#include<vector>
#include<iostream>
#include<algorithm>

using std::cin;
using std::cout;
const int N = 500005;
using ll = long long;
const ll inf = 1e18;
ll a[N], b[N], c[N];
ll v[N];
ll dp[N];
ll pb[N];
ll pa[N];
ll sc[N];
int n, q;
struct pr { int l, r, k; };
std::vector<pr> o;
inline bool cmp0(const pr & x, const pr & y) {
	return x.r < y.r;
}
struct sgt {
	ll max[N << 2];
	inline void upt(int x, ll w, int cur = 1, int l = 1, int r = n) {
		if(l == r) return void(max[cur] = w);
		int mid = (l + r) >> 1;
		if(x <= mid) {
			upt(x, w, cur << 1, l, mid);
		} else {
			upt(x, w, cur << 1 | 1, mid + 1, r);
		}
		max[cur] = std::max(max[cur << 1], max[cur << 1 | 1]);
	}
	inline ll qry(int ql, int qr, int cur = 1, int l = 1, int r = n) {
		if(ql <= l && r <= qr) return max[cur];
		int mid = (l + r) >> 1;
		ll ans = -inf;
		if(ql <= mid) ans = std::max(ans, qry(ql, qr, cur << 1, l, mid));
		if(mid < qr) ans = std::max(ans, qry(ql, qr, cur << 1 | 1, mid + 1, r));
		return ans;
	}
} sdp, spa;
struct info {
	ll ad, mx, maxv, maxadd, maxmax;
	inline ll operator () (ll x) const {
		return std::max(x + ad, mx);
	}
};
inline info ins(const info & x, const info & y) {
	return (info){x.ad + y.ad, std::max(x.mx + y.ad, y.mx), std::max(y(x.maxv), y.maxv), std::max(x.maxadd, x.ad + y.maxadd),
		std::max(std::max(x.maxmax, y.maxmax), x.maxv + y.maxadd)};
}
info seg[N << 2];
inline void build(int cur, int l, int r) {
	if(l == r) {
		seg[cur] = (info){ v[l], dp[l], dp[l], std::max(v[l], 0ll), dp[l] };
		return ;
	}
	int mid = (l + r) >> 1;
	build(cur << 1, l, mid);
	build(cur << 1 | 1, mid + 1, r);
	seg[cur] = ins(seg[cur << 1], seg[cur << 1 | 1]);
}
inline void dfs(int ql, int qr, ll & a, ll & b, int cur = 1, int l = 1, int r = n) {
	if(ql <= l && r <= qr) {
		b = std::max(b, a + seg[cur].maxadd);
		b = std::max(b, seg[cur].maxmax);
		a = seg[cur](a);
		return ;
	}
	int mid = (l + r) >> 1;
	if(ql <= mid) dfs(ql, qr, a, b, cur << 1, l, mid);
	if(mid < qr) dfs(ql, qr, a, b, cur << 1 | 1, mid + 1, r);
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n;++i) cin >> a[i];
	for(int i = 1;i <= n;++i) cin >> b[i];
	for(int i = 1;i <= n;++i) cin >> c[i];
	for(int i = 1;i <= n;++i) pa[i] = pa[i - 1] + a[i];
	for(int i = 1;i <= n;++i) pb[i] = pb[i - 1] + b[i];
	for(int i = n;i >= 1;--i) sc[i] = sc[i + 1] + c[i];
	o.resize(q);
	for(int i = 0;i < q;++i) {
		cin >> o[i].l >> o[i].r >> o[i].k;
	}
	std::fill(dp, dp + n + 1, -inf);
	sort(o.begin(), o.end(), cmp0);
	ll ans = -inf;
	for(int i = 1;i <= n;++i) {
		sdp.upt(i, dp[i] - pb[i]);
		spa.upt(i, pa[i] - pb[i - 1]);
	}
	for(const pr & z : o) {
		ll max = -inf;
		max = std::max(sdp.qry(std::max(z.l - 1, 1), z.r), spa.qry(z.l, z.r));
		max += pb[z.r];
		dp[z.r] = std::max(dp[z.r], max - z.k);
		sdp.upt(z.r, dp[z.r] - pb[z.r]);
	}
	for(int i = 1;i <= n;++i) {
		ans = std::max(ans, dp[i] + sc[i]);
		dp[i] += sc[i];
	}
	for(int i = 1;i <= n;++i) v[i] = b[i] - c[i - 1];
	build(1, 1, n);
	for(const pr & z : o) {
		ll w = dp[z.l - 1], a = -inf;
		dfs(z.l, z.r, w, a);
		ans = std::max(ans, a - z.k);
	}
	for(int i = 1;i <= n;++i) dp[i] = pa[i] + b[i] + sc[i];
	build(1, 1, n);
	for(const pr & z : o) {
		ll w = -inf, a = -inf;
		dfs(z.l, z.r, w, a);
		ans = std::max(ans, a - z.k);
	}
	cout << ans << '\n';
}