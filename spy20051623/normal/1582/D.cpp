#include <bits/stdc++.h>

using namespace std;

int d[100005];

int exgcd(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	} else {
		int r = exgcd(b, a % b, y, x);
		y -= a / b * x;
		return r;
	}
}

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &d[i]);
	}
	int a = d[n - 2], b = d[n - 1], x, y;
	int g = __gcd(abs(a), abs(b));
	int s = 0;
	for (int i = 0; i < n - 2; ++i) {
		int gg = __gcd(g, abs(d[i]));
		if (s >= 0) {
			if (d[i] > 0) {
				printf("%d ", -g / gg);
				s += -g / gg * d[i];
			} else {
				printf("%d ", g / gg);
				s += g / gg * d[i];
			}
		} else {
			if (d[i] > 0) {
				printf("%d ", g / gg);
				s += g / gg * d[i];
			} else {
				printf("%d ", -g / gg);
				s += -g / gg * d[i];
			}
		}
	}
	a /= g, b /= g, s /= g;
	exgcd(abs(a), abs(b), x, y);
	s = -s;
	if (a < 0) x = -x;
	if (b < 0) y = -y;
	while (!x || !y) {
		x += b, y -= a;
	}
	if (s) printf("%d %d\n", x * s, y * s);
	else printf("%d %d\n", b, -a);
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