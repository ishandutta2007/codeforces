#include <bits/stdc++.h>

using namespace std;

int ans[200000];

int callsLeft = 0;

void attemptFill(int ai, int aj, int vi) {
	// printf("call %d %d %d\n", ai, aj, vi);
	if (aj - ai > 1 && callsLeft > 0) {
		// we need to recurse further
		callsLeft -= 2;
		int amid = (ai + aj) / 2;
		// printf("flip call %d\n", amid);
		attemptFill(amid, aj, vi);
		attemptFill(ai, amid, vi - (amid - aj));
	} else {
		// printf("fill call\n");
		for (int i = ai; i < aj; ++i) {
			ans[i] = vi + (i - ai);
			// printf("%d has %d\n", i, ans[i]);
		}
	}
}

int main() {
	int n, k; scanf("%d %d", &n, &k);
	callsLeft = k;
	if (k % 2 == 0) printf("-1\n");
	else {
		--callsLeft;
		attemptFill(0, n, 1);
		if (callsLeft > 0) printf("-1");
		else for (int i = 0; i < n; ++i) printf("%d ", ans[i]);
		printf("\n");
	}
}