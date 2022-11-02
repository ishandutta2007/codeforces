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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, k;
	cin >> n >> k;
	if (k < n / 2) {
		cout << "-1" << endl;
		return 0;
	}

	if (n == 1) {
		if (k == 0) {
			cout << 1 << endl;
			return 0;
		} 
		cout << -1 << endl;
		return 0;
	}

	int m = n / 2 - 1;
	int x = k - m;
	int y = 2 * (k - m);

	printf("%d %d", x, y);
	int z = max(x, y) + 1;
	for (int i = 2; i < n; ++i) {
		printf(" %d", z + i);
	}
	printf("\n");


	return 0;
}