#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y) {
	int t;
	while (t = x % y) {
		x = y;
		y = t;
	}
	return y;
}

void solve() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	--a;
	--b;
	--c;
	int x, y, z;
	z = pow(10, c);
	if (a == c)
		x = z;
	else
		x = pow(10, a) + z;
	if (b == c)
		y = z;
	else
		y = pow(10, b) + z;
	if (a == b)
		y += z;
	while (gcd(x, y) != z)
		y += z;
	printf("%d %d\n", x, y);
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}