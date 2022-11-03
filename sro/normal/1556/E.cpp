#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;
const int Inf = 0x3f3f3f3f;

const int maxn = 1 << 17;

struct zkwSeg {
	ll dt[maxn << 1];
	void inline init() { memset(dt, Inf, sizeof(dt)); }
	void inline modify(int a, ll x) {
		dt[a += maxn] = x;
		while (a >>= 1) dt[a] = min(dt[a << 1], dt[a << 1 | 1]);
	}
	ll inline get(int l, int r) {
		ll ans = 1e18;
		for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ans = min(ans, dt[l++]);
			if (r & 1) ans = min(ans, dt[--r]);
		}
		return ans;
	}
} seg;

struct zkwSeg2 {
	ll dt[maxn << 1];
	void inline modify(int a, ll x) {
		dt[a += maxn] = x;
		while (a >>= 1) dt[a] = max(dt[a << 1], dt[a << 1 | 1]);
	}
	ll inline get(int l, int r) {
		ll ans = -1e18;
		for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ans = max(ans, dt[l++]);
			if (r & 1) ans = max(ans, dt[--r]);
		}
		return ans;
	}
} seg2;

int N, Q;
ll a[maxn], b[maxn], c[maxn];

int main() {
	scanf("%d%d", &N, &Q);
	repi(i, N) scanf("%lld", a + i), a[i] += a[i - 1];
	repi(i, N) scanf("%lld", b + i), b[i] += b[i - 1];
	seg.init();
	repi(i, N) c[i] = b[i] - a[i], seg.modify(i, c[i]), seg2.modify(i, c[i]);
	while (Q--) {
		int l, r; scanf("%d%d", &l, &r);
		if (a[r] - a[l - 1] != b[r] - b[l - 1]) {
			puts("-1"); continue;
		}
		ll mx = seg.get(l, r);
		if (mx < c[l - 1]) {
			puts("-1"); continue;
		}
		printf("%lld\n", seg2.get(l, r) - c[l - 1]);
	}
	return 0;
}