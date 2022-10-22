#include<bits/stdc++.h>
const int maxn = 100100;
using std::cin;
using std::cout;
typedef long long ll;
const int mod = 1e9 + 7;
ll out;
int n, a[maxn];

int pre[maxn], nxt[maxn];

ll sa[maxn << 2], sb[maxn << 2];

inline ll sum(int l, int r) { return (l + r) * (r - l + 1ll) >> 1; }

int maxa[maxn << 2], maxb[maxn << 2];
int mina[maxn << 2], minb[maxn << 2];
int taga[maxn << 2], tagb[maxn << 2];
ll s0[maxn << 2], s1[maxn << 2], s2[maxn << 2], s3[maxn << 2];
// s : ai, bi, ai * bi, ai * i
inline void puta(int cur, int v, int l, int r) {
	taga[cur] = maxa[cur] = mina[cur] = v;
	s0[cur] = (ll) v * (r - l + 1);
	s2[cur] = (ll) s1[cur] * v;
	s3[cur] = v * sum(l, r);
}
inline void putb(int cur, int v, int l, int r) {
	tagb[cur] = maxb[cur] = minb[cur] = v;
	s1[cur] = (ll) v * (r - l + 1);
	s2[cur] = (ll) s0[cur] * v;
}
inline void pushdown(int cur, int l, int r) {
	int mid = l + r >> 1;
	if(taga[cur] != -1) {
		puta(cur << 1, taga[cur], l, mid);
		puta(cur << 1 | 1, taga[cur], mid + 1, r);
		taga[cur] = -1;
	}
	if(tagb[cur] != -1) {
		putb(cur << 1, tagb[cur], l, mid);
		putb(cur << 1 | 1, tagb[cur], mid + 1, r);
		tagb[cur] = -1;
	}
}
inline void update(int cur) {
	maxa[cur] = std::max(maxa[cur << 1], maxa[cur << 1 | 1]);
	maxb[cur] = std::max(maxb[cur << 1], maxb[cur << 1 | 1]);
	mina[cur] = std::min(mina[cur << 1], mina[cur << 1 | 1]);
	minb[cur] = std::min(minb[cur << 1], minb[cur << 1 | 1]);
	s0[cur] = s0[cur << 1] + s0[cur << 1 | 1];
	s1[cur] = s1[cur << 1] + s1[cur << 1 | 1];
	s2[cur] = s2[cur << 1] + s2[cur << 1 | 1];
	s3[cur] = s3[cur << 1] + s3[cur << 1 | 1];
}

inline void upt(int cur, int v0, int v1, int ql, int qr, int l = 1, int r = n) {
	int mid = l + r >> 1;
	if(mina[cur] < v0 && v0 < maxa[cur] || minb[cur] < v1 && v1 < maxb[cur] || l < ql || r > qr) {
		pushdown(cur, l, r);
		if(ql <= mid) upt(cur << 1, v0, v1, ql, qr, l, mid);
		if(mid < qr) upt(cur << 1 | 1, v0, v1, ql, qr, mid + 1, r);
		update(cur);
	} else {
		if(v0 >= maxa[cur]) puta(cur, v0, l, r);
		if(v1 <= minb[cur]) putb(cur, v1, l, r);
	}
}

inline ll ask(ll * s, int ql, int qr, int cur = 1, int l = 1, int r = n) {
	if(ql <= l && r <= qr) return s[cur];
	int mid = l + r >> 1; ll ans = 0;
	pushdown(cur, l, r);
	if(ql <= mid) ans += ask(s, ql, qr, cur << 1, l, mid);
	if(mid < qr) ans += ask(s, ql, qr, cur << 1 | 1, mid + 1, r);
	return ans;
}

int min[20][maxn];
int max[20][maxn];

inline int gmin(int l, int r) {
	const int lg = std::__lg(r - l + 1);
	return std::min(min[lg][l], min[lg][r - (1 << lg) + 1]);
}
inline int gmax(int l, int r) {
	const int lg = std::__lg(r - l + 1);
	return std::max(max[lg][l], max[lg][r - (1 << lg) + 1]);
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;++i) {
		cin >> a[i];
	}
	std::map<int, int> map;
	for(int i = 1;i <= n;++i) {
		pre[i] = map[a[i]] + 1;
		map[a[i]] = i;
	}
	for(auto & i : map) i.second = n + 1;
	for(int i = n;i >= 1;--i) {
		nxt[i] = map[a[i]] - 1;
		map[a[i]] = i;
	}
	for(int i = 1;i <= n;++i) {
		min[0][i] = nxt[i];
		max[0][i] = pre[i];
	}
	for(int i = 1;i < 20;++i) {
		for(int j = 1;j + (1 << i) - 1 <= n;++j) {
			min[i][j] = std::min(min[i - 1][j], min[i - 1][j + (1 << i - 1)]);
			max[i][j] = std::max(max[i - 1][j], max[i - 1][j + (1 << i - 1)]);
		}
	}
	puta(1, -1e9, 1, n);
	putb(1, 1e9, 1, n);
	for(int i = n;i >= 1;--i) {
		ll ans = 0;
		int can_first = 1, can_last = n;
		int l = i, r = n + 1;
		for(;l + 1 != r;) {
			int mid = l + r >> 1;
			if(gmax(i, mid) < i && gmin(i, mid) > mid) {
				l = mid;
			} else {
				r = mid;
			}
		}
		upt(1, pre[i], nxt[i], i, n);
		out = (out + ask(s3, i, l) + i * ask(s1, i, l) - ask(s2, i, l) - i * sum(i, l)) % mod;
	}
	cout << int(out) << '\n';
}