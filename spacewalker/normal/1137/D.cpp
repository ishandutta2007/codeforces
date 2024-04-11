#include <bits/stdc++.h>

using namespace std;

char moveResult[100];

// hare is 1, tortoise is 2, cockroach is 3 to 10
// return a bitmask. 1 is on if tortoise and hare are on same cell,
// 2 if tortoise and cockroach are on same cell
int makeMove(bool hare, bool tortoise, bool cockroach) {
	printf("next ");
	if (hare) printf("0 ");
	if (tortoise) printf("1 ");
	if (cockroach) for (int i = 2; i < 10; ++i) printf("%d ", i);
	printf("\n");
	fflush(stdout);
	vector<int> results(10);
	int digSet;
	if (scanf("%d", &digSet) == 0) exit(0);
	for (int i = 0; i < digSet; ++i) {
		scanf("%s", moveResult);
		for (int j = 0; moveResult[j]; ++j) results[moveResult[j] - '0'] = i;
	}
	int ans = 0;
	if (results[0] == results[1]) ans |= 1;
	if (results[0] == results[2]) ans |= 2;
	return ans;
}


int main() {
	do {
		makeMove(true, true, false);
	} while ((makeMove(true, false, false) & 1) == 0);
	while ((makeMove(true, true, true) & 2) == 0) {}
	printf("done\n");
	return 0;
}