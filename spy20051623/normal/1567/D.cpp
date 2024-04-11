#include <bits/stdc++.h>

using namespace std;

int x[20];

int p[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

void solve() {
	memset(x, 0, sizeof x);
	int s, n;
	scanf("%d%d", &s, &n);
	int cnt = 0, sum = 0, ss = s;
	while (ss) {
		x[cnt++] = ss % 10;
		sum += x[cnt - 1];
		ss /= 10;
	}
	if (sum >= n) {
		while (n > 1) {
			while (!x[cnt - 1]) --cnt;
			--x[cnt - 1], --n;
			s -= p[cnt - 1];
			printf("%d ", p[cnt - 1]);
		}
		if (s) printf("%d\n", s);
		return;
	}
	int pos = 1;
	while (sum < n) {
		while (!x[pos]) ++pos;
		--x[pos];
		if (n - sum <= 9) x[pos - 1] += n - sum, sum = n;
		else x[pos - 1] += 10, sum += 9, pos > 1 ? --pos : 0;
	}
	while (n > 1) {
		while (!x[cnt - 1]) --cnt;
		--x[cnt - 1], --n;
		s -= p[cnt - 1];
		printf("%d ", p[cnt - 1]);
	}
	if (s) printf("%d\n", s);
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