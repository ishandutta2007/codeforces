#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isLucky(int n) {
	if (n == 0) {
		return false;
	}
	while (n) {
		if (n % 10 != 4 && n % 10 != 7) {
			return false;
		}
		n /= 10;
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		if (n % i == 0 && isLucky(i)) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}