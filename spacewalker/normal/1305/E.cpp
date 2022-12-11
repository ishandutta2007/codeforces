#include <bits/stdc++.h>
using namespace std;

constexpr int PEEPEE = 100000000;
constexpr int POOPOO = 20000;

int waysToSum(int ub, int k) {
	int slow, shi;
	if (k <= ub) {
		slow = 1, shi = k - 1;
	} else {
		slow = k - ub, shi = ub;
	}
	if (slow > shi) return 0;
	else return (shi - slow + 1) / 2;
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	if (n == 1) {
		if (m > 0) printf("-1\n");
		else printf("69\n");
		return 0;
	}
	// first compute the number of starting terms
	int curCount = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (i + j <= n) ++curCount;
		}
	}
	if (m > curCount) {
		printf("-1\n");
		return 0;
	}
	int finalLast = -1, finalRoam = -1;
	for (int potfLast = n - 1; potfLast > 0; --potfLast) {
		int potfRoam;
//		printf("last elem %d?\n", potfLast);
		for (potfRoam = potfLast + 1;
				curCount > m && waysToSum(potfLast, potfRoam) > 0;
				curCount += waysToSum(potfLast, potfRoam + 1) - waysToSum(potfLast, potfRoam), 
				++potfRoam) {
//			printf("checking %d %d %d\n", curCount, potfLast, potfRoam);
		}
		if (curCount == m) {
			finalLast = potfLast, finalRoam = potfRoam;
			break;
		}
	}
//	printf("TEMP: %d %d\n", finalLast, finalRoam);
	vector<int> ans;
	for (int i = 1; i <= finalLast; ++i) ans.push_back(i);
	ans.push_back(finalRoam);
	int curBonus = PEEPEE;
	while (ans.size() < n) {
		ans.push_back(curBonus);
		curBonus += POOPOO;
	}
	for (int x : ans) printf("%d ", x);
	printf("\n");
	return 0;
}