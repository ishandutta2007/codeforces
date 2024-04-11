#include <bits/stdc++.h>

using namespace std;

vector<int> maxSeqCount(int toSkip, vector<int> &nums, int count) {
//	printf("MSQ %d\n", toSkip);
	int n = nums.size();
	vector<int> ans;
	for (int j = 0; j < n; ++j) {
		if (toSkip == j) continue;
		if (nums[j] != -1) {
			int eCount = ans.size();
			for (int k = 0; k < count; ++k) {
				if (k == ans.size()) {
					ans.push_back(j);
					break;
				} else if (k == 0) {
					if (nums[ans[0]] < nums[j]) {
						ans.insert(begin(ans), j);
						break;
					}
				} else if (nums[ans[k-1]] >= nums[j] && nums[j] >= nums[ans[k]]) {
					ans.insert(begin(ans) + k, j);
					break;
				}
			}
//			printf("after %d: ", j);
//			for (int x : ans) printf(" %d", x);
//			printf("\n");
//			printf("%lu elements\n", ans.size());
			if (ans.size() > count) ans.resize(count);
		}
	}
	return ans;
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	vector<vector<int>> graph(n);
	for (int i = 0; i < m; ++i) {
		int u, v; scanf("%d %d", &u, &v);
		graph[--u].push_back(--v);
	}
	vector<vector<int>> sdist(n, vector<int>(n, -1));
	for (int st = 0; st < n; ++st) {
		sdist[st][st] = 0;
		queue<int> q;
		q.push(st);
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (int next : graph[cur]) {
				if (sdist[st][next] == -1) {
					sdist[st][next] = sdist[st][cur] + 1;
					q.push(next);
				}
			}
		}
	}
	vector<vector<int>> inMaxPairs(n);
	vector<vector<int>> outMaxPairs(n);
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < n; ++j) {
//			printf("%4d ", sdist[i][j]);
//		}
//		printf("\n");
//	}
	for (int i = 0; i < n; ++i) {
		vector<int> idist(n), odist(n);
		for (int j = 0; j < n; ++j) {
			idist[j] = sdist[j][i];
		}
		inMaxPairs[i] = maxSeqCount(i, idist, 3);
		outMaxPairs[i] = maxSeqCount(i, sdist[i], 3);
//		printf("in %d:", i);
//		for (int x : inMaxPairs[i]) printf(" %d", x);
//		printf("\nout %d:", i);
//		for (int x : outMaxPairs[i]) printf(" %d", x);
//		printf("\n");
	}
	int ans = 0;
	vector<int> path(4, -1);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j || sdist[i][j] == -1) continue;
			for (int lead : inMaxPairs[i]) {
				for (int trail : outMaxPairs[j]) {
					if (lead == j || trail == i || lead == trail) continue;
					int cost = sdist[lead][i] + sdist[i][j] + sdist[j][trail];
//					printf("checking %d %d %d %d\n", lead, i, j, trail);
					if (cost > ans) {
						ans = cost;
						path = {lead, i, j, trail};
					}
				}
			}
		}
	}
	for (int i = 0; i < 4; ++i) printf("%d ", path[i] + 1);
	printf("\n");
	return 0;
}