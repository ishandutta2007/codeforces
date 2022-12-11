#include <bits/stdc++.h>

using namespace std;

// third parameter is 0 => exp 2; TP 1 => exp 5
int weight[1000][1000][2], vala[1000][1000][2];
char path[5000];

void findPath(int tp, int i, int j) {
	if (i > 0 && weight[i-1][j][tp] + vala[i][j][tp] == weight[i][j][tp]) {
		path[i+j-1] = 'D';
		findPath(tp, i-1, j);
	} else if (j > 0 && weight[i][j-1][tp] + vala[i][j][tp] == weight[i][j][tp]) {
		path[i+j-1] = 'R';
		findPath(tp, i, j-1);
	} else return;
}

int main() {
	int n; scanf("%d", &n);
	int zi = -1, zj = -1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			weight[i][j][0] = weight[i][j][1] = 1000000000;
			int x; 
			scanf("%d", &x);
			if (x == 0) {
				vala[i][j][0] = vala[i][j][1] = 1;
				zi = i, zj = j;
			} else {
				while (x % 2 == 0) {
					vala[i][j][0]++;
					x /= 2;
				}
				while (x % 5 == 0) {
					vala[i][j][1]++;
					x /= 5;
				}
			}
			for (int k = 0; k < 2; ++k) {
				if (i > 0) weight[i][j][k] = min(weight[i-1][j][k], weight[i][j][k]);
				if (j > 0) weight[i][j][k] = min(weight[i][j-1][k], weight[i][j][k]);
				if (weight[i][j][k] == 1000000000) weight[i][j][k] = 0;
				weight[i][j][k] += vala[i][j][k];
			}
		}
	}
	int bestExp = (weight[n-1][n-1][0] < weight[n-1][n-1][1] ? 0 : 1);
	if (weight[n-1][n-1][bestExp] > 1 && zi != -1) {
		// some zero exists
		printf("1\n");
		for (int i = 0; i < zi; ++i) printf("D");
		for (int j = 0; j < n-1; ++j) printf("R");
		for (int i = zi; i < n-1; ++i) printf("D");
		printf("\n");
		return 0;
	}
	printf("%d\n", weight[n-1][n-1][bestExp]);
	findPath(bestExp, n-1, n-1);
	printf("%s\n", path);
	return 0;
}