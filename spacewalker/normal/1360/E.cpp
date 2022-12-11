#include <bits/stdc++.h>

using namespace std;
constexpr int NMAX = 55;

char grid[NMAX][NMAX];
bool canReach[NMAX][NMAX];

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%s", grid[i]);
		memset(canReach, 0, sizeof canReach);
		for (int i = n - 1; i >= 0; --i) {
			for (int j = n - 1; j >= 0; --j) {
				if (grid[i][j] == '1') {
					if (i == n - 1 || j == n - 1) canReach[i][j] = true;
					else if (canReach[i+1][j] || canReach[i][j + 1]) canReach[i][j] = true;
				}
			}
		}
		bool allExist = true;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == '1' && !canReach[i][j]) allExist = false;
			}
		}
		if (allExist) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}