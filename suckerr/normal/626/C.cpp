#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int n, m;

bool check(int limit) {
	int h2 = 2 * n;
	if (h2 > limit) {
		return false;
	}

	int cur = 0;
	for (int i = 1; i <= m; i++) {
		cur += 3;
		if (cur % 2 == 0) {
			if (h2 + 2 <= limit) {
				h2 += 2;
			} else {
				cur += 3;
			}
		}
	}
	return cur <= limit;
}

int main() {
	scanf("%d %d", &n, &m);
	int l = 0, r = 1e7;
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	cout << l << endl;
	return 0;
}