#include <cstdio>

using namespace std;

typedef long long ll;

ll solve(ll A, ll B, ll C) { // finds y
	if (B == 0) {
		return 0;
	}
	ll N = A % B;
	ll X = solve(B, N, C);
	ll Y = (-C - A * X) / B;
	if (A != 0) {
		Y %= A;
	}
	return Y;
}

int abs(int a) {
	return a > 0 ? a : -a;
}

int _gcd(int a, int b) {
	if (b == 0) return a;
	return _gcd(b, a % b);
}

int A, B, C;

int main() {
	scanf("%d %d %d", &A, &B, &C);
	int gcd = _gcd(abs(A), abs(B));
	if (C % gcd == 0) {
		ll Y = solve(A, B, C);
		ll X = 0;
		if (A != 0) {
			X = (-B * Y - C) / A;
		}
		printf("%I64d %I64d\n", X, Y);
	} else {
		printf("-1\n");
	}
	return 0;
}