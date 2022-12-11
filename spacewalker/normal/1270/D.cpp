#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k; scanf("%d %d", &n, &k);
	if (k == 1) {
		printf("! 1\n");
		return 0;
	}
	map<int, int> answers;
	for (int blank = 0; blank < k + 1; ++blank) {
		printf("?");
		for (int i = 0; i < k + 1; ++i) {
			if (i == blank) continue;
			printf(" %d", i + 1);
		}
		printf("\n");
		fflush(stdout);
		int pos, val; scanf("%d %d", &pos, &val);
		if (pos == -1) return 0;
		answers[val]++;
	}
	printf("! %d\n", answers.rbegin()->second);
	return 0;
}