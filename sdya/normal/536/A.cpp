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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

long long a, b;

bool check(long long l, long long r, long long t, long long m) {
	long long h = a + (r - 1) * b;
	if (h > t) {
		return false;
	}
	long long total = ((r + l - 2) * (r - l + 1) / 2LL) * b + (r - l + 1) * a;
	return total <= t * m;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	long long n;
	scanf("%I64d%I64d%I64d", &a, &b, &n);
	for (int i = 0; i < n; ++i) {
		long long l, t, m;
		scanf("%I64d%I64d%I64d", &l, &t, &m);
		long long left_bound = l, right_bound = 2000000;
		while (right_bound - left_bound > 1) {
			long long middle = (left_bound + right_bound) / 2;
			if (check(l, middle, t, m)) {
				left_bound = middle;
			} else {
				right_bound = middle;
			}
		}
		long long bound = -1;
		if (check(l, right_bound, t, m)) {
			bound = right_bound;
		} else if (check(l, left_bound, t, m)) {
			bound = left_bound;
		}
		printf("%I64d\n", bound);
	}

	return 0;
}