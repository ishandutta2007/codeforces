#include <bits/stdc++.h>

using namespace std;



#define N 1010



int w[N][N], n, a, b;



int main() {

	//freopen("r.in", "r", stdin);

	scanf("%d %d %d", &n, &a, &b);

	if (n == 1) {

		if (a == 1 && b == 1) {

			puts("YES");

			puts("0");

		}

		else puts("NO");

		return 0;

	}

	if (a != 1 && b != 1) {

		puts("NO");

		return 0;

	}

	if (a == 1 && b == 1) {

		if (n <= 3) {

			puts("NO");

		}

		else {

			puts("YES");

			for (int i = 1; i <= n; i ++) {

				for (int j = 1; j <= n; j ++) printf("%d", (abs(i - j) == 1) ? 1 : 0);

				puts("");

			}

		}

		return 0;

	}

	puts("YES");

	int flag = 1;

	if (b == 1) flag = 0;

	a = max(a, b);

	for (int i = 1; i <= n; i ++) {

		for (int j = 1; j <= n; j ++) {

			if (i == j) printf("0");

			else printf("%d", flag ^ ((i >= a && j >= a) ? 1 : 0));

		}

		puts("");

	}





	return 0;

}