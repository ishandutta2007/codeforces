#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int getMask(int n) {
	vector < int > digits;
	while (n) {
		if (n % 10 == 4 || n % 10 == 7) {
			digits.push_back(n % 10);
		}
		n /= 10;
	}
	reverse(digits.begin(), digits.end());
	int res = 0;
	for (int i = 0; i < digits.size(); ++i) {
		res = res * 10 + digits[i];
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b;
	cin >> a >> b;
	for (int c = a + 1; ; ++c) {
		if (getMask(c) == b) {
			cout << c << endl;
			return 0;
		}
	}

	return 0;
}