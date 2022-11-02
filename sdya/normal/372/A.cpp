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
int a[maxN], n;
int cnt[maxN];

bool check(int m) {
	if (m == 0) {
		return true;
	}

	int bound = m;
	for (int i = 0; i < m; ++i) {
		while (bound < n && a[bound] < a[i] + a[i]) {
			++bound;
		}
		if (bound == n) {
			return false;
		}
		++bound;
	}
	return true;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);

	int left_bound = 0, right_bound = n / 2;
	while (right_bound - left_bound > 1) {
		int middle = (left_bound + right_bound) / 2;
		if (check(middle)) {
			left_bound = middle;
		} else {
			right_bound = middle;
		}
	}

	int res = left_bound;
	if (check(right_bound)) {
		res = right_bound;
	}
	printf("%d\n", n - res);

	return 0;
}