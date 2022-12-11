#include <cstdio>
#include <vector>
#include <algorithm>
#define move kmove

using namespace std;

struct move {
	bool isRow;
	int idx;
	move(bool iR, int i) : isRow(iR), idx(i) {}
};

bool validateGuess(vector<vector<int>> &g, vector<int> &rowCt, vector<int> &colCt) {
	int n = rowCt.size();
	int m = colCt.size();
	vector<vector<int>> produced(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			produced[i][j] = rowCt[i] + colCt[j];
			//printf("predicted[%d][%d] = %d\n", i, j, produced[i][j]);
		}
	}
	return (g == produced);
}

void printMoves(vector<move> &ml) {
	printf("%lu\n", ml.size());
	for (move mv : ml) {
		printf("%s %d\n", (mv.isRow ? "row" : "col"), mv.idx + 1);
	}
}

int main() {
	int n, m; scanf("%d %d", &n, &m);

	vector<vector<int>> grid(n, vector<int>(m, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &grid[i][j]);
			if (grid[i][j] == 0) {
			}
		}
	}

	vector<move> movelist;

	int minVal = 1000;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			minVal = min(minVal, grid[i][j]);
		}
	}

	for (int re = 0; re < minVal; ++re) {
		for (int i = 0; i < min(n, m); ++i) {
			movelist.emplace_back((n < m) ,i);
		}
	}

	vector<vector<int>> redGrid(grid);

	int refRow = 0;
	int refCol = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			redGrid[i][j] -= minVal;
			if (redGrid[i][j] == 0) {
				refRow = i;
				refCol = j;
			}
		}
	}



	vector<int> addRow(n, 0);
	vector<int> addCol(m, 0);

	for (int i = 0; i < n; ++i) {
		addRow[i] = redGrid[i][refCol];
	}

	for (int j = 0; j < m; ++j) {
		addCol[j] = redGrid[refRow][j];
		//printf("predicted column %d to add %d\n", j, addCol[j]);
	}

	if (validateGuess(redGrid, addRow, addCol)) {
		for (int i = 0; i < n; ++i) {
			for (int mv = 0; mv < addRow[i]; ++mv) {
				movelist.emplace_back(true, i);
			}
		}
		for (int j = 0; j < m; ++j) {
			for (int mv = 0; mv < addCol[j]; ++mv) {
				movelist.emplace_back(false, j);
			}
		}
		printMoves(movelist);
	} else {
		printf("-1\n");
	}
	return 0;
}