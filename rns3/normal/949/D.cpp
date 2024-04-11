#include <bits/stdc++.h>
using namespace std;

#define N 101010

long long s[N], t[N];
int a[N], b[N];

int n, d, B;

bool ok(int k) {//printf("	%d\n", k);
	long long cur = 0;
	int j = 1;
	int bad = 0;
	for (int i = 1; i <= (n + 1) / 2; i ++) {
		cur += B;
		int j = lower_bound(s + 1, s + n + 1, cur) - s;
		if (j - i > 1ll * d * i) bad ++, cur -= B;
	}//printf("%d\n", bad);

	if (bad > k) return 0;

	bad = 0;
	cur = 0;

	for (int i = 1; i <= (n + 1) / 2; i ++) {
		cur += B;
		int j = lower_bound(t + 1, t + n + 1, cur) - t;
		if (j - i > 1ll * d * i) bad ++, cur -= B;
	}//printf("%d\n", bad);

	if (bad > k) return 0;
	return 1;
}

void prep() {
	for (int i = 1; i <= n; i ++) s[i] = s[i-1] + a[i];
	for (int i = 1; i <= n; i ++) t[i] = t[i-1] + b[i];
}

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d %d %d", &n, &d, &B);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), b[n+1-i] = a[i];
	prep();
	int st = (n + 1) / 2, en = -1, mid;
	while (st > en + 1) {
		mid = (st + en + 1) >> 1;
		if (ok(mid)) st = mid;
		else en = mid;
	}
	printf("%d\n", st);

	return 0;
}