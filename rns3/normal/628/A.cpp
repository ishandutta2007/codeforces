#include <bits/stdc++.h>
using namespace std;

int n, b, p;

int calc(int n) {
	if (n == 1) return 0;
	int Log = 31 - __builtin_clz(n);
	return calc((1 << Log - 1) + (n % (1 << Log))) + b * (1 << Log) + (1 << Log - 1);
}

int main() {
//	freopen("a.in", "r", stdin);
	cin >> n >> b >> p;
	cout << calc(n) << ' ' << n * p << endl;
	return 0;
}