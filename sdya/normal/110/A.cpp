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
	long long n;
	cin >> n;
	int m = 0;
	while (n) {
		if (n % 10 == 4 || n % 10 == 7) {
			++m;
		}
		n /= 10;
	}
	if (isLucky(m)) {
		cout << "YES";
	} else {
		cout << "NO";
	}
	return 0;
}