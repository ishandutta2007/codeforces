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

bool check(int bound, int n, int m) {
	int c6 = bound / 6;
	int c2 = bound / 2 - c6;
	int c3 = bound / 3 - c6;

	n = max(0, n - c2);
	m = max(0, m - c3);
	return n + m <= c6;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;
	int left_bound = 0, right_bound = 1000000000;
	while (right_bound - left_bound > 1) {
		int middle = (left_bound + right_bound) / 2;
		if (check(middle, n, m)) {
			right_bound = middle;
		} else {
			left_bound = middle;
		}
	}
	int bound = right_bound;
	if (check(left_bound, n, m)) {
		bound = left_bound;
	}
	cout << bound << endl;


	return 0;
}