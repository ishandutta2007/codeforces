#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k; scanf("%d %d", &n, &k);
	vector<int> cts(k);
	for (int i = 0; i < n; ++i) {
		int x; scanf("%d", &x);
		cts[x - 1]++;
	}
	int full = 0, half = 0;
	for (int i = 0; i < k; ++i) {
		full += cts[i] / 2;
		half += cts[i] % 2;
	}
	printf("%d\n", 2 * full + half / 2 + half % 2);
	return 0;
}