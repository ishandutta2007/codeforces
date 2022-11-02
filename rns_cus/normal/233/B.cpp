#include <bits/stdc++.h>
using namespace std;

long long n;

int sum(int x) {
	int rlt = 0;
	while (x) rlt += x % 10, x /= 10;
	return rlt;
}

int solve1() {
	for (int i = 1; 1ll * i * i <= n; i ++) {
		if (1ll * i * (i + sum(i)) == n) return i;
	}
	return -1;
}

int solve2() {
	int st = sqrt(n) - 100;
	for (int i = st; 1ll * i * i <= n; i ++) {
		if (1ll * i * (i + sum(i)) == n) return i;
	}
	return -1;
}

int main() {
//	freopen("b.in", "r", stdin);
	cin >> n;
	if (n < 1e12) cout << solve1() << endl;
	else cout << solve2() << endl;
	return 0;
}