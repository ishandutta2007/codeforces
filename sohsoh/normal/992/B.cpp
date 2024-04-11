#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

ll l, r, x, y;

inline bool check(int a, int b) {
	return a >= l && a <= r && b >= l && b <= r && __gcd(a, b) == 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> l >> r >> x >> y;

	if (y % x) return cout << 0 << endl, 0;
	y /= x;

	l = (l + x - 1) / x;
	r = r / x;

	if (l > r) return cout << 0 << endl, 0;

	ll ans = 0;
	for (int i = 1; i * i <= y; i++) {
		if (y % i == 0) {
			ans += check(i, y / i);
			if (y / i != i) ans += check(y / i, i);
		}
	}

	cout << ans << endl;
	return 0;
}