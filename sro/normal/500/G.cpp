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

const int maxn = 200005;
int N;
vector<int> nei[maxn];
int Fa[20][maxn], *fa = Fa[0];
int dep[maxn];

void dfs(int now, int lst) {
	fa[now] = lst;
	cont(i, 19) Fa[i][now] = Fa[i - 1][Fa[i - 1][now]];
	dep[now] = dep[lst] + 1;
	parse(to, nei[now]) if (to != lst) dfs(to, now);
}

int inline lca(int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);
	int toup = dep[a] - dep[b];
	loop(i, 20) if ((toup >> i) & 1) a = Fa[i][a];
	if (a == b) return a;
	range(i, 19, 0, -1) if (Fa[i][a] != Fa[i][b]) a = Fa[i][a], b = Fa[i][b];
	return fa[a];
}

int inline dist(int a, int b) {
	return dep[a] + dep[b] - dep[lca(a, b)] * 2;
}

ll inline gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

void inline exgcd(ll a, ll b, ll &x, ll &y) {
	b ? (exgcd(b, a % b, y, x), y -= a / b * x) : (x = 1, y = 0);
}

ll inline calc_cachup(ll d1, ll d2, ll t1, ll t2) {
	ll c = t2 - t1, g = gcd(d1, d2);
	if (c % g) return INF;
	ll x, y; exgcd(d1, d2, x, y); y = -y;
	x *= c / g; y *= c / g;
	d1 /= g; d2 /= g;
	if (x < 0 || y < 0) {
		int jar = max((-x - 1) / d2 + 1, (-y - 1) / d1 + 1);
		x += jar * d2; y += jar * d1;
	}
	int jan = max(x / d2, y / d1);
	x -= jan * d2; y -= jan * d1;
	return x * g * d1 + t1;
}

ll inline euclid(int a, int b, int l, int r) {
	if (l > r || !b) return INF;
	if ((l - 1) / b != r / b) return (l + b - 1) / b;
	ll res = euclid(b, a % b, (b - r % b) % b, (b - l % b) % b);
	if (res == INF) return INF;
	return (res * a + l + b - 1) / b;
}

ll inline calc_meet(ll d1, ll d2, ll t1, ll t2, ll dis) {
	if ((t1 + t2 + dis) % 2) return INF;
	ll L = ((t2 - t1 - dis) % d2 + d2) % d2, R = ((t2 - t1 + dis) % d2 + d2) % d2;
	ll x = (!L || L > R || 2 * dis == d2) ? 0 : euclid(d2, d1 % d2, L, R);
	if (x == INF) return INF;
	ll y = (x * d1 - (t2 - t1 - dis)) / d2;
	return (x * d1 + y * d2 + t1 + t2 + dis) / 2;
}

ll solve(int a, int b, int x, int y) {
	vector<int> lcas = {lca(a, x), lca(a, y), lca(b, x), lca(b, y)};
	sort(all(lcas), [&] (int a, int b) { return dep[a] > dep[b]; });
	int l1 = lcas[0], l2 = lcas[1];
	if (l1 == l2 && dep[l1] < max(dep[lca(a, b)], dep[lca(x, y)])) return INF;
	ll d1 = dist(a, b) * 2, d2 = dist(x, y) * 2, d = dist(l1, l2);
	ll ad1 = dist(a, l1), ad2 = dist(a, l2);
	if (ad1 > ad2) ad1 = d1 - ad1;
	else ad2 = d1 - ad2;
	ll xd1 = dist(x, l1), xd2 = dist(x, l2);
	if (xd1 > xd2) xd1 = d2 - xd1;
	else xd2 = d2 - xd2;
	return min({
		calc_cachup(d1, d2, ad1, xd1),
		calc_cachup(d1, d2, ad2, xd2),
		calc_meet(d1, d2, ad1, xd2, d),
		calc_meet(d1, d2, ad2, xd1, d)
	});
}

int main() {
	scanf("%d", &N);
	cont(i, N - 1) {
		int u, v; scanf("%d%d", &u, &v);
		nei[u].pub(v); nei[v].pub(u);
	}
	dfs(1, 0);
	int q; scanf("%d", &q);
	while (q--) {
		int a, b, x, y; scanf("%d%d%d%d", &a, &b, &x, &y);
		ll res = solve(a, b, x, y);
		printf("%lld\n", res == INF ? -1 : res);
	}
	return 0;
}