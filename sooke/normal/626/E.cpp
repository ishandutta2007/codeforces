#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long lol;
typedef long double lod;

inline char readLetter() {
	char c = getchar();
	while ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z')) { c = getchar(); }
	return c;
}
inline int read() {
	char c = getchar(); int n = 0, f = 0;
	while (c < '0' || c > '9') { if (c == '-') { f = 1; } c = getchar(); }
	while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
	return f ? -n : n;
}

const lol maxLongLong = 9223372036854775807ll;
const int maxN = 200005;

int n;
lol a[maxN], sum[maxN];

struct Scheme {
	int pos, len;
	
	inline lol calc() { return sum[pos] - sum[pos - len - 1] + sum[n] - sum[n - len]; }
} ans;
bool operator <(Scheme x, Scheme y) {
	return (x.calc() - a[x.pos] * (x.len << 1 | 1)) * (y.len << 1 | 1) < (y.calc() - a[y.pos] * (y.len << 1 | 1)) * (x.len << 1 | 1);
}

int main() {
	n = read();
	for (int i = 1; i <= n; i++) { a[i] = read(); }
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) { sum[i] = sum[i - 1] + a[i]; }
	ans.pos = 1, ans.len = 0;
	for (int i = 1, mid = 0; i <= n; i++, mid = 0) {
		for (int l = 1, r = std::min(i - 1, n - i), lmid, rmid; l <= r; ) {
			lmid = l + (r - l) / 3, rmid = r - (r - l) / 3;
			Scheme ls = (Scheme) {i, lmid}, rs = (Scheme) {i, rmid};
			if (ls < rs) { l = lmid + 1, mid = lmid; }
			else { r = rmid - 1, mid = rmid; }
		}
		ans = std::max(ans, (Scheme) {i, mid});
	}
	printf("%d\n", ans.len * 2 + 1);
	for (int i = ans.pos - ans.len; i <= ans.pos; i++) { printf("%lld ", a[i]); }
	for (int i = n - ans.len + 1; i <= n; i++) { printf("%lld ", a[i]); }
	return 0;
}

// By Sooke.
// CF626E Simple Skewness.