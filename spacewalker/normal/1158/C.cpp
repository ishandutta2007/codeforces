#include <bits/stdc++.h>

using namespace std;

vector<int> perm;
vector<vector<int>> toVisit;
int cAssign;

void fillPerm(int start) {
	// printf("FILL %d with %d\n", start, cAssign);
	perm[start] = cAssign--;
	// reverse(toVisit[start].begin(), toVisit[start].end());
	for (int x : toVisit[start]) {
		// printf("move %d\n", x);
		fillPerm(x);
	}
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		vector<int> next(n);
		for (int i = 0; i < n; ++i) scanf("%d", &next[i]);
		toVisit = vector<vector<int>>(n + 1);
		bool withCons = false;
		for (int i = 0; i < n; ++i) {
			--next[i];
			if (next[i] >= 0) {
				// printf("%d->%d\n", next[i], i);
				withCons = true;
				toVisit[next[i]].push_back(i);
			}
		}
		if (!withCons) {
			for (int i = 0; i < n; ++i) printf("%d ", i + 1);
			printf("\n");
			continue;
		}
		perm.assign(n + 1, -1);
		cAssign = (toVisit[n].empty() ? n : n + 1);
		for (int i = n; i >= 0; --i) {
			if (perm[i] == -1 && !toVisit[i].empty()) fillPerm(i);
		}
		for (int i = 0; i < n; ++i) {
			if (perm[i] == -1) perm[i] = cAssign--;
		}
		vector<int> trueNext(n + 1, -1);
		stack<int> descVal;
		for (int i = 0; i <= n; ++i) {
			while (!descVal.empty() && perm[descVal.top()] < perm[i]) {
				// printf("pop %d\n", descVal.top());
				trueNext[descVal.top()] = i;
				descVal.pop();
			}
			// if (!descVal.empty()) printf("end with top %d\n", perm[descVal.top()]);
			descVal.push(i);
			// printf("push %d\n", i);
		}
		bool valid = true;
		for (int i = 0; i < n; ++i) {
			if (next[i] >= 0 && next[i] != trueNext[i]) valid = false;
		}
		if (!valid) printf("-1");
		else {
			for (int i = 0; i < n; ++i) printf("%d ", perm[i]);
		}
		printf("\n");
	}
	return 0;
}