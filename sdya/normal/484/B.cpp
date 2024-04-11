#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

const int maxN = 210000;
int n, a[maxN];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	n = unique(a, a + n) - a;
	int res = 0;
	for (int i = 0; i < n; ++i) {
		int current = a[i];
		int position = i;
		while (current <= a[n - 1]) {
			int index = lower_bound(a + position, a + n, current + a[i]) - a;
			--index;
			if (a[index] < current + a[i]) {
				res = max(res, a[index] - current);
			}
			current += a[i];
			position = index;
		}
	}
	
	printf("%d\n", res);

	return 0;
}