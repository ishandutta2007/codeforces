#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <bitset>
using namespace std;

bitset<10> get(int n) {
	bitset<10> res;
	while (n) {
		res[n % 10] = 1;
		n /= 10;
	}
	return res;
}

int main() {
	int n;
	cin >> n;
	int res = 0;
	for (int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			if ((get(i) & get(n)).count() > 0) {
				++res;
			}
			if (i != n / i && (get(n / i) & get(n)).count() > 0) {
				++res;
			}
		}
	}
	cout << res << endl;
	return 0;
}