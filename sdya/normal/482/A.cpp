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
	scanf("%d%d", &n, &k);
	int m = k + 1;
	for (int i = 1; i <= n - m; ++i) {
		printf("%d ", i);
	}
	int l = n - m + 1, r = n;
	for (int i = n - m + 1, j = 0; i <= n; ++i, ++j) {
		if (j % 2 == 0) {
			printf("%d ", l);
			++l;
		} else {
			printf("%d ", r);
			--r;
		}
	}
	printf("\n");

	return 0;
}