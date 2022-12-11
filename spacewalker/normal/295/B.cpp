#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_set>
#define INF 1000000000

using namespace std;
typedef long long ll;

int main() {
	int n; scanf("%d", &n);
	vector<vector<ll>> graph(n, vector<ll>(n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%lld", &graph[i][j]);
		}
	}
	vector<int> toDel(n, -1);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &toDel[i]);
		--toDel[i];
	}
	reverse(toDel.begin(), toDel.end());
	vector<vector<ll>> optPath(graph);
	vector<int> included;
	included.reserve(n);
	vector<ll> ans(n, 0);
	for (int q = 0; q < n; ++q) {
		int toAdd = toDel[q];
		included.push_back(toAdd);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				optPath[i][j] = min(optPath[i][j], optPath[i][toAdd] + optPath[toAdd][j]);
				//printf("op[%d][%d][%d] = %lld\n", i, j, q, optPath[i][j]);
			}
		}
		for (int i : included) {
			for (int j : included) {
				ans[q] += optPath[i][j];
			}
		}
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < n; ++i) {
		printf("%s%lld", (i == 0 ? "" : " "), ans[i]);
	}
	return 0;
}