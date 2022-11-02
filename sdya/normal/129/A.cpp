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
	int n, k;
	cin >> n;
	int s = 0, odd = 0, even = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		s += a;
		if (a % 2 == 0) {
			++even;
		} else {
			++odd;
		}
	}
	if (s % 2 == 0) {
		cout << even;
	} else {
		cout << odd;
	}
	return 0;
}