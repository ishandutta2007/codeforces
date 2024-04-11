#include <bits/stdc++.h>
using namespace std;

long long a, b, k;

long long calc(long long n) {
	return n / k;
}

int main() {
//	freopen("a.in", "r", stdin);
	cin >> k >> a >> b;
	if (a < 0 && b < 0) a = -a, b = -b;
	if (a > b) swap(a, b);
	if (a == 0) cout << calc(b) + 1 << endl;
	else if (a > 0) cout << calc(b) - calc(a - 1) << endl;
	else cout << calc(-a) + calc(b) + 1 << endl;
}