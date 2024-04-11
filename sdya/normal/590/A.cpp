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

const int maxN = 510000;
int n, a[maxN], b[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	int res = 0;

	for (int i = 0; i < n; ++i) {
		int j = i;
		while (j + 1 < n && a[j + 1] != a[j]) {
			++j;
		}
		int m = (j - i + 1);
		if (m % 2 == 0) {
			for (int k = i; k < i + m / 2; ++k) {
				b[k] = a[i];
			}
			for (int k = i + m / 2; k < i + m; ++k) {
				b[k] = a[j];
			}
			res = max(res, m / 2 - 1);
		} else {
			for (int k = i; k < i + m; ++k) {
				b[k] = a[i];
			}
			res = max(res, m / 2);
		}
		i = j;
	}

	printf("%d\n", res);
	for (int i = 0; i < n; ++i) {
		printf("%d ", b[i]);
	}
	printf("\n");

	return 0;
}