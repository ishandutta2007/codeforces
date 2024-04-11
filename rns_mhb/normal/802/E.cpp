#include <bits/stdc++.h>
using namespace std;

#define N 2020

const int n = 250;

int a[N];

const long long INF = 1ll << 60;

int cnt[N<<1];


int main() {
	//freopen("1.in", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T --) {
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		int tmp;
		//scanf("%d", &tmp);

		long long s = 0, t = 0;
		for (int i = 1; i <= n; i ++) s += a[i], t += a[i] * a[i];

		long double x = 1.0 * s / n;
		x *= x;
		long double y = 1.0 * t / n;
		//cerr << y / x << endl;

		bool type = 0;

		if (y / x > 7.0 / 6.0) type = 1;

		memset(cnt, 0, sizeof cnt);
		int mx = 0;
		for (int i = 1; i <= n; i ++) cnt[a[i]] ++, mx = max(a[i], mx);

		int rlt;

		if (type == 1) {
			double mn = INF;
			for (int ans = ((mx + 1) / 2); ans <= 1000; ans ++) {
				double ave = 1.0 * n / (ans * 2 + 1.0);
				double now = 0;
				for (int i = 0; i <= ans * 2; i ++) now += fabs(ave - cnt[i]);
				if (now < mn) mn = now, rlt = ans;
				else break;
			}
		}
		else {
			rlt = (1.0 * s / n) + 0.5;
		}
		printf("%d\n", rlt);
	}

	return 0;
}