#include <bits/stdc++.h>

using namespace std;

int forceInComp(int x, map<int, int> &comp) {
	if (comp.count(x) == 0) {
		int ita = comp.size();
		comp[x] = ita;
	}
	return comp[x];
}

constexpr int ASIZE = 2020;

int vertBlock[ASIZE][ASIZE], horiBlock[ASIZE][ASIZE];
int partSum[ASIZE][ASIZE];

int gridSum(int i1, int i2, int j1, int j2) {
	return partSum[i2 + 1][j2 + 1] - partSum[i1][j2 + 1] - partSum[i2 + 1][j1] + partSum[i1][j1];
}

bool pwedengHatiin(int i1, int i2, int j1, int j2) {
//	printf("PH %d %d %d %d\n", i1, i2, j1, j2);
	int lamangParihaba = gridSum(i1, i2, j1, j2);
	if (lamangParihaba == 1) return true;
	for (int lhe = j1; lhe < j2; ++lhe) {
//		printf("LHE %d vb %d\n", lhe, vertBlock[i1][lhe] + i1);
//		printf("sum halves %d %d\n", gridSum(i1, i2, j1, lhe), gridSum(i1, i2, lhe + 1, j2));
		if (vertBlock[i1][lhe] + i1 >= i2 && gridSum(i1, i2, j1, lhe) < lamangParihaba
				&& gridSum(i1, i2, lhe + 1, j2) < lamangParihaba) {
			return pwedengHatiin(i1, i2, j1, lhe) && pwedengHatiin(i1, i2, lhe + 1, j2);
		}
	}
	for (int uhe = i1; uhe < i2; ++uhe) {
		if (horiBlock[uhe][j1] + j1 >= j2 && gridSum(i1, uhe, j1, j2) < lamangParihaba
				&& gridSum(uhe + 1, i2, j1, j2) < lamangParihaba) {
			return pwedengHatiin(i1, uhe, j1, j2) && pwedengHatiin(uhe + 1, i2, j1, j2);
		}
	}
	return false;
}

int main() {
	int n; scanf("%d", &n);
	vector<pair<int, int>> xRange(n), yRange(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d %d %d", &xRange[i].first, &yRange[i].first, &xRange[i].second, &yRange[i].second);
	}
	map<int, int> xcomp, ycomp;
	set<int> xLaman, yLaman;
	for (int i = 0; i < n; ++i) {
		xLaman.insert(xRange[i].first);
		xLaman.insert(xRange[i].second);
		yLaman.insert(yRange[i].first);
		yLaman.insert(yRange[i].second);
	}
	for (int x : xLaman) forceInComp(x, xcomp);
	for (int y : yLaman) forceInComp(y, ycomp);
	for (int i = 0; i < n; ++i) {
		xRange[i].first = forceInComp(xRange[i].first, xcomp);
		xRange[i].second = forceInComp(xRange[i].second, xcomp);
		yRange[i].first = forceInComp(yRange[i].first, ycomp);
		yRange[i].second = forceInComp(yRange[i].second, ycomp);
		--xRange[i].second;
		--yRange[i].second;
		swap(xRange[i].first, yRange[i].first);
		swap(xRange[i].second, yRange[i].second);
	}
	swap(xcomp, ycomp);
	for (int i = 0; i < n; ++i) {
//		printf("comp %d %d %d %d\n", xRange[i].first, yRange[i].first,
//				xRange[i].second, yRange[i].second);
	}
	n = xcomp.size();
	int m = ycomp.size(), k = xRange.size();
	for (int i = 0; i < k; ++i) {
		for (int xc = xRange[i].first; xc <= xRange[i].second; ++xc) {
			for (int yc = yRange[i].first; yc <= yRange[i].second; ++yc) {
				if (xc < xRange[i].second) horiBlock[xc][yc] = -1;
				if (yc < yRange[i].second) vertBlock[xc][yc] = -1;
//				printf("%d %d blocks %d %d\n", xc, yc, vertBlock[xc][yc], horiBlock[xc][yc]);
			}
		}
		partSum[xRange[i].first + 1][yRange[i].first + 1]++;	
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			partSum[i][j] += partSum[i-1][j] + partSum[i][j-1] - partSum[i-1][j-1];
//			printf("PS %d %d %d\n", i, j, partSum[i][j]);
		}
	}
//	printf("%d %d\n", n, m);
	for (int j = 0; j < m - 1; ++j) {
		for (int i = n - 1; i >= 0; --i) {
//			printf("vb %d %d = %d\n", i, j, vertBlock[i][j]);
			if (vertBlock[i][j] == -1) continue;
			vertBlock[i][j] = (i == n - 1 ? 0 : vertBlock[i+1][j]) + 1;
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		for (int j = m - 1; j >= 0; --j) {
			if (horiBlock[i][j] == -1) continue;
			horiBlock[i][j] = (j == m - 1 ? 0 : horiBlock[i][j + 1]) + 1;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m - 1; ++j) {
//			printf("%d ", vertBlock[i][j]);
		}
//		printf("\n");
	}
	for (int j = 0; j < m; ++j) {
		for (int i = 0; i < n - 1; ++i) {
//			printf("%d ", horiBlock[i][j]);
		}
//		printf("\n");
	}
	if (pwedengHatiin(0, n - 1, 0, m - 1)) printf("YES\n");
	else printf("NO\n");
	return 0;
}