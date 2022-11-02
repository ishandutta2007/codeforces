#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
int n, m;
long long a[maxN], b[maxN];

long long calcDistance(int i, int l, int r) {
	if (b[l] >= a[i]) {
		return b[r] - a[i];
	}
	if (b[r] <= a[i]) {
		return a[i] - b[l];
	}
	return b[r] - b[l] + min(a[i] - b[l], b[r] - a[i]);
}

bool check(long long t) {
	int last = 1;
	for (int i = 1; i <= n; ++i) {
		if (last > m || calcDistance(i, last, last) > t) {
			continue;
		}
		int position = last;
		while (true) {
			if (position + 1 <= m && calcDistance(i, last, position + 1) <= t) {
				++position;
			} else {
				break;
			}
		}
		last = position + 1;
	}

	return last > m;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%I64d", &a[i]);
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%I64d", &b[i]);
	}

	long long left_bound = 0, right_bound = 100000000000LL;
	while (right_bound - left_bound > 1) {
		long long middle = (left_bound + right_bound) / 2;
		if (check(middle)) {
			right_bound = middle;
		} else {
			left_bound = middle;
		}
	}

	long long res = right_bound;
	if (check(left_bound)) {
		res = left_bound;
	}

	cout << res << endl;


	return 0;
}