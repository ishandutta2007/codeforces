#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int n;

LL c(LL n, LL k) {
	LL rlt = 1, m = 1;
	for (int i = 1; i <= k; i ++) {
		rlt *= (n - i + 1), m *= i;
		LL d = __gcd(rlt, m);
		rlt /= d, m /= d;
	}
	return rlt / m;
}

int main() {
//	freopen("f.in", "r", stdin);
	cin >> n;
	cout << c(n, 5) + c(n, 6) + c(n, 7) << endl;
	return 0;
}