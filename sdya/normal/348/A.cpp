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

const int maxN = 110000;
int n, a[maxN];

bool check(int i) {
	long long total = (long long)(i) * (long long)(n - 1);
	for (int j = 0; j < n; ++j) {
		total -= a[j];
	}
	return total >= 0;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	int m = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		m = max(m, a[i]);
	}

	long long left_bound = m, right_bound = 2000000000LL;
	while (right_bound - left_bound > 1) {
		long long middle = (left_bound + right_bound) / 2;
		if (check(middle)) {
			right_bound = middle;
		} else {
			left_bound = middle;
		}
	}
	if (check(left_bound)) {
		cout << left_bound << endl;
	} else {
		cout << right_bound << endl;
	}


	return 0;
}