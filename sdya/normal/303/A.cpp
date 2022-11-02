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

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	if (n % 2 == 0) {
		printf("-1\n");
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 0; i < n; ++i) {
		printf("%d ", (i + 1) % n);
	}
	printf("\n");
	for (int i = 0; i < n; ++i) {
		printf("%d ", (2 * i + 1) % n);
	}
	printf("\n");

	return 0;
}