#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

ll ax, ay, bx, by, cx, cy;

int move[4][2][2] = {{{1,0},{0,1}}, {{0,1}, {-1,0}}, {{-1,0}, {0, -1}}, {{0,-1},{1,0}}};

ll ABS(ll n) {
	return n > 0 ? n : -n;
}

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}


ll solve(ll x, ll y, ll m) {
	if (y == 0) return m / x;
	ll A = solve(y, x % y, m);
	ll B = (m - A * x) / y;
	return B % x;
}

bool poss(ll m, ll n, ll x, ll y) {
	ll k = gcd(ABS(x), ABS(y));
	if (k == 0) {
		return m == 0 && n == 0;
	}

	if (m % k || n % k) return false;
	m /= k;
	n /= k;
	x /= k;
	y /= k;

	if (x == 0 || y == 0) return true;

	ll B = solve(x, y, m);
	ll A = (m - B * y) / x;
	ll cur = A * y - B * x;
	ll diff = cur - n;
	return diff % (x * x + y * y) == 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> ax >> ay >> bx >> by >> cx >> cy;

	bool ans = false;
	for(int i = 0; i < 4; ++i) {
		ll x = bx - (ax * move[i][0][0] + ay * move[i][1][0]);
		ll y = by - (ax * move[i][0][1] + ay * move[i][1][1]);
		if (poss(x, y, cx, cy)) {
			ans = true;
			break;
		}
	}

	if (ans) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}