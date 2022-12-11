#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

#define INF 1000000000

using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<int> boy(n, -1);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &boy[i]);
	}
	int m; scanf("%d", &m);
	vector<int> girl(m, -1);
	for (int i = 0; i < m; ++i) {
		scanf("%d", &girl[i]);
	}
	sort(boy.begin(), boy.end());
	sort(girl.begin(), girl.end());
	vector<vector<int>> opt(n + 1, vector<int>(m + 1, -INF));
	for (int i = 0; i < n; ++i) {
		opt[i][0] = 0;
	}
	for (int i = 0; i < m; ++i) {
		opt[0][i] = 0;
	}
	for (int bc = 1; bc <= n; ++bc) {
		for (int gc = 1; gc <= m; ++gc) {
			opt[bc][gc] = max(opt[bc-1][gc], opt[bc][gc-1]);
			if (abs(boy[bc-1] - girl[gc-1]) <= 1) {
				opt[bc][gc] = max(opt[bc][gc], opt[bc-1][gc-1] + 1);
			}
			//printf("opt[%d][%d] = %d\n", bc, gc, opt[bc][gc]);
		}
	}
	printf("%d\n", opt[n][m]);
	return 0;
}