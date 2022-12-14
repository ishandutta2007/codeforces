#include <bits/stdc++.h>

using namespace std;



long long p, q, b, tmp;

int n;



int main() {

	//freopen("1.in", "r", stdin);

	scanf("%d", &n);

	while (n --) {

		scanf("%I64d %I64d %I64d", &p, &q, &b);

		while (b < 1e9) b = b * b;

		while (1) {

			tmp = __gcd(b, q);

			if (tmp == 1) break;

			q /= tmp;

			b = tmp;

			while (b < 1e9) b = b * b;

		}

		if (p % q == 0) puts("Finite");

		else puts("Infinite");

	}



	return 0;

}