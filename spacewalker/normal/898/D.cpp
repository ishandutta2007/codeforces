#include <bits/stdc++.h>

using namespace std;

int clockOn[1000000];
int counterAdd[2000000];

int main() {
	int n, m, k; scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; ++i) {
		int x; scanf("%d", &x);
		++clockOn[--x];
	}
	int cArrSum = 0, ans = 0;
	for (int t = 0; t < 1000000; ++t) {
		cArrSum -= counterAdd[t];
		int toAdd = clockOn[t];

		if (cArrSum + toAdd >= k) {
			++ans; --toAdd;
		}

		cArrSum += toAdd;
		counterAdd[t + m] += toAdd;
	}
	printf("%d\n", ans);
	return 0;
}