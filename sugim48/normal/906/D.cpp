#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<ll, int> ll_i;
struct edge { int v, w, h; };
const int INF = INT_MAX / 10;
const int MOD = 1e9 + 7;

ll pow_mod(ll x, ll n, ll M) {
	ll ans = 1;
	for (; n; n>>=1) {
		if (n & 1) ans = ans * x % M;
		x = x * x % M;
	}
	return ans;
}

ll f(ll x) {
	ll ans = x;
	vector<ll> ps;
	for (ll y = 2; y * y <= x; y++)
		if (x % y == 0) {
			ps.pb(y);
			for (; x % y == 0; x /= y);
		}
	if (x > 1) ps.pb(x);
	for (ll p: ps) ans /= p, ans *= p - 1;
	return ans;
}

ll calc(vector<ll>& a, vector<ll>& Ms, int l, int r, int k) {
	if (l + k == r || k == Ms.size()) return 1;
	int i = l + k;
	if (a[i] == 1) return 1;
	ll x = calc(a, Ms, l, r, k + 1);
	ll M = Ms[k];
	bool pro = false;
	ll y = 1;
	rep(t, x) {
		y *= a[i];
		if (y > 100) {
			pro = true;
			break;
		}
	}
	if (!pro) return y;
	ll res = pow_mod(a[i], x, M);
	if (pro) for (; res < 100; res += M);
	return res;
}

int main() {
	int N; ll M; cin >> N >> M;
	vector<ll> Ms = {M};
	while (Ms.size() < 40) Ms.pb(f(Ms.back()));
	vector<ll> a(N);
	rep(i, N) scanf("%lld", &a[i]);
	int Q; cin >> Q;
	while (Q--) {
		int l, r; scanf("%d%d", &l, &r), l--;
		ll ans = calc(a, Ms, l, r, 0);
		ans = (ans % M + M) % M;
		printf("%lld\n", ans);
	}
	/*
	int ma = 0;
	for (int x = 1000000000; x >= 1; x--) {
		int cnt = 0;
		for (int y = x; y > 1; y = f(y)) cnt++;
		ma = max(ma, cnt);
		if (x % 10000 == 0) cout << x << ' ' << ma << endl;
	}
	*/
}