#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
		arr[i] = n - arr[i];
	}
	vector<int> ans(n);
	vector<vector<int>> byColorCount(n+1);
	for (int i = 0; i < n; ++i) byColorCount[arr[i]].push_back(i);
	int curColor = 1;
	for (int ct = 1; ct <= n; ++ct) {
		if (byColorCount[ct].size() % ct != 0) {
			printf("Impossible\n");
			return 0;
		} else if (!byColorCount[ct].empty()) {
			for (int k = 0; k < byColorCount[ct].size(); ++k) {
				ans[byColorCount[ct][k]] = curColor + (k % (byColorCount[ct].size() / ct));
			}
			curColor += byColorCount[ct].size() / ct;
		}
	}
	printf("Possible\n");
	for (int x : ans) printf("%d ", x);
	printf("\n");
	return 0;
}