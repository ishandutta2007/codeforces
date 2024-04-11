#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
typedef long long ll;
const int mod = 998244353;
const int base = 233;
const int B = 100;
int pw[maxn];
int n, m, q;
struct String {
	int h[maxn], N;
	inline void init(const char * s) {
		N = strlen(s + 1);
		for(int i = 1;i <= N;++i) {
			h[i] = ((ll) h[i - 1] * base + s[i]) % mod;
		}
	}
	inline int sub(int l, int r) {
		return (h[r] + (ll) (mod - h[l - 1]) * pw[r - l + 1]) % mod;
	}
} S, T;
char s[maxn], t[maxn];
struct str {
	int pos;
	inline int sub(int x) const {
		if(x <= pos) return S.h[x];
		if(x <= pos + m) return ((ll) S.h[pos] * pw[x - pos] + T.h[x - pos]) % mod;
		return ((ll) S.h[pos] * pw[x - pos] + (ll) T.h[m] * pw[x - pos - m] + S.sub(pos + 1, x - m)) % mod;
	}
	inline int get(int x) const {
		if(x <= pos) return s[x];
		if(x <= pos + m) return t[x - pos];
		return s[x - m];
	}
};
inline int lcp(const str & s0, const str & s1) {
	int l = 0, r = n + m + 1;
	for(;l + 1 != r;) {
		int mid = l + r >> 1;
		if(s0.sub(mid) == s1.sub(mid)) {
			l = mid;
		} else {
			r = mid;
		}
	}
	return l;
}
inline int cmp0(int x, int y) {
	const str X = {x}, Y = {y};
	int len = lcp(X, Y);
	return X.get(len + 1) < Y.get(len + 1);
}
int rk[maxn], val[maxn];
int st[20][maxn];
inline void init(int len) {
	for(int i = 1;i < 20;++i) {
		for(int j = 0;j + (1 << i) - 1 <= len;++j) {
			st[i][j] = std::min(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
		}
	}
}
inline int getmin(int ql, int qr) {
	const int lg = std::__lg(qr - ql + 1);
	return std::min(st[lg][ql], st[lg][qr - (1 << lg) + 1]);
}
int ans[maxn];
struct Q { int id, l, r, x, y; };
inline void down(int & x, int y) {
	if(x > y) {
		x = y;
	}
}
std::vector<Q> pr[maxn];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	*pw = 1;
	for(int i = 1;i < maxn;++i) {
		pw[i] = (ll) pw[i - 1] * base % mod;
	}
	cin >> s + 1 >> t + 1 >> q;
	n = strlen(s + 1), m = strlen(t + 1);
	S.init(s), T.init(t);
	rep(i, 0, n) {
		rk[i] = i;
	}
	std::stable_sort(rk, rk + n + 1, cmp0);
	rep(i, 0, n) {
		st[0][rk[i]] = val[rk[i]] = i;
	}
	init(n);
	rep(i, 1, q) {
		int l, r, mod, x, y;
		cin >> l >> r >> mod >> x >> y;
		int & ans = ::ans[i] = 1e9;
		if(mod > B) {
			for(int i = x, j = y;i <= n;i += mod, j += mod) {
				if(l <= j && i <= r) {
					down(ans, getmin(std::max(i, l), std::min(j, r)));
				}
			}
		} else {
			pr[mod].push_back({i, l, r, x, y});
		}
	}
	rep(i, 1, B) {
		for(int j = 0;j < B;++j) {
			int N = 0;
			for(int k = j;k <= n;k += i) {
				st[0][N] = val[k];
				++ N;
			}
			if(N) {
				init(N - 1);
				for(const Q & x : pr[i]) if(x.x <= j && j <= x.y) {
					const int L = (x.l - j + i - 1) / i, R = (x.r - j + i) / i - 1;
					if(L <= R) down(ans[x.id], getmin(L, R));
				}
			}
		}
	}
	rep(i, 1, q) {
		if(ans[i] > n) {
			cout << -1 << ' ';
		} else {
			cout << rk[ans[i]] << ' ';
		}
	}
}