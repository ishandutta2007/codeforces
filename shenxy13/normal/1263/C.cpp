#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int t, n;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		scanf("%d", &n);
		vector<int> ans;
		for (int j = 1; j <= n; ++j) {
			if (!ans.empty() && n / j == ans.back()) break;
			ans.push_back(n / j);
		}
		for (int j = ans.back() - 1; j >= 0; --j) ans.push_back(j);
		printf("%lu\n", ans.size());
		for (int j = ans.size() - 1; j > 0; --j) printf("%d ", ans[j]);
		printf("%d\n", ans[0]);
	}
	return 0;
}