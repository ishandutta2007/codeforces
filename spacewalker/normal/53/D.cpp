#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<int> goal(n), cur(n);
	for (int i = 0; i < n; ++i) scanf("%d", &goal[i]);
	for (int i = 0; i < n; ++i) scanf("%d", &cur[i]);
	vector<int> targetPos(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (goal[j] == cur[i]) {
				// printf("%d target %d\n", i, j);
				targetPos[i] = j;
				goal[j] = -1;
				break;
			}
		}
	}
	vector<pair<int, int>> ans;
	for (int i = 0; i < n; ++i) {
		int toPull = min_element(targetPos.begin() + i, targetPos.end()) - targetPos.begin();
		for (int j = toPull - 1; j >= i; --j) {
			swap(targetPos[j], targetPos[j+1]);
			ans.emplace_back(j, j + 1);
		}
	}
	printf("%lu\n", ans.size());
	for (auto pp : ans) printf("%d %d\n", pp.first + 1, pp.second + 1);
	return 0;
}