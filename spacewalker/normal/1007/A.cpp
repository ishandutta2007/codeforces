#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
	sort(arr.begin(), arr.end());
	set<pair<int, int>> elemSorted;
	for (int i = 0; i < n; ++i) {
		elemSorted.emplace(arr[i], i);
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		auto toRem = elemSorted.upper_bound(make_pair(arr[i], n));
		if (toRem != elemSorted.end()) {
			++ans;
			elemSorted.erase(toRem);
		}
	}
	printf("%d\n", ans);
	return 0;
}