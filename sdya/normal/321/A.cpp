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
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	long long a, b;
	cin >> a >> b;
	string s;
	cin >> s;
	long long dx = 0, dy = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'U') {
			++dy;
		} else if (s[i] == 'D') {
			--dy;
		} else if (s[i] == 'L') {
			--dx;
		} else {
			++dx;
		}
	}

	long long x = 0, y = 0;
	if (a == 0 && b == 0) {
		printf("Yes\n");
		return 0;
	}
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'U') {
			++y;
		} else if (s[i] == 'D') {
			--y;
		} else if (s[i] == 'L') {
			--x;
		} else {
			++x;
		}
		long long k = 0;
		if (dx == 0 && dy == 0) {
			if (x == a && y == b) {
				printf("Yes\n");
				return 0;
			}
			continue;
		}
		if (dx != 0) {
			k = (a - x) / dx;
		} else {
			k = (b - y) / dy;
		}
		if (k * dx + x == a && k * dy + y == b && k >= 0) {
			printf("Yes\n");
			return 0;
		}
	}

	printf("No\n");

	return 0;
}