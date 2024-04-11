#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void PR(vi &v) { trav(x, v) cout << x << ' '; cout << endl; }

ll gcd(ll a, ll b) { return __gcd(a, b); }

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (b) { ll d = euclid(b, a % b, y, x);
		return y -= a/b * x, d; }
	return x = 1, y = 0, a;
}

template <class Z> Z chinese(Z a, Z m, Z b, Z n) {
	Z x, y; euclid(m, n, x, y);
	Z ret = a * (y + m) % m * n + b * (x + n) % n * m;
	if (ret >= m * n) ret -= m * n;
	return ret;
}

template <class Z> Z chinese_common(Z a, Z m, Z b, Z n) {
	Z d = gcd(m, n);
	if (((b -= a) %= n) < 0) b += n;
	if (b % d) return -1; // No solution
	return d * chinese(Z(0), m/d, b/d, n/d) + a;
}

int main() {
	cin.sync_with_stdio(false);
	int N;
	cin >> N;
	vector<ll> M(N), R(N);
	rep(i,0,N) cin >> M[i];
	rep(i,0,N) cin >> R[i];
	const ll LIM = 1LL << 30;
	double res = 0;
	rep(bs,1,(1 << N)) {
		int cnt = (int)bitset<32>(bs).count();
		ll k = 0;
		ll m = 1;
		rep(i,0,N) {
			if (bs & (1 << i)) {
				// R[i] mod M[i]
				if (M[i] >= LIM) goto fail;
				ll d = gcd(M[i], m);
				ll l = M[i] * m / d;
				if (l >= LIM) goto fail;
				ll k2 = chinese_common(R[i], M[i], k, m);
				if (k2 == -1) goto fail;
				k = k2;
				m = l;
			}
		}
		res += (cnt & 1 ? 1.0 : -1.0) / (double)m;
fail:;
	}
	cout << setprecision(10) << fixed << res << endl;
}