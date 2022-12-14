#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	char c;
	int arr[n + 1][n + 1];
	for (int i = 0; i < n + 1; ++i) arr[i][0] = arr[0][i] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < n; j += 4) {
			scanf(" %c", &c);
			int x = (c >= '0' && c <= '9' ? c - '0' : c - 'A' + 10);
			arr[i][j] = x / 8;
			arr[i][j + 1] = (x % 8) / 4;
			arr[i][j + 2] = (x % 4) / 2;
			arr[i][j + 3] = x % 2;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
	}
	int ans = 0;
	for (int x = 1; x <= n; ++x) {
		if (n % x) continue;
		bool possible = true;
		for (int i = x; i <= n; i += x) {
			for (int j = x; j <= n; j += x) {
				int sum = arr[i][j] - arr[i - x][j] - arr[i][j - x] + arr[i - x][j - x];
				if (sum != x * x && sum != 0) possible = false;
			}
		}
		if (possible) ans = x;
	}
	printf("%d", ans);
	return 0;
}