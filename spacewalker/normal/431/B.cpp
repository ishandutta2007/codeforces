#include <algorithm>
#include <cstdio>
#include <vector>
#define MAX 5

using namespace std;

int main() {

	int hap[MAX][MAX] = {};
	for (int i = 0; i < MAX; ++i) {
		for (int j = 0; j < MAX; ++j) {
			scanf("%d", &hap[i][j]);
		}
	}

	int exH[MAX][MAX] = {};
	for (int i = 0; i < MAX; ++i) {
		for (int j = 0; j < MAX; ++j) {
			exH[i][j] = hap[i][j] + hap[j][i];
		}
	}

	
	vector<int> cPerm(MAX, 0);
	for (int i = 0; i < MAX; ++i) {
		cPerm[i] = i;
	}


	int maxSoFar = exH[0][1] + exH[1][2] + exH[2][3] * 2 + exH[3][4] * 2;
	for (;next_permutation(cPerm.begin(), cPerm.end());) {
		// 01234
		// 01 23 + 12 34 + 23 + 34
		int cHappiness = exH[cPerm[0]][cPerm[1]]
						 + exH[cPerm[1]][cPerm[2]]
						 + exH[cPerm[2]][cPerm[3]] * 2
						 + exH[cPerm[3]][cPerm[4]] * 2;
		maxSoFar = max(maxSoFar, cHappiness);
	}

	printf("%d", maxSoFar);
}