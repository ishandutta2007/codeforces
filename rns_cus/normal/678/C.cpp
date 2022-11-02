#include <bits/stdc++.h>
using namespace std;

long long n, a, b, p, q, A, B, AB;

long long lcm(long long a, long long b) {
	return a / __gcd(a, b) * b;
}

int main() {
//	freopen("c.in", "r", stdin);
	cin >> n >> a >> b >> p >> q;
	if (p < q) swap(p, q), swap(a, b);
	A = n / a, B = n / b, AB = n / lcm(a, b);
	cout << A * p + (B - AB) * q << endl;
	return 0;
}