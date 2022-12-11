#include <cstdio>
#include <vector>

using namespace std;

int main() {
	int n, k, m; scanf("%d %d %d", &n, &k, &m);
	vector<vector<int>> byMod(m, vector<int>());
	for (int i = 0; i < n; ++i) {
		int temp; scanf("%d", &temp);
		byMod[(temp%m)].push_back(temp);
	}
	for (int i = 0; i < m; ++i) {
		if (byMod[i].size() >= k) {
			printf("Yes\n");
			for (int j = 0; j < k; ++j) {
				printf("%s%d", (j > 0 ? " " : ""), byMod[i][j]);
			}
			return 0;
		}
	}
	printf("No\n");
	return 0;
}