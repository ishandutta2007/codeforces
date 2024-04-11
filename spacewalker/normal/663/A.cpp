#include <bits/stdc++.h>

using namespace std;

char sRead[10];

int main() {
	vector<int> sign{1};
	while (scanf("%s", sRead), sRead[0] != '=') {
		if (sRead[0] == '+') sign.push_back(1);
		else if (sRead[0] == '-') sign.push_back(-1);
	}
	int n; scanf("%d", &n);
	int qCount = sign.size();
	int pos = 0, neg = 0;
	for (int x : sign) (x == 1 ? pos : neg)++;
	if (n < pos - neg * n || pos * n - neg < n) {
		printf("Impossible\n");
		return 0;
	}
	printf("Possible\n");
	vector<int> pNums(pos, 1), nNums(neg, 1);
	if (n <= pos - neg) {
		int toCompensate = (pos - neg) - n;
		for (int &x : nNums) {
			int amt = min(toCompensate, n - 1);
			toCompensate -= amt;
			x += amt;
		}
	} else {
		int toCompensate = n - (pos - neg);
		for (int &x : pNums) {
			int amt = min(toCompensate, n - 1);
			toCompensate -= amt;
			x += amt;
		}
	}
	for (int i = 0; i < qCount; ++i) {
		if (i > 0) {
			printf(" %c ", sign[i] == 1 ? '+' : '-');
		}
		if (sign[i] == 1) {
			printf("%d", pNums.back());
			pNums.pop_back();
		} else {
			printf("%d", nNums.back());
			nNums.pop_back();
		}
	}
	printf(" = %d\n", n);
	return 0;
}