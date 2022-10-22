#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 100200;
typedef long long ll;
int n, q;
ll a[maxn];
const int mod = 998244353;
ll sum[maxn << 2];
ll max[maxn << 2][4];
ll ans[4];
inline void up(int cur) {
	sum[cur] = sum[cur << 1] + sum[cur << 1 | 1];
	for(int i = 0;i < 4;++i) {
		max[cur][i] = std::max(max[cur << 1][i], max[cur << 1 | 1][i]);
	}
}
inline void build(int cur = 1,int l = 1,int r = n) {
	if(l == r) {
		sum[cur] = std::abs(a[l]);
		max[cur][0] = a[l + 1] + a[l] - std::abs(a[l + 1]) - std::abs(a[l]);
		max[cur][1] = -a[l + 1] + a[l] - std::abs(a[l + 1]) - std::abs(a[l]);
		max[cur][2] = a[l + 1] + -a[l] - std::abs(a[l + 1]) - std::abs(a[l]);
		max[cur][3] = -a[l + 1] + -a[l] - std::abs(a[l + 1]) - std::abs(a[l]);
		return ;
	}
	int mid = l + r >> 1;
	build(cur << 1, l, mid);
	build(cur << 1 | 1, mid + 1, r);
	up(cur);
}
inline void mdf(int pos,int cur = 1,int l = 1,int r = n) {
	if(l == r) {
		sum[cur] = std::abs(a[pos]);
		max[cur][0] = a[l + 1] + a[l] - std::abs(a[l + 1]) - std::abs(a[l]);
		max[cur][1] = -a[l + 1] + a[l] - std::abs(a[l + 1]) - std::abs(a[l]);
		max[cur][2] = a[l + 1] + -a[l] - std::abs(a[l + 1]) - std::abs(a[l]);
		max[cur][3] = -a[l + 1] + -a[l] - std::abs(a[l + 1]) - std::abs(a[l]);
		return ;
	}
	int mid = l + r >> 1;
	pos <= mid ? mdf(pos, cur << 1, l, mid) : mdf(pos, cur << 1 | 1, mid + 1, r);
	up(cur);
}
inline void qry(int ql, int qr,int cur = 1,int l = 1,int r = n) {
	if(ql <= l && r <= qr) {
		rep(i, 0, 3) {
			ans[i] = std::max(ans[i], max[cur][i]);
		}
		return ;
	}
	int mid = l + r >> 1;
	if(ql <= mid) qry(ql, qr, cur << 1, l, mid);
	if(mid < qr) qry(ql, qr, cur << 1 | 1, mid + 1, r);
}
inline void add(int l, int r, int v) {
	a[l] += v, mdf(l);
	if(r != n) a[r + 1] -= v, mdf(r + 1);
	mdf(l - 1), mdf(r);
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	rep(i, 1, n) {
		cin >> a[i];
	}
	for(int i = n;i >= 1;--i) {
		a[i] -= a[i - 1];
	}
	build();
	cin >> q;
	rep(i, 1, q) {
		int t, l, r, x;
		cin >> t >> l >> r >> x;
		if(t == 1) {
			ans[0] = ans[1] = ans[2] = ans[3] = -1e18;
			qry(l, r);
			cout << sum[1] - std::abs(a[1]) + std::max({ans[0], ans[1] + x + x, ans[2] - x - x, ans[3]}) << '\n';
		} else {
			add(l, r, x);
		}
	}
}