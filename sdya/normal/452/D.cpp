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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxK = 110000;
const int inf = 1000000000;

int k, n1, n2, n3, t1, t2, t3;
int a[maxK], b[maxK], c[maxK];

bool check(int a[], int index, int position, int n, int t) {
	int start = upper_bound(a + 1, a + index, position - t) - a;
	return index - start + 1 <= n;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
	{
		for (int i = 1; i <= k; ++i) {
			int left_bound = a[i - 1], right_bound = inf;
			while (right_bound - left_bound > 1) {
				int middle = (left_bound + right_bound) / 2;
				if (check(a, i, middle, n1, t1)) {
					right_bound = middle;
				} else {
					left_bound = middle;
				}
			}
			int res = right_bound;
			if (check(a, i, left_bound, n1, t1)) {
				res = left_bound;
			}
			a[i] = res;
		}
	}
	{
		for (int i = 1; i <= k; ++i) {
			int left_bound = max(b[i - 1], a[i] + t1), right_bound = inf;
			while (right_bound - left_bound > 1) {
				int middle = (left_bound + right_bound) / 2;
				if (check(b, i, middle, n2, t2)) {
					right_bound = middle;
				} else {
					left_bound = middle;
				}
			}
			int res = right_bound;
			if (check(b, i, left_bound, n2, t2)) {
				res = left_bound;
			}
			b[i] = res;
		}
	}
	{
		for (int i = 1; i <= k; ++i) {
			int left_bound = max(c[i - 1], b[i] + t2), right_bound = inf;
			while (right_bound - left_bound > 1) {
				int middle = (left_bound + right_bound) / 2;
				if (check(c, i, middle, n3, t3)) {
					right_bound = middle;
				} else {
					left_bound = middle;
				}
			}
			int res = right_bound;
			if (check(c, i, left_bound, n3, t3)) {
				res = left_bound;
			}
			c[i] = res;
		}
	}

	cout << c[k] + t3 << endl;

	return 0;
}