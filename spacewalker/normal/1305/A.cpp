#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		vector<int> a(n), b(n);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
		sort(begin(a), end(a));
		sort(begin(b), end(b));
		for (int x : a) printf("%d ", x);
		printf("\n");
		for (int x : b) printf("%d ", x);
		printf("\n");
	}
	return 0;
}