#include<bits/stdc++.h>
using std::cin;
using std::cout;
typedef long long ll;
const int maxn = 1001000;
const int Mod = 2147483647; 
const int mod = 998244353;
const int base = 1919810;
int pw[maxn];
char a[maxn], l[maxn], r[maxn];
int dp[maxn];
int lena, lenl, lenr;
inline void reduce(int &x) {
	x += x >> 31 & mod;
}
struct hash {
	int h[maxn], L;
	const char * s;
	inline void init(const char * s) {
		this -> s = s, L = strlen(s + 1);
		for(int i = 1;i <= L;++i) h[i] = ((ll) h[i - 1] * base + s[i]) % Mod;
	}
	inline int sub(int l, int r) const { return (h[r] + ll(Mod - h[l - 1]) * pw[r - l + 1]) % Mod; }
} L, R, A;

inline int lcp(const hash&a, int p0, const hash&b, int p1) {
	int l = 0, r = std::min(a.L - p0, b.L - p1) + 2;
	for(;l + 1 != r;) {
		int mid = l + r >> 1;
		(a.sub(p0, p0 + mid - 1) == b.sub(p1, p1 + mid - 1) ? l : r) = mid;
	}
	return l;
}

inline int bound(int i, hash & b, int flag) {
	const int R = i + b.L - 1, lcp = :: lcp(A, i, b, 1);
	if(R > lena) return lena;
	if(flag) {
		if(lcp == b.L || A.s[i + lcp] > b.s[lcp + 1]) return i + b.L - 2;
		return i + b.L - 1;
	} else {
		if(lcp < b.L && A.s[i + lcp] > b.s[lcp + 1]) return i + b.L - 2;
		return i + b.L - 1;
	}
}

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> a + 1 >> l + 1 >> r + 1;
	lena = strlen(a + 1);
	lenl = strlen(l + 1);
	lenr = strlen(r + 1);
	*pw = 1;
	L.init(l), R.init(r), A.init(a);
	for(int i = 1;i < maxn;++i) pw[i] = (ll) pw[i - 1] * base % Mod;
	dp[0] = 1, dp[1] = mod - 1;

	for(int i = 1;i <= lena;++i) {
		reduce(dp[i] += dp[i - 1] - mod);
		if(a[i] != '0') {
			int li = bound(i, L, 1);
			int ri = bound(i, R, 0);
			reduce(dp[li + 1] += dp[i - 1] - mod);
			reduce(dp[ri + 1] -= dp[i - 1]);
		} else {
			if(lenl == 1 && l[1] == '0') reduce(dp[i] += dp[i - 1] - mod), reduce(dp[i + 1] -= dp[i - 1]);
		}
	}

	cout << dp[lena] << '\n';
}