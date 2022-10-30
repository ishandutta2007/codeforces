#define _CRT_SECURE_NO_WARNINGS
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
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int h1, a1, d1;
	cin >> h1 >> a1 >> d1;
	int h2, a2, d2;
	cin >> h2 >> a2 >> d2;
	int h, a, d;
	cin >> h >> a >> d;

	int res = 1000000000;
	for (int j = a1; j <= 4000; ++j) {
		for (int k = d1; k <= 4000; ++k) {
			int needed = (j - a1) * a + (k - d1) * d;

			int x = max(0, j - d2);
			int y = max(0, a2 - k);

			if (y == 0) {
				if (x != 0) {
					res = min(res, needed);
				}
				continue;
			}

			if (x == 0) {
				continue;
			}

			int t2 = (h2 + x - 1) / x;

			int i = max(h1, (t2 + 1) * y - (y - 1));
			needed += (i - h1) * h;
			res = min(res, needed);
		}
	}

	cout << res << endl;

	return 0;
}