#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX_PER_DAY 8
using namespace std;

int main() {
	int n, k; scanf("%d %d", &n, &k);
	vector<int> candies(n, 0);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &candies[i]);
	}
	int givenCandies = 0;
	int aryaStock = 0;
	for (int i = 0; i < n; ++i) {
		// add the current candies to arya's stock
		aryaStock += candies[i];
		int toGive = min(MAX_PER_DAY, aryaStock);
		givenCandies += toGive;
		aryaStock -= toGive;
		if (givenCandies >= k) {
			printf("%d\n", i + 1);
			return 0;
		}
	}	
	printf("-1\n");
	return 0;
}