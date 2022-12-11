#include <bits/stdc++.h>

using namespace std;

int main() {
	int q; scanf("%d", &q);
	while (q--) {
		int n; scanf("%d", &n);
		vector<int> arr(n);
		vector<int> nextIsSame;
		for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
		for (int i = 0; i < n; ++i) {
			if (arr[i] == arr[(i + 1) % n]) {
				nextIsSame.push_back(i);
			}
		}
		if (nextIsSame.size() == n) {
			printf("1\n");
			for (int i = 0; i < n; ++i) printf("1 ");
			printf("\n");
		} else if (n % 2 == 0) {
			printf("2\n");
			for (int i = 0; i < n; ++i) printf("%d ", (i % 2) + 1);
			printf("\n");
		} else if (!nextIsSame.empty()) {
			int keystone = nextIsSame[0];
			printf("2\n");
			for (int i = 0; i < n; ++i) printf("%d ", ((i + (i > keystone)) % 2) + 1);
			printf("\n");
		} else {
			printf("3\n");
			for (int i = 0; i < n - 1; ++i) printf("%d ", (i % 2) + 1);
			printf("3\n");
		}
		
	}
	return 0;
}