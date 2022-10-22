#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;

typedef unsigned long long u64;
typedef double db;
typedef long long ll;
typedef unsigned u32;

const int N = 200200;
const ll inf = 1e18;
int n, m;
int d[N], h[N];
int cnt[N];
ll s[N];

inline void up(ll&a, ll b) { if(a < b) a = b; }

ll a[N], b[N];

ll max0[N << 2], max1[N << 2], ans[N << 2];

inline void update(int x) {
	max0[x] = std::max(max0[x << 1], max0[x << 1 | 1]);
	max1[x] = std::max(max1[x << 1], max1[x << 1 | 1]);
	ans[x] = std::max(ans[x << 1], ans[x << 1 | 1]);
	up(ans[x], max0[x << 1] + max1[x << 1 | 1]);
}
inline void build(int cur, int l, int r) {
	if(l == r) {
		max0[cur] = a[l];
		max1[cur] = b[l];
		ans[cur] = -inf;
		return ;
	}
	int mid = l + r >> 1;
	build(cur << 1, l, mid);
	build(cur << 1 | 1, mid + 1, r);
	update(cur);
}
ll max, res;

inline void ask(int ql, int qr, int cur, int l = 1, int r = n + n) {
	if(ql <= l && r <= qr) {
		up(res, ans[cur]);
		up(res, max + max1[cur]);
		up(max, max0[cur]);
		return ;
	}
	int mid = l + r >> 1;
	if(ql <= mid) ask(ql, qr, cur << 1, l, mid);
	if(mid < qr) ask(ql, qr, cur << 1 | 1, mid + 1, r);
}
inline ll ask(int l, int r) {
	max = -inf, res = 0;
	ask(l, r, 1);
	return res;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;++i) cin >> d[i];
	for(int i = 1;i <= n;++i) cin >> h[i];
	for(int i = 1;i <= n;++i) {
		d[i + n] = d[i];
		h[i + n] = h[i];
	}
	for(int i = 1;i <= n + n;++i) {
		s[i + 1] = s[i] + d[i];
	}
	for(int i = 1;i <= n + n;++i) {
		h[i] <<= 1;
		a[i] = h[i] - s[i];
		b[i] = h[i] + s[i];
	}
	build(1, 1, n + n);
	for(int i = 1, l, r;i <= m;++i) {
		cin >> l >> r;
		if(l <= r) {
			cout << ask(r + 1, l + n - 1) << '\n';
		} else {
			cout << ask(r + 1, l - 1) << '\n';
		}
	}
}