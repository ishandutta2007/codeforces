#include<bits/stdc++.h>
using std::cin;
using std::cout;
const int N = 100005;
using u16 = unsigned short;

int n, m;
struct pr { u16 l, r; } a[N];

inline bool operator < (const pr & x, const pr & y) { return x.l < y.l; }
inline int cmpr(const pr & x, const pr & y) { return x.r < y.r; }
std::vector<int> id[N];
std::vector<pr> seg[N << 2];
inline void ins(std::vector<pr> & vc, pr x) {
	auto iter = lower_bound(vc.begin(), vc.end(), x);
	if(iter != vc.end() && iter -> r <= x.r) return ;
	auto L = lower_bound(vc.begin(), vc.end(), x, cmpr);
	auto R = upper_bound(vc.begin(), vc.end(), x);
	if(L < R) vc.erase(L, R);
	vc.insert(lower_bound(vc.begin(), vc.end(), x), x);
}
inline bool test(std::vector<pr> & vc, pr x) {
	auto iter = lower_bound(vc.begin(), vc.end(), x);
	return iter != vc.end() && iter -> r <= x.r;
}
inline void ins(int pos, pr x, int cur = 1, int l = 1, int r = m) {
	ins(seg[cur], x);
	if(l == r) return ;
	int mid = (l + r) >> 1;
	pos <= mid ? ins(pos, x, cur << 1, l, mid) : ins(pos, x, cur << 1 | 1, mid + 1, r);
}
inline int find(int p, u16 L, u16 R, int cur = 1, int l = 1, int r = m) {
	if(r < p) return m + 1;
	if(p <= l) {
		if(test(seg[cur], (pr) {L, R})) {
			for(;l != r;) {
				int mid = (l + r) >> 1;
				if(test(seg[cur << 1], (pr) { L, R})) {
					cur <<= 1, r = mid;
				} else {
					l = mid + 1, cur = cur << 1 | 1;
				}
			}
			return l;
		}
		return m + 1;
	}
	int mid = (l + r) >> 1;
	int le = find(p, L, R, cur << 1, l, mid);
	if(le <= m) return le;
	return find(p, L, R, cur << 1 | 1, mid + 1, r);
}
inline int ask(int p, int l, int L, int R) {
	if(R - L + 1 < l) return 0;
	int o = find(p, L, R);
	if(o > m) return 0;
	return ask(o + 1, l, L, a[o].l - 1) + ask(o + 1, l, a[o].r + 1, R) + (a[o].r - a[o].l + 1);
}
int ans[N];
std::vector<pr> o;
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= m;++i) cin >> a[i].l >> a[i].r, id[a[i].r - a[i].l + 1].push_back(i);
	for(int i = n;i >= 1;--i) {
		for(int u : id[i]) {
			ins(u, a[u]);
		}
		ans[i] = ask(1, i, 1, n);
	}
	for(int i = 1;i <= n;++i) {
		cout << ans[i] << '\n';
	}
}