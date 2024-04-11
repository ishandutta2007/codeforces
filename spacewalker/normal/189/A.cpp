#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
	int n, a, b, c; scanf("%d %d %d %d", &n, &a, &b, &c);
	vector<int> opt(n+1, 0);
	for (int i = 1; i <= n; ++i) {
		opt[i] = max((i - a >= 0 ? opt[i-a] + 1 : -1000000),
				 max((i - b >= 0 ? opt[i-b] + 1 : -1000000),
					 (i - c >= 0 ? opt[i-c] + 1 : -1000000)));
		//printf("dp[%d] = %d\n", i, opt[i]);
	}
	printf("%d\n", opt[n]);
}