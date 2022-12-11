#include <bits/stdc++.h>

using namespace std;

map<int, int> getReassignment(vector<int> arr) {
	sort(begin(arr), end(arr));
	map<int, int> ans;
	for (int i = 0; i < arr.size(); ++i) {
		if (i == 0 || arr[i] != arr[i-1]) {
			int ita = ans.size() + 1;
 			ans[arr[i]] = ita;
		}
	}
	return ans;
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	vector<vector<int>> arr(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &arr[i][j]);
		}
	}
	vector<vector<int>> mapIfColumn(n, vector<int>(m)), mapIfRow(n, vector<int>(m));
	vector<int> rowSize(n), colSize(m);
	for (int i = 0; i < n; ++i) {
		map<int, int> rowRe = getReassignment(arr[i]);
		for (int j = 0; j < m; ++j) mapIfRow[i][j] = rowRe[arr[i][j]];
		rowSize[i] = rowRe.size();
	}
	for (int i = 0; i < m; ++i) {
		vector<int> curColumn(n);
		for (int j = 0; j < n; ++j) curColumn[j] = arr[j][i];
		map<int, int> colRe = getReassignment(curColumn);
		for (int j = 0; j < n; ++j) mapIfColumn[j][i] = colRe[arr[j][i]];
		colSize[i] = colRe.size();
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int rowPlace = mapIfRow[i][j], colPlace = mapIfColumn[i][j];
			int rowMax = rowSize[i], colMax = colSize[j];
//			printf("%d %d RP CP RM CM %d %d %d %d\n", i, j, rowPlace, colPlace, rowMax, colMax);
			if (rowPlace < colPlace) rowMax += colPlace - rowPlace;
			else colMax += rowPlace - colPlace;
			printf("%d ", max(rowMax, colMax));
		}
		printf("\n");
	}
	return 0;
}