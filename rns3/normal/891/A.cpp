#include <bits/stdc++.h>

using namespace std;



#define N 2020



int n, a[N];



bool ok(int x) {

	for (int le = 1, ri = x; ri <= n; le ++, ri ++) {

		int now = a[le];

		for (int i = le + 1; i <= ri; i ++) now = __gcd(now, a[i]);

		if (now == 1) return 1;

	}

	return 0;

}



int main() {

	//freopen("r.in", "r", stdin);

	scanf("%d", &n);

	int cnt = 0;

	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), cnt += (a[i] == 1);

	int all = a[1];

	for (int i = 2; i <= n; i ++) all = __gcd(all, a[i]);

	if (all != 1) {

		puts("-1");

		return 0;

	}

	if (cnt) {

		printf("%d\n", n - cnt);

		return 0;

	}

	int st = 1, en = n + 1;

	while (st < en - 1) {

		int mid = (st + en + 1) >> 1;

		if (ok(mid)) en = mid;

		else st = mid;

	}

	printf("%d\n", en + n - 2);



	return 0;

}