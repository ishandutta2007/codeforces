#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

#define OFFSET 10000
#define MOD 1000000007
using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<int> arr(n, 0);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	vector<vector<int>> waysToGet(n, vector<int>(2*OFFSET + 1, 0));
	for (int i = 0; i < n; ++i) {
		waysToGet[i][OFFSET] = 1;
	}
	waysToGet[0][OFFSET + arr[0]] = 1;
	waysToGet[0][OFFSET - arr[0]] = 1;
	for (int i = 1; i < n; ++i) {
		for (int s = -OFFSET; s <= OFFSET; ++s) {
			int os = s + OFFSET;
			waysToGet[i][os] = (waysToGet[i][os] + ((os-arr[i] > 0 ? waysToGet[i-1][os-arr[i]] : 0) 
												 + (os+arr[i] <= 2*OFFSET ? waysToGet[i-1][os+arr[i]] : 0)) % MOD) % MOD;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = (ans + waysToGet[i][OFFSET] - 1) % MOD;
	}
	printf("%d\n", ans); 
	return 0;
}