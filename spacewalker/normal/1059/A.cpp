#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
	int n, l, a; scanf("%d %d %d", &n, &l, &a);
	vector<int> arr(n), len(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &arr[i], &len[i]);
	}
	if (n == 0) {
		printf("%d\n", l/a);
		return 0;
	}
	int total = arr[0]/a;
	// printf("INIT %d\n", total);
	for (int i = 1; i < n; ++i) {
		total += (arr[i] - (arr[i-1] + len[i-1]))/a;
		// printf("TT %d\n", total);
	}
	total += (l - (arr[n-1] + len[n-1]))/a;
	printf("%d\n", total);
	return 0;
}