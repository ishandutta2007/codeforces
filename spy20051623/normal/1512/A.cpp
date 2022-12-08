#include <bits/stdc++.h>

using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, a[200], c1, c2, n1, n2;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		c1 = c2 = 0;
		for (int i = 0; i < n; ++i) {
			if (c1 == 0) {
				++c1;
				n1 = a[i];
			} else if (a[i] == n1) {
				++c1;
			} else if (c2 == 0) {
				++c2;
				n2 = a[i];
			} else {
				++c2;
			}
		}
		if (c1 == 1) {
			for (int i = 0; i < n; ++i) {
				if (a[i] == n1) {
					printf("%d\n", i + 1);
					break;
				}
			}
		} else {
			for (int i = 0; i < n; ++i) {
				if (a[i] == n2) {
					printf("%d\n", i + 1);
					break;
				}
			}
		}
	}
	return 0;
}