#include <bits/stdc++.h>

using namespace std;

int ask(int x) {
	printf("%d\n", x);
	fflush(stdout);
	int r;
	scanf("%d", &r);
	return r;
}

int pre[30];
int bit[30];
int qps[30];

void solve() {
	int n, k;
	scanf("%d%d", &n, &k);
	memset(qps, 0, sizeof qps);
	qps[0] = 1;
	for (int i = 1; i < 30; ++i) {
		if (qps[i - 1] * k > 20000000)break;
		qps[i] = qps[i - 1] * k;
	}
	int ok = 0;
	int ans = 0;
	memset(pre, 0, sizeof pre);
	while (!ok) {
		memset(bit, 0, sizeof bit);
		int tans = ans;
		for (int &i : bit) {
			i = tans % k;
			tans /= k;
			if (!tans)break;
		}
		if (ans % 2) {
			for (int i = 0; i < 30; ++i) {
				bit[i] = (pre[i] + k - bit[i]) % k;
			}
		} else {
			for (int i = 0; i < 30; ++i) {
				bit[i] = (bit[i] + pre[i]) % k;
			}
		}
		int x = 0;
		for (int i = 0; i < 30; ++i) {
			x += qps[i] * bit[i];
		}
		ok = ask(x);
		for (int i = 0; i < 30; ++i) {
			pre[i] = (bit[i] + k - pre[i]) % k;
		}
		++ans;
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}