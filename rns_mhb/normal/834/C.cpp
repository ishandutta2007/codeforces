#include <bits/stdc++.h>
using namespace std;

int runs, a, b, c, d, e;
long long t;

int main() {
	scanf("%d", &runs);
	while (runs --) {
		scanf("%d%d", &a, &b);
		c = pow(1ll * a * b, 0.333333);
		t = 1ll * c * c * c;
		while (t < 1ll * a * b) {
			c ++;
			t = 1ll * c * c * c;
		}
		if (t > 1ll * a * b) puts("No");
		else {
			if (a % c || b % c) puts("No");
			else {
				d = a / c;
				e = b / c;
				if (c % d || c % e) puts("No");
				else puts("Yes");
			}
		}
	}
}