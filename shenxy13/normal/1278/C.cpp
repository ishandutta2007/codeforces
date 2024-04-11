#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n;
		scanf("%d", &n);
		int jar[2 * n];
		for (int i = 0; i < 2 * n; ++i) scanf("%d", &jar[i]);
		int sum = 0;
		map<int, int> k;
		k[0] = 0;
		for (int i = 0; i < n; ++i) {
			if (jar[i] == 1) sum += 1;
			else sum -= 1;
			k[sum] = max(k[sum], i + 1);
		}
		int ans = k[0];
		sum = 0;
		for (int i = 2 * n - 1; i >= n; --i) {
			if (jar[i] == 1) sum += 1;
			else sum -= 1;
			if (k.find(-sum) != k.end()) ans = max(ans, 2 * n - i + k[-sum]);
		}
		printf("%d\n", 2 * n - ans);
	}
	return 0;
}