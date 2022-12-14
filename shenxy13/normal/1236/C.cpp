#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<int> ans[n];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i % 2) ans[n - 1 - j].push_back(i * n + j + 1);
			else ans[j].push_back(i * n + j + 1);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) printf("%d%c", ans[i][j], j==n-1?'\n':' ');
	}
	return 0;
}