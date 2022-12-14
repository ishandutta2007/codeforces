#include <bits/stdc++.h>

using namespace std;



#define N 202020



int a[N], t[N], T, n;



int id[N];



bool ok(int x) {

	int res = x, tot = 0;

	for (int i = 1; i <= n && res; i ++) if (a[id[i]] >= x) {

		res --;

		tot += t[id[i]];

	}

	return !res && tot <= T;

}



void check(int x) {

	printf("%d\n", x);

	int res = x;

	for (int i = 1; i <= n && res; i ++) if (a[id[i]] >= x) {

		res --;

		printf("%d ", id[i]);

	}

}



bool cmp(int i, int j) {

	return t[i] < t[j];

}



int main() {

	//freopen("r.in", "r", stdin);

	scanf("%d %d", &n, &T);

	for (int i = 1; i <= n; i ++) scanf("%d %d", &a[i], &t[i]), id[i] = i;

	sort(id + 1, id + n + 1, cmp);

	int st = 0, en = n + 1, mid;

	while (st < en - 1) {

		mid = (st + en) >> 1;

		if (ok(mid)) st = mid;

		else en = mid;

	}

	printf("%d\n", st);

	check(st);



	return 0;

}