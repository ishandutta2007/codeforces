#include <bits/stdc++.h>

using namespace std;
constexpr int NMAX = 100010;

char strng[NMAX];

int main() {
	int k, n; scanf("%d %d", &n, &k);
	scanf("%s", strng);
	int zrs = n, zre = -1, ors = n, ore = -1;
	for (int i = 0; i < n; ++i) {
		if (strng[i] == '0') zre = i;
		else ore = i;
	}	
	for (int i = n - 1; i >= 0; --i) {
		if (strng[i] == '0') zrs = i;
		else ors = i;
	}	
//	printf("%d %d %d %d\n", zrs, zre, ors, ore);
	if (zrs > zre || ors > ore) {
		printf("tokitsukaze\n");
	} else if (zre - zrs < k || ore - ors < k) {
		printf("tokitsukaze\n");
	} else if (strng[0] == strng[n-1]) {
		printf("once again\n");
	} else if (zre - zrs >= k + 1 || ore - ors >= k + 1) {
		printf("once again\n");
	} else if (2 * k < n) {
		printf("once again\n");
	} else {
		if (strng[0] == '1') {
			for (int i = 0; i < n; ++i) strng[i] = '0' + '1' - strng[i];
			swap(zrs, ors);
			swap(zre, ore);
		}
		// the zero range starts at 0, the one range ends at n - 1
		if (zre - ors + 1 >= k + 1) {
			printf("once again\n");
		} else {
			printf("quailty\n");
		}
	}
	return 0;
}