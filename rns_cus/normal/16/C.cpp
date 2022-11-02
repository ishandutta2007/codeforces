#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, y, a, b;
	scanf("%d %d %d %d", &x, &y, &a, &b);
int d = __gcd(a, b); a /= d, b /= d;
	d = min(x / a, y / b);
	printf("%d %d\n", a * d, b * d);
	return 0;
}