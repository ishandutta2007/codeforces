#include <bits/stdc++.h>

using namespace std;



int x, d;



int e;

long long ans[101010];



void add(long long x) {

	ans[++e] = x;

}



int main() {

	//freopen("r.in", "r", stdin);

	scanf("%d %d", &x, &d);

	long long now = 1, D = 100ll * d;

	int k = (1 << 30) - 1, h = 30;

	while (x) {

		while (x < k) {

			k >>= 1, h --;

		}

		x -= k;

		for (int i = 1; i <= h; i ++) add(now);

		now += D;

	}

	printf("%d\n", e);

	for (int i = 1; i <= e; i ++) printf("%I64d ", ans[i]);

	puts("");





	return 0;

}