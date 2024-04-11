#include <bits/stdc++.h>
using namespace std;

#define N 255

int n, a[N], st, en;
int cnt[10000];

const int K = 5;
const int D = 100;

int main() {
	scanf("%d", &n);
	long long x, y, z;
	while (n --) {
		st = 100000, en = -100000;
		x = 0, y = 0;
        for (int i = 1; i <= 250; i ++) {
			scanf("%d", &a[i]);
			st = min(st, a[i]);
			en = max(en, a[i]);
			x += abs(a[i]);
			y += a[i] * a[i];
        }
        x = x * x;
        y = y * 250;
        double tag = 1.0 * y / x;
        if (st >= -K && en <= K) {
			int pp = max(abs(st), abs(en));
			memset(cnt, 0, sizeof cnt);
			for (int i = 1; i <= n; i ++) cnt[a[i]+D] ++;
			int big = 0, small = 100000;
			for (int i = -pp; i <= pp; i ++) {
				big = max(big, cnt[i+D]);
				small = min(small, cnt[i+D]);
			}
			if (big * 3 <= small * 4) puts("uniform");
			else puts("poisson");
			continue;
		}
        if (tag > 1.14) puts("uniform");
        else puts("poisson");
	}
	return 0;
}