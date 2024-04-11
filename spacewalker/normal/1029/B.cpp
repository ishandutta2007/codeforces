#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>

using namespace std;

int main() {
	int n;scanf("%d", &n);
	vector<int> arr(n), maxLenAt(n);
	for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
	maxLenAt[0] = 1;
	set<pair<int, int>> accRange{{1, 0}};
	for (int i = 1; i < n; ++i) {
		while ((!accRange.empty()) && arr[accRange.rbegin()->second] * 2 < arr[i]) {
			// printf("remove %d\n", accRange.rbegin()->second);
			accRange.erase(*accRange.rbegin());
		}
		maxLenAt[i] = (accRange.empty() ? 0 : accRange.rbegin()->first) + 1;
		accRange.insert(make_pair(maxLenAt[i], i));
		// printf("add %d\n", i);
	}
	printf("%d\n", *max_element(maxLenAt.begin(), maxLenAt.end()));
	return 0;
}