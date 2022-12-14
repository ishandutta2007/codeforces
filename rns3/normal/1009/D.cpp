#include <bits/stdc++.h>

using namespace std;



#define N 101010



int x[N], y[N], e;



void add(int xx, int yy) {

	x[++e] = xx;

	y[e] = yy;

}



int main() {

	//freopen("r.in", "r", stdin);

	int n, m;

	scanf("%d %d", &n, &m);

	if (m < n - 1) {

		puts("Impossible");

		return 0;

	}

	for (int i = 1; i < n; i ++) add(i, i + 1);

	for (int i = 1; i < n && e < m; i ++) for (int j = i + 2; j <= n && e < m; j ++) if (__gcd(i, j) == 1) add(i, j);

	if (e == m) {

		puts("Possible");

		for (int i = 1; i <= e; i ++) printf("%d %d\n", x[i], y[i]);

	}

	else puts("Impossible");



	return 0;

}