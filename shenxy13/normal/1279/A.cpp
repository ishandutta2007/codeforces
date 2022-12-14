#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int arr[3];
		for (int j = 0; j < 3; ++j) scanf("%d", &arr[j]);
		sort(arr, arr + 3);
		if (arr[2] > arr[0] + arr[1] + 1) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}