#include <bits/stdc++.h>
using namespace std;

long long n, mod;

long long lcm(long long a, long long b) {
	return a / __gcd(a, b) * b;
}

int main() {
//	freopen("j.in", "r", stdin);
	mod = 1;
	for (long long i = 2; i <= 10; i ++) mod = lcm(mod, i);
	cin >> n;
	cout << n / mod << endl;
	return 0;
}