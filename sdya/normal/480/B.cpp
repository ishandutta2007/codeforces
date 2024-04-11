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

const int maxN = 110000;

int n, l, x, y;
int a[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d%d", &n, &l, &x, &y);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	bool hasX = false, hasY = false;

	for (int i = 0; i < n; ++i) {
		if (binary_search(a, a + n, a[i] - x)) {
			hasX = true;
		}
		if (binary_search(a, a + n, a[i] + x)) {
			hasX = true;
		}

		if (binary_search(a, a + n, a[i] - y)) {
			hasY = true;
		}
		if (binary_search(a, a + n, a[i] + y)) {
			hasY = true;
		}
	}

	if (hasX && hasY) {
		printf("0\n");
		return 0;
	}

	if (!hasX && hasY) {
		printf("1\n%d\n", x);
		return 0;
	}
	if (!hasY && hasX) {
		printf("1\n%d\n", y);
		return 0;
	}

	vector < int > candidates;
	for (int i = 0; i < n; ++i) {
		candidates.push_back(a[i] - x);
		candidates.push_back(a[i] + x);
		candidates.push_back(a[i] - y);
		candidates.push_back(a[i] + y);
	}

	for (int i = 0; i < candidates.size(); ++i) {
		int t = candidates[i];
		if (t < 0 || t > l) {
			continue;
		}
		if (binary_search(a, a + n, t - x) || binary_search(a, a + n, t + x)) {
			if (binary_search(a, a + n, t - y) || binary_search(a, a + n, t + y)) {
				printf("1\n%d\n", t);
				return 0;
			}
		}
	}
	printf("2\n%d %d\n", x, y);

	return 0;
}