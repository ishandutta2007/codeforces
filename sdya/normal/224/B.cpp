#include <iostream>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
using namespace std;

const int maxN = 110000;
int cnt[maxN];

int main() {
	int n, k;
	cin >> n >> k;
	vector < int > a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int m = 1;
	++cnt[a[0]];
	int right_bound = 0;
	for (int i = 0; i < n; ++i) {
		while (right_bound + 1 < n && m < k) {
			++cnt[a[right_bound + 1]];
			if (cnt[a[right_bound + 1]] == 1) {
				++m;
			}
			++right_bound;
		}
		if (m == k) {
			int old = i;
			int x = i;
			while (true) {
				--cnt[a[x]];
				if (cnt[a[x]] == 0) {
					break;
				} else {
					old = x + 1;
					++x;
				}
			}
			printf("%d %d\n", old + 1, right_bound + 1);
			return 0;
		}
		--cnt[a[i]];
		if (cnt[a[i]] == 0) {
			--m;
		}
	}
	printf("-1 -1\n");
	return 0;
}