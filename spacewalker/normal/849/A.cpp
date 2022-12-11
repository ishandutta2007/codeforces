#include <cstdio>
#include <vector>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<int> arr(n, 0);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	if (n % 2 == 1 && arr[0] % 2 == 1 && arr[n-1] % 2 == 1) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}