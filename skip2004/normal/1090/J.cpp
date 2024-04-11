#include<bits/stdc++.h>
const int mod = 1423813747;
const int base = 114514;
typedef long long ll;
const int maxn = 100100;
using std::cin;
using std::cout;
int pw[maxn];
struct Hash_string {
	int val[maxn], len;
	inline void init(const char * ch) {
		len = strlen(ch + 1);
		for(int i = 1;i <= len;++i) {
			val[i] = ((ll) val[i - 1] * base + ch[i]) % mod;
		}
	}
	inline int sub(int l, int r) const {
		return (val[r] + ll(mod - val[l - 1]) * pw[r - l + 1]) % mod;
	}
} S, T;
char s[maxn], t[maxn];
inline int lcp(const Hash_string & s, int p0, const Hash_string & t, int p1) {
	int l = 0, r = std::min(s.len - p0 + 1, t.len - p1 + 1) + 1;
	for(;l + 1 != r;) {
		int mid = l + r >> 1;
		if(s.sub(p0, p0 + mid - 1) == t.sub(p1, p1 + mid - 1)) {
			l = mid;
		} else {
			r = mid;
		}
	}
	return l;
}
int rk[maxn];
inline int gch(int pos, int p) {
	return p <= pos ? s[p] : t[p - pos];
}
inline int lcp(int x, int y) {
	if(x > y) std::swap(x, y);
	return S.sub(x + 1, y) == T.sub(1, y - x) ? y + lcp(T, 1, T, y - x + 1) : x + lcp(T, 1, S, x + 1);
}
inline int cmp0(const int & x, const int & y) {
	int L = lcp(x, y);
	return gch(x, L + 1) < gch(y, L + 1);
}
int ok[maxn];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	*pw = 1;
	for(int i = 1;i < maxn;++i) {
		pw[i] = (ll) pw[i - 1] * base % mod;
	}
	cin >> s + 1 >> t + 1;
	int n = strlen(s + 1), m = strlen(t + 1);
	S.init(s);
	T.init(t);
	ll ans = 0;
	for(int i = 1;i <= n;++i) {
		rk[i] = i;
		ans += i + m;
	}
	std::stable_sort(rk + 1, rk + n + 1, cmp0);
	for(int i = 1;i < n;++i) {
		ans -= lcp(rk[i], rk[i + 1]);
	}
	for(int i = 2;i <= n;++i) {
		ok[i] += 1;
		ok[i + lcp(S, i, T, 1)] -= 1;
	}
	for(int i = 1;i <= n;++i) {
		ok[i] += ok[i - 1];
		ans -= !ok[i];
	}
	cout << ans << '\n';

}