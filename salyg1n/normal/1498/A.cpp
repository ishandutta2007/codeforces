#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

ll sum_of_num(ll a) {
	ll res = 0;
	while (a > 0) {
		res += a % 10;
		a /= 10;
	}
	return res;
}

ll gcdSum(ll a) {
	return gcd(a, sum_of_num(a));
}

int main() {
	ll t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		ll n;
		cin >> n;
		while (gcdSum(n) == 1) {
			n++;
		}
		cout << n << "\n";
	}
	return 0;
}