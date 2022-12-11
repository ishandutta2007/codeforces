#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<int> left(n), right(n);
	for (int i = 0; i < n; ++i) scanf("%d %d", &left[i], &right[i]);
	multiset<int> leftend(left.begin(), left.end()), rightend(right.begin(), right.end());
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		leftend.erase(leftend.find(left[i]));
		rightend.erase(rightend.find(right[i]));
		ans = max(ans, *(rightend.begin()) - *(leftend.rbegin()));
		leftend.insert(left[i]);
		rightend.insert(right[i]);
	}
	printf("%d\n", ans);
	return 0;
}