#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
	int n, m; ll k; scanf("%d %d %lld", &n, &m, &k);
	vector<ll> arr(n);
	for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
	int lo = 0, hi = n - 1;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		// check if boxes from mid to n - 1 are sortable
		int minBoxNeeded = 0;
		ll cBoxSum = 0;
		// printf("att %d\n", mid);
		for (int i = mid; i < n; ++i) {
			cBoxSum += arr[i];
			// do we need another box for this?
			if (cBoxSum > k) {
				// printf("new box at %d\n", i);
				++minBoxNeeded;
				cBoxSum = arr[i];
			}
		}
		if (cBoxSum > 0) ++minBoxNeeded;
		if (minBoxNeeded > m) {
			lo = mid + 1;
		} else {
			hi = mid;
		}
	}
	printf("%d\n", n - lo);
	return 0;
}