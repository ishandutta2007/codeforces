#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	char op[2 * n];
	int x[2 * n];
	for (int i = 0; i < 2 * n; ++i) {
		scanf(" %c", &op[i]);
		if (op[i] == '-') scanf("%d", &x[i]);
	}
	vector<int> stk, ans;
	for (int i = 2 * n - 1; i >= 0; --i) {
		if (op[i] == '+') {
			if (stk.empty()) {
				printf("NO");
				return 0;
			} else ans.push_back(stk.back()), stk.pop_back();
		} else {
			if (!stk.empty() && x[i] > stk.back()) {
				printf("NO");
				return 0;
			} else stk.push_back(x[i]);
		}
	}
	reverse(ans.begin(), ans.end());
	printf("YES\n");
	for (int i: ans) printf("%d ", i);
	return 0;
}