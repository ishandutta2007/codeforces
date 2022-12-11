#include <bits/stdc++.h>

using namespace std;
constexpr int INF = 1000000000;

vector<int> ticketValidFor{1, 90, 1440};
vector<int> ticketCost{20, 50, 120};

int main() {
	int n; scanf("%d", &n);
	vector<int> tripTime(n);
	for (int i = 0; i < n; ++i) scanf("%d", &tripTime[i]);
	vector<vector<int>> prevCover(3, vector<int>(n, -1));
	for (int k = 0; k < 3; ++k) {
		for (int i = 0; i < n; ++i) {
			auto iterFirstC = upper_bound(begin(tripTime), end(tripTime), tripTime[i] - ticketValidFor[k]);
			if (iterFirstC == begin(tripTime)) prevCover[k][i] = -1;
			else prevCover[k][i] = distance(begin(tripTime), iterFirstC) - 1;
		}
	}
	vector<int> ans(n);
	ans[0] = 20;
	for (int i = 1; i < n; ++i) {
		ans[i] = INF;
		for (int k = 0; k < 3; ++k) {
			ans[i] = min(ans[i], (prevCover[k][i] > -1 ? ans[prevCover[k][i]] : 0) + ticketCost[k]);
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%d\n", ans[i] - (i == 0 ? 0 : ans[i-1]));
	}
	return 0;
}