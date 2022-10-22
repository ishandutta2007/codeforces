#include<bits/stdc++.h>
typedef long long ll;
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i) 
const int mod0 = 1e9 + 7;
const int mod1 = 1e9 + 9;
using std::cin;
using std::cout;
const int base0 = 1919810;
const int base1 = 114514;
const int maxn = 200100;
int n, q;
int pw0[maxn];
int pw1[maxn];
char s[maxn];
int h0[maxn], h1[maxn];
int rk[maxn], kth[maxn];;
inline void down(int & x, int y) { if(x > y) { x = y; } }
inline int test(int l0, int r0, int l1, int r1) {
	return
	(h0[r0] + ll(mod0 - pw0[r0 - l0 + 1]) * h0[l0 - 1] - h0[r1] - ll(mod0 - pw0[r1 - l1 + 1]) * h0[l1 - 1]) % mod0 == 0
&&  (h1[r0] + ll(mod1 - pw1[r0 - l0 + 1]) * h1[l0 - 1] - h1[r1] - ll(mod1 - pw1[r1 - l1 + 1]) * h1[l1 - 1]) % mod1 == 0;
}
inline int lcp(int x, int y) {
	int l = 0, r = n - std::max(x, y) + 2;
	for(;l + 1 != r;) {
		int mid = l + r >> 1;
		(test(x, x + mid - 1, y, y + mid - 1) ? l : r) = mid;
	}
	return l;
}
inline int lcs(int x, int y) {
	int l = 0, r = std::min(x, y) + 1;
	for(;l + 1 != r;) {
		int mid = l + r >> 1;
		(test(x - mid + 1, x, y - mid + 1, y) ? l : r) = mid;
	}
	return l;
}
inline int cmp(int x, int y) {
	const int c = lcp(x, y);
	return s[x + c] < s[y + c];
}
inline int calc(int l, int r) {
	for(int i = 1;i < r - l + 1;++i) {
		if(test(l, l + i - 1, r - i + 1, r)) {
			return i;
		}
	}
	return 1e9;
}
inline int border(int l, int r) {
	static const int block = 256;
	static const int dt = n / block;
	for(int i = 1;i <= block && i < r - l + 1;++i) if(test(l, l + i - 1, r - i + 1, r)) return i;
	int min = 1e9;
	rep(i, std::max(1, rk[l] - dt), std::min(n, rk[l] + dt)) {
		const int pos = kth[i];
		if(l < pos && pos <= r) {
			const int len = r - pos + 1;
			if(test(l, l + len - 1, pos, r)) {
				down(min, len);
			}
		}
	}
	return min;
}
std::vector<int> d[maxn];
inline int ask1(int l, int r) {
	const int len = r - l + 1;
	for(int x : d[len]) if(test(l, r - len / x, l + len / x, r)) return 1;
	return 0;
}
int min_suf[maxn], min_pre[maxn];
int cnt[maxn][26];
int right[maxn];
inline int ask(int l, int r) {
	for(int i = 0;i < 26;++i) 
		if(cnt[r][i] - cnt[l - 1][i] >= 2) return 1;
	return 0;
}
inline int ask2(int l, int r) {
	if(min_suf[r] * 2 <= r - l + 1) return 1;
	if(min_pre[l] * 2 <= r - l + 1) return 1;
	int bd = border(l, r);
	if(bd + bd < r - l + 1) return 1;
	return 0;
}
inline int ask3(int l, int r) {
	if(cnt[r][s[l] - 'a'] - cnt[l - 1][s[l] - 'a'] >= 2) return 1;
	if(cnt[r][s[r] - 'a'] - cnt[l - 1][s[r] - 'a'] >= 2) return 1;
	return right[l] <= r;
}
typedef int AI[maxn];
AI st0[20], st1[20];
inline void put(AI * a, int l, int r, int v) {
	if(l <= r) {
		const int lg = std::__lg(r - l + 1);
		down(a[lg][l], v);
		down(a[lg][r - (1 << lg) + 1], v);
	}
}
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	*pw0 = *pw1 = 1;
	for(int i = 1;i < maxn;++i) {
		pw0[i] = (ll) pw0[i - 1] * base0 % mod0;
		pw1[i] = (ll) pw1[i - 1] * base1 % mod1;
	}
	cin >> n;
	cin >> s + 1;
	for(int i = 1;i <= n;++i) {
		h0[i] = ((ll) h0[i - 1] * base0 + s[i]) % mod0;
		h1[i] = ((ll) h1[i - 1] * base1 + s[i]) % mod1;
		kth[i] = i;
		for(int j = 0;j < 26;++j) {
			cnt[i][j] = cnt[i - 1][j];
		}
		cnt[i][s[i] - 'a'] += 1;
	}
	std::stable_sort(kth + 1, kth + n + 1, cmp);
	for(int i = 1;i <= n;++i) {
		rk[kth[i]] = i;
	}
	for(int i = 2;i <= n;++i) if(d[i].empty()) {
		for(int j = i;j <= n;j += i) {
			d[j].push_back(i);
		}
	}
	for(int i = 0;i < 20;++i) {
		for(int j = 1;j + (1 << i) - 1 <= n;++j) {
			st0[i][j] = st1[i][j] = 1e9;
		}
	}
	for(int i = 1;i + i <= n;++i) {
		for(int j = 1;j + i <= n;j += i) {
			const int a0 = j, a1 = j + i;
			if(s[a0] == s[a1]) {
				const int cs = lcs(a0, a1), cp = lcp(a0, a1), L = a0 - cs + 1, R = a1 + cp - 1, len = cs + cp - 1;
				if(len >= i) {
					put(st0, L, L + len - i, i);
					put(st1, R - len + i, R, i);
				}
			}
		}
	}
	for(int i = 19;i >= 1;--i) {
		for(int j = 1;j + (1 << i) - 1 <= n;++j) {
			down(st0[i - 1][j], st0[i][j]), down(st0[i - 1][j + (1 << i - 1)], st0[i][j]);
			down(st1[i - 1][j], st1[i][j]), down(st1[i - 1][j + (1 << i - 1)], st1[i][j]);
		}
	}
	for(int i = 1;i <= n;++i) right[i] = 1e9;
	for(int i = 1;i <= n;++i) {
		min_pre[i] = st0[0][i];
		min_suf[i] = st1[0][i];
		if(min_pre[i] <= n) {
			const int L = i, R = L + min_pre[i] * 2 - 1;
			down(right[L], R);
		}
	}
	for(int i = n - 1;i >= 1;--i) {
		down(right[i], right[i + 1]);
	}
	cin >> q;
	for(int i = 1, l, r;i <= q;++i) {
		cin >> l >> r;
		if(ask(l, r)) {
			if(ask1(l, r)) {
				cout << 1 << '\n';
				continue;
			}
			if(ask2(l, r)) {
				cout << 2 << '\n';
				continue;
			}
			if(ask3(l, r)) {
				cout << 3 << '\n';
				continue;
			}
			cout << 4 << '\n';
		} else {
			cout << -1 << '\n';
		}
	}
}