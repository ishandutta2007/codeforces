#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n;

int main() {
	int rlt = -INF;
	scanf("%d", &n);
	for (int i = 1, x; i <= n; i ++) {
		scanf("%d", &x);
		if (x < 0) {
			rlt = max(rlt, x);
			continue;
		}
		int y = sqrt(x);
		if (y * y != x) rlt = max(rlt, x);
	}
	printf("%d\n", rlt);

	return 0;
}