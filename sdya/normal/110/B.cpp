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
	vector < vector < int > > a(26);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 26; ++j) {
			if (a[j].size() == 0) {
				a[j].push_back(i);
				printf("%c", 'a' + j);
				break;
			} else if (isLucky(i - a[j].back())) {
				a[j].push_back(i);
				printf("%c", 'a' + j);
				break;
			}
		}
	}
	return 0;
}