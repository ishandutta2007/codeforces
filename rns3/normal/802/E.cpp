#include <bits/stdc++.h>
using namespace std;

#define N 255

int n, a[N];
int cnt[2010];

int main() {
	scanf("%d", &n);
	long long x, y, z, pop;
	int ma;
	while (n --) {
		ma = 0;
		memset(cnt, 0, sizeof cnt);
		x = 0, y = 0;
        for (int i = 1; i <= 250; i ++) {
			scanf("%d", &a[i]);
			ma = max(ma, a[i]);
			if (a[i] <= 2000) cnt[a[i]] ++;
			x += a[i];
			y += a[i] * a[i];
        }
        pop = 1.0 * x / 250 + 0.5;
        x = x * x;
        y = y * 250;
        double tag = 1.0 * y / x;
        if (tag > 1.142857) {
        	double old = 10000000.0, now;
        	int pp;
			for (int p = ma / 2; p <= 2000; p ++) {
				now = 0;
				for (int i = 0; i <= p * 2; i ++) {
					now += fabs(cnt[i] - 250.0 / (2 * p + 1));
				}
				if (old > now) pp = p, old = now;
				else break;
			}
			printf("%d\n", pp);
        }
        else {
			//pop = sqrt(1.0 * y) / 250 + 0.5;
			printf("%I64d\n", pop);
        }
	}
	return 0;
}