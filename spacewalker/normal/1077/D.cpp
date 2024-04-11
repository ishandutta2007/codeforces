#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;
typedef long long ll;

int occ[300000];

int main() {
	int n, k; scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) {
		int x; scanf("%d", &x);
		++occ[x];
	}
	vector<int> pickOrder;
	for (int i = 0; i < 300000; ++i) if (occ[i] > 0) pickOrder.push_back(i);
	sort(pickOrder.begin(), pickOrder.end(), [] (int i, int j) {return occ[i] > occ[j];});
	int lo = 1, hi = (n+1);
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		// printf("[%d %d %d]\n", lo, mid, hi);
		// we try to find longest array such that we can get at least mid copies
		// if an element has e copies, we take the max. k such that mid*k <= e
		// k <= e/mid
		int arrLength = 0;
		for (int i : pickOrder) {
			arrLength += occ[i] / mid;
			// printf("element %d allows %d copies\n", i, occ[i] / mid);
		}
		if (arrLength >= k) {
			// it's a yes!
			lo = mid +1;
		} else {
			hi = mid;
		}
	}
	--lo;
	// printf("ANS %d\n", lo);
	vector<int> ans;
	for (int i : pickOrder) {
		for (int rep = 0; rep < occ[i] / lo && ans.size() < k; ++rep) {
			ans.push_back(i);
		}
	}
	for (int x : ans) printf("%d ", x);
	printf("\n");
	return 0;
}