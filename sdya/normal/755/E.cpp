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

	int n, k;
	cin >> n >> k;
	if (k == 1 || k > 3 || n <= 3) {
		printf("-1\n");
		return 0;
	}
	if (n == 4) {
		if (k != 3) {
			printf("-1\n");
			return 0;
		}
		printf("3\n1 2\n2 3\n3 4\n");
		return 0;
	}

	if (k == 2) {
		printf("%d\n", n - 1);
		for (int i = 1; i < n; ++i) {
			printf("%d %d\n", i, i + 1);
		}
		return 0;
	}

	printf("%d\n", n - 1);
	printf("1 2\n");
	for (int i = 2; i <= n; ++i) {
		if (i != 3) {
			printf("3 %d\n", i);
		}
	}
	return 0;
}