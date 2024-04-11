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
	cin >> n >> k;
	vector < string > s(n);
	vector < int > order(k);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	for (int i = 0; i < k; ++i) {
		order[i] = i;
	}
	int res = 1000000000;
	do {
		int A = 1000000000, B = 0;
		for (int i = 0; i < n; ++i) {
			int value = 0;
			for (int j = 0; j < k; ++j) {
				value = value * 10 + s[i][order[j]] - '0';
			}
			A = min(A, value);
			B = max(B, value);
		}
		res = min(res, B - A);
	} while (next_permutation(order.begin(), order.end()));
	cout << res << endl;
	return 0;
}