#include <bits/stdc++.h>
using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	int num = 0, den = n - 2;
	for(int b = 2; b < n; b ++)
		for(int t = 1; t <= n; t *= b)
			num += n % (t * b) / t;
	int g = __gcd(num, den);
	num /= g; den /= g;
	cout << num << '/' << den << '\n';
	return 0;
}