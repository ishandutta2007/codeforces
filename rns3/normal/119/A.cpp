#include <bits/stdc++.h>
using namespace std;

int a, b, n;

int main() {
	scanf("%d %d %d", &a, &b, &n);
	while (1) {
		if (!n) {
			puts("1");
			break;
		}
		n -= __gcd(a, n);
		if (!n) {
			puts("0");
			break;
		}
		n -= __gcd(b, n);
	}
	return 0;
}