#include <bits/stdc++.h>
using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int num, den;
	if(a * d > b * c) {
		num = a * d - b * c;
		den = a * d;
	} else {
		num = b * c - a * d;
		den = b * c;
	}
	int g = __gcd(num, den);
	num /= g; den /= g;
	cout << num << '/' << den << '\n';
	return 0;
}