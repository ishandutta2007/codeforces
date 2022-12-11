#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int ans[200][200], rowxor[200], colxor[200], n, m;

bool fillAns(int bitIdx) {
	vector<int> rowOdd, colOdd;
	for (int i = 0; i < n; ++i)
		if (((1<<bitIdx)&rowxor[i]) > 0) rowOdd.push_back(i); 
	for (int i = 0; i < m; ++i) {
		if (((1<<bitIdx)&colxor[i]) > 0) colOdd.push_back(i);
	}
	if (rowOdd.size() % 2 != colOdd.size() % 2) return false;
	for (int i = 0; i < min(rowOdd.size(), colOdd.size()); ++i) {
		ans[rowOdd[i]][colOdd[i]] |= (1<<bitIdx);
	}
	if (rowOdd.size() > colOdd.size()) {
		for (int i = colOdd.size(); i < rowOdd.size(); ++i) {
			ans[rowOdd[i]][0] |= (1<<bitIdx);
		}
	}
	if (colOdd.size() > rowOdd.size()) {
		for (int i = rowOdd.size(); i < colOdd.size(); ++i) {
			ans[0][colOdd[i]] |= (1 << bitIdx);
		}
	}
	return true;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d", rowxor + i);
	for (int i = 0; i < m; ++i) scanf("%d", colxor + i);
	for (int biti = 31; biti >= 0; --biti) {
		if (!fillAns(biti)) {printf("NO\n"); return 0;}
	}
	printf("YES\n");
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%s%d", (j == 0 ? "" : " "), ans[i][j]);
		}
		printf("\n");
	}
}