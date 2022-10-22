#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;

typedef unsigned long long u64;
typedef double db;
typedef long long ll;
typedef unsigned u32;
typedef std::pair<int, int> pr;
#define fi first
#define se second
const int N = 20000;
const int lim = 4000;
std::vector<pr> ob[N << 2];
int n, p, q;
inline void push(int ql, int qr, pr x, int cur = 1, int l = 1, int r = N) {
	if(ql <= l && r <= qr) {
		return ob[cur].push_back(x);
	}
	int mid = l + r >> 1;
	if(ql <= mid) push(ql, qr, x, cur << 1, l, mid);
	if(mid < qr) push(ql, qr, x, cur << 1 | 1, mid + 1, r);
}
int ans[N + 10];
std::vector<pr> ask[N << 2];
int bak[20][N];
int bag[N];
inline void up(int & x, int y) {
	if(x < y) x = y;
}
inline void push(const pr & x) {
	for(int i = lim;i >= x.fi;--i) {
		up(bag[i], bag[i - x.fi] + x.se);
	}
}
inline void solve(int cur, int l, int r, int d) {
	memcpy(bak[d], bag, lim + 1 << 2);
	for(const auto & x : ob[cur]) {
		push(x);
	}
	if(l == r) {
		for(auto x : ask[l]) {
			ans[x.second] = bag[x.first];
		}
	} else {
		int mid = l + r >> 1;
		solve(cur << 1, l, mid, d + 1);
		solve(cur << 1 | 1, mid + 1, r, d + 1);
	}
	memcpy(bag, bak[d], lim + 1 << 2);
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> p;
	rep(i, 1, n) {
		int c, h, t;
		cin >> c >> h >> t;
		push(t, t + p - 1, pr(c, h));
	}
	cin >> q;
	for(int i = 1, a, b;i <= q;++i) {
		cin >> a >> b;
		ask[a].push_back(pr(b, i));
	}
	solve(1, 1, N, 0);
	rep(i, 1, q) cout << ans[i] << '\n';
}