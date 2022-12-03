#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<int, ll> i_ll;
typedef pair<ll, int> ll_i;
typedef pair<ll, ll> ll_ll;
typedef pair<i_i, ll> P;
const int INF = INT_MAX / 2;
const int MOD = 1e9 + 7;
struct edge { int v, w; };

ll seed;

ll rnd() {
	ll ret = seed;
	seed = (seed * 7 + 13) % MOD;
	return ret;
}

void cut(set<P>& st, int m) {
	auto it = st.upper_bound({{m, INF}, 0});
	it--;
	int l = it->first.first, r = it->first.second;
	ll x = it->second;
	st.erase(it);
	if (l < m) st.insert({{l, m}, x});
	if (m < r) st.insert({{m, r}, x});
}

int pow_mod(ll x, ll n, int M) {
	ll ans = 1;
	for (; n; n>>=1) {
		if (n & 1) ans = ans * x % M;
		x = x * x % M;
	}
	return ans;
}

int main() {
	int N, Q; cin >> N >> Q;
	ll vmax; cin >> seed >> vmax;
	vector<ll> a(N);
	rep(i, N) a[i] = rnd() % vmax + 1;
	vector<int> ops(Q), ls(Q), rs(Q), xs(Q), ys(Q);
	rep(q, Q) {
		ops[q] = rnd() % 4 + 1;
		ls[q] = rnd() % N + 1;
		rs[q] = rnd() % N + 1;
		if (ls[q] > rs[q]) swap(ls[q], rs[q]);
		if (ops[q] == 3) xs[q] = rnd() % (rs[q] - ls[q] + 1) + 1;
		else xs[q] = rnd() % vmax + 1;
		if (ops[q] == 4) ys[q] = rnd() % vmax + 1;
	}
	set<P> st;
	rep(i, N) st.insert({{i, i + 1}, a[i]});
	rep(q, Q) {
		int op = ops[q], l = ls[q] - 1, r = rs[q], x = xs[q], y = ys[q];
		// cout << op << ' ' << l << ' ' << r << ' ' << x << ' ' << y << endl;
		cut(st, l), cut(st, r);
		// for (P p: st) cout << p.first.first << ' ' << p.first.second << ' ' << p.second << endl;
		vector<P> ps;
		auto it = st.lower_bound({{l, -1}, -1});
		while (it != st.end() && it->first.second <= r) {
			ps.pb(*it);
			it++;
		}
		if (op == 1) {
			for (P p: ps) st.erase(p);
			for (P p: ps) {
				p.second += x;
				st.insert(p);
			}
		}
		if (op == 2) {
			for (P p: ps) st.erase(p);
			st.insert({{l, r}, x});
		}
		if (op == 3) {
			vector<ll_i> vs;
			for (P p: ps) vs.pb({p.second, p.first.second - p.first.first});
			sort(vs.begin(), vs.end());
			int rest = x;
			ll ans;
			for (ll_i v: vs) {
				if (rest <= v.second) {
					ans = v.first;
					break;
				}
				rest -= v.second;
			}
			printf("%lld\n", ans);
		}
		if (op == 4) {
			vector<ll_i> vs;
			for (P p: ps) vs.pb({p.second, p.first.second - p.first.first});
			ll ans = 0;
			for (ll_i v: vs)
				ans = (ans + (ll)pow_mod(v.first % y, x, y) % y * v.second) % y;
			printf("%lld\n", (ans + y) % y);
		}
	}
}