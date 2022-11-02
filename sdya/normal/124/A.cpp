#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
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

bool isLucky(string s) {
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] != '4' && s[i] != '7') {
			return false;
		}
	}
	return true;
}

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		if (i > a && n - i <= b) {
			++res;
		}
	}
	cout << res;
	return 0;
}