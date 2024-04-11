#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k; scanf("%d %d", &n, &k);
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
	int firstUn = -1, lastUn = n;
	for (int i = 0; i < n; ++i) {
		if (arr[i] > k) {
			if (firstUn == -1) firstUn = i;
			lastUn = i;
		}
	}
	if (firstUn == -1) printf("%d\n", n);
	else printf("%d\n", firstUn + (n - 1 - lastUn));
	return 0;
}