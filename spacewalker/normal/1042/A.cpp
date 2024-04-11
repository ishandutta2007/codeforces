#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	int m; scanf("%d", &m);
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
	int maxK = *max_element(arr.begin(), arr.end()) + m;
	for (int i = 0; i < m; ++i) (*min_element(arr.begin(), arr.end()))++;
	int minK = *max_element(arr.begin(), arr.end());
	printf("%d %d\n", minK, maxK);
	return 0;
}