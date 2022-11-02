#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios :: sync_with_stdio(false);
	ll n, a, b, p, q;
	cin >> n >> a >> b >> p >> q;
	ll lcm = a / __gcd(a, b) * b;
	ll either = n / lcm;
	ll red = n / a - either;
	ll blue = n / b - either;
	cout << red * p + blue * q + either * max(p, q) << '\n';
	return 0;
}