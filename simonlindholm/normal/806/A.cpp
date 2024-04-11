#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll solve() {
	ll X, Y, P, Q;
	cin >> X >> Y >> P >> Q;
	if (P == 0 && X != 0) return -1;
	if (P == Q && X != Y) return -1;
	ll g = __gcd(P,	Q);
	P /= g;
	Q /= g;
	auto works = [&](ll k) {
		ll p = P * k;
		ll q = Q * k;
		if (q < Y) return false;
		if (p < X) return false;
		return p - X <= q - Y;
	};
	ll lo = 0, hi = 1;
	while (!works(hi)) hi *= 2;
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		if (works(mid)) hi = mid;
		else lo = mid;
	}
	return Q * hi - Y;
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int T;
	cin >> T;
	rep(i,0,T) {
		cout << solve() << endl;
	}
	exit(0);
}