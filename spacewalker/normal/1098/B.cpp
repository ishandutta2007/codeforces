#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>

using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr int INF = 1000000000;

string pairScheme[] = {"ACTG", "TGAC", "TCAG", "AGTC", "CGAT", "ATCG"};

struct NiceGridProperties {
	int pScheme;
	int n, m;
	vector<int> rowOffset;
	// 1 = 101010
	// 0 = 010101
	NiceGridProperties() {}
	NiceGridProperties(int ps, int n, int m) : pScheme(ps), n(n), m(m) {}
	NiceGridProperties(const NiceGridProperties &other) :
		pScheme(other.pScheme), n(other.n), m(other.m), rowOffset(other.rowOffset) {}
	int getOptimalGridValue(vector<vector<char>> &grid) {
		// printf("PAIR %d\n", pScheme);
		int ans = 0;
		rowOffset = vector<int>(grid.size());
		for (int i = 0; i < grid.size(); ++i) {
			vector<int> oeS1(2), oeS2(2);
			char s1 = pairScheme[pScheme][(i % 2) * 2];
			char s2 = pairScheme[pScheme][(i % 2) * 2 + 1];
			for (int j = 0; j < grid[i].size(); ++j) {
				if (grid[i][j] != s1) {
					oeS1[j%2]++;
				}
				if (grid[i][j] != s2) {
					oeS2[j%2]++;
				}
			}
			int firstValStart = oeS1[0] + oeS2[1];
			int secondValStart = oeS2[0] + oeS1[1];
			// printf("ROW %d %d %d\n", i, firstValStart, secondValStart);
			if (secondValStart < firstValStart) rowOffset[i] = 1;
			ans += min(firstValStart, secondValStart);
		}
		return ans;
	}
	void constructGrid(vector<vector<char>> &ans) {
		// printf("PAIR %d\n", pScheme);
		for (int i = 0; i < n; ++i) {
			// printf("RO %d\n", rowOffset[i]);
			for (int j = 0; j < m; ++j) {
				// printf("EL %d\n", j);
				ans[i][j] = pairScheme[pScheme][(i%2) * 2 + ((j%2) ^ rowOffset[i])];
			}
		}
	}
};

int main() {
	int n, m; scanf("%d %d", &n, &m);
	vector<vector<char>> grid(n, vector<char>(m));
	vector<vector<char>> mirrorGrid(m, vector<char>(n));
	char c; scanf("%c", &c);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%c", &(grid[i][j]));
			mirrorGrid[j][i] = grid[i][j];
		}
		scanf("%c", &c);
	}
	NiceGridProperties bestAnsRec;
	int bestAnsVal = INF;
	for (int i = 0; i < 6; ++i) {
		NiceGridProperties current(i, n, m);
		int cbv = current.getOptimalGridValue(grid);
		if (cbv < bestAnsVal) {
			bestAnsVal = cbv;
			bestAnsRec = current;
		}
	}
	NiceGridProperties mirrorBAR;
	int mirrorBAV = INF;
	for (int i = 0; i < 6; ++i) {
		NiceGridProperties current(i, m, n);
		int cbv = current.getOptimalGridValue(mirrorGrid);
		if (cbv < mirrorBAV) {
			mirrorBAV = cbv;
			mirrorBAR = current;
		}
	}
	if (bestAnsVal <= mirrorBAV) {
		vector<vector<char>> ans(n, vector<char>(m));
		bestAnsRec.constructGrid(ans);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				printf("%c", ans[i][j]);
			}
			printf("\n");
		}
	} else {
		// printf("MIRROR\n");
		vector<vector<char>> ans(m, vector<char>(n));
		mirrorBAR.constructGrid(ans);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				printf("%c", ans[j][i]);
			}
			printf("\n");
		}
	}
	return 0;
}