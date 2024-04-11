#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	int cminEnding = 0, bestmeValue = 0, allSum = 0;
	scanf("%d", &allSum);
	cminEnding = bestmeValue = allSum = (allSum*2 - 1);
	for (int i = 1; i < n; ++i) {
		int newVal; scanf("%d", &newVal);
		newVal = newVal * 2 - 1;
		cminEnding = newVal + min(cminEnding, 0);
		bestmeValue = min(bestmeValue, cminEnding);
		allSum += newVal;
	}
	printf("%d\n", (allSum - 2*bestmeValue + n) / 2);
	return 0;
}