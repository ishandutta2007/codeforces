#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long quickpow(long long a, long long b) {
	long long res = 1;
	a %= mod;
	while (b) {
		if (b & 1)
			res = res * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}

long long inv(long long n) {
	return quickpow(n, mod - 2);
}

int dx = 1, dy = 1, mx, my, idx, idy;

class P {
public:
	int x, y;

	bool operator!=(P &o) const {
		if (x + dx > mx || x + dx < 1) dx = -dx;
		if (y + dy > my || y + dy < 1) dy = -dy;
		return x != o.x || y != o.y || dx != idx || dy != idy;
	}

	bool operator-(P &o) const {
		return x == o.x || y == o.y;
	}

	void operator++() {
		if (x + dx > mx || x + dx < 1) dx = -dx;
		if (y + dy > my || y + dy < 1) dy = -dy;
		x += dx;
		y += dy;
	}
};

void redirect(P &p) {
	if (p.x + dx > mx || p.x + dx < 1) dx = -dx;
	if (p.y + dy > my || p.y + dy < 1) dy = -dy;
}

istream &operator>>(istream &i, P &p) {
	i >> p.x >> p.y;
	return i;
}

void solve() {
	cin >> mx >> my;
	P a{}, b{};
	cin >> a >> b;
	dx = 1;
	dy = 1;
	redirect(a);
	idx = dx;
	idy = dy;
	long long p;
	cin >> p;
	long long c = 0, k = 1, p1 = (1 - p * inv(100) % mod + mod) % mod;
	P cur = a;
	do {
		if (cur - b) {
			k *= p1;
			k %= mod;
		}
		c += k;
		c %= mod;
		++cur;
	} while (cur != a);
	k = (1 - k + mod) % mod;
	cout << c * inv(k) % mod << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}