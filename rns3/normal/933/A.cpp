#include <bits/stdc++.h>
using namespace std;

#define N 2020

int n, a[N], s[N];

int one(int st, int en) {
	if (st > en) return 0;
	if (st == 0) return 0;
	return s[en] - s[st-1];
}

int two(int st, int en) {
	return (en - st + 1) - one(st, en);
}

int calc(int le, int ri) {
	int rlt = 0;
	for (int i = le - 1; i <= ri; i ++) {
		rlt = max(rlt, one(le, i) + two(i + 1, ri));
	}
	return rlt;
}

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i ++) {
		s[i] = s[i-1];
		if (a[i] == 1) s[i] ++;
	}
	int tot = a[n], ans = 0;
	ans = calc(1, n);
	for (int i = 1; i < n; i ++) ans = max(ans, calc(1, i) + calc(i + 1, n));
	printf("%d\n", ans);

	return 0;
}