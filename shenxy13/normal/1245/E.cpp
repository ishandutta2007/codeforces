#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int ladders[100];
double dptable[100][2];
double dp(int i, bool usestairs) {
	if (dptable[i][usestairs] > -0.5) return dptable[i][usestairs];
	if (i == 0) return dptable[i][usestairs] = 0;
	if (i < 6) return dptable[i][usestairs] = 6;
	double ans = 0;
	for (int j = i - 6; j < i; ++j) ans += dp(j, true) / 6.0;
	ans += 1;
	if (ladders[i] != -1 && usestairs) ans = min(ans, dp(ladders[i], false));
	return dptable[i][usestairs] = ans;
}
int main() {
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 2; ++j) dptable[i][j] = -1.0;
	}
	int nextint, grid[10][10], cnt = 0;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			grid[i][j] = cnt++;
			scanf("%d", &nextint);
			if (nextint == 0) ladders[grid[i][j]] = -1;
			else ladders[grid[i][j]] = grid[i - nextint][j];
		}
		++i;
		for (int j = 9; j >= 0; --j) grid[i][j] = cnt++;
		for (int j = 0; j < 10; ++j) {
			scanf("%d", &nextint);
			if (nextint == 0) ladders[grid[i][j]] = -1;
			else ladders[grid[i][j]] = grid[i - nextint][j];
		}
	}
	printf("%.9lf", dp(99, true));
	return 0;
}