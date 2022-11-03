#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define parse(it, x) for (auto &it : (x))
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

int n, m, g, ng, mg;
ll k, x, y, cyc;
int *a = new int[500005], *b = new int[500005];
int *p = new int[1000005], *q = new int[1000005];

int inline gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
void inline exgcd(int a, int b, ll &x, ll &y) {
	b ? (exgcd(b, a % b, y, x), y -= a / b * x) : (x = 1, y = 0);
}

bool check(ll d) {
	ll dst = d - k, res = 0;
	if (dst < 0) return 0;
	cont(i, max(n, m) * 2) {
		if (!p[i] || !q[i]) continue;
		if (p[i] % g != q[i] % g) continue;
		int P = p[i] / g, Q = q[i] / g;
		ll nd = d - q[i];
		if (nd < 0) continue;
		ll xx = x * (P - Q + ng) % ng;
		res += nd / cyc;
		if (nd % cyc >= xx * m) ++res;
	}
	return res <= dst;
}

signed main() {
	scanf("%d%d%lld", &n, &m, &k); g = gcd(n, m);
	cont(i, max(n, m) * 2) p[i] = q[i] = 0;
	cont(i, n) scanf("%d", a + i), p[a[i]] = i;
	cont(i, m) scanf("%d", b + i), q[b[i]] = i;
	if (n < m) {
		swap(a, b);
		swap(p, q);
		swap(n, m);
	}
	ng = n / g, mg = m / g;
	exgcd(mg, ng, x, y);
	x %= ng; if (x < 0) x += ng;
	cyc = 1ll * n / g * m;
	ll l = 0, r = 1e18;
	while (r - l > 1) {
		ll m = (l + r) >> 1;
		if (check(m)) r = m;
		else l = m;
	}
	printf("%lld\n", r);
	return 0;
}