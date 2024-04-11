#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int n, x, y, c, d[5];

inline LL square(int x) {return 1ll * x * x;}

inline LL com(int x) {return 1ll * x * (x + 1) / 2;}

LL calc(int k) {
	LL rlt = 2ll * k * (k + 1) + 1;
	for (int i = 0; i < 4; i ++) rlt -= square(max(0, k - d[i]));
	for (int i = 0; i < 4; i ++) rlt += com(max(0, k - d[i] - d[(i+1)%4] - 1));
	return rlt;
}

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d %d %d %d", &n, &x, &y, &c);
	d[0] = abs(1 - x);
	d[1] = abs(1 - y);
	d[2] = abs(n - x);
	d[3] = abs(n - y);
	int st = -1, en = 2 * n;
	while (en - st > 1) {
		int mid = st + en >> 1;
		if (calc(mid) >= c) en = mid;
		else st = mid;
	}
	printf("%d\n", en);
	return 0;
}