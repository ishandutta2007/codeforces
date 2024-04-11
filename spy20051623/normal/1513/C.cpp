#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int l[200050][10];

void solve() {
	int n, m;
	long long sum = 0;
	scanf("%d%d", &n, &m);
	while (n) {
		int p = n % 10;
		p += m;
		for (int i = 0; i < 10; ++i) {
			sum += l[p][i];
		}
		sum %= mod;
		n /= 10;
	}
	printf("%d\n", sum);
}

int main() {
//	freopen("in.txt", "r", stdin);
	l[0][0] = 1;
	for (int i = 1; i < 200051; ++i) {
		int k = l[i - 1][9];
		for (int j = 1; j < 10; ++j) {
			l[i][j] = l[i - 1][j - 1];
		}
		l[i][0] += k;
		l[i][1] += k;
		for (int j = 0; j < 10; ++j) {
			l[i][j] %= mod;
		}
	}
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}