#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

constexpr int NMAX = 1010;

char grid[NMAX][NMAX];
int distReached[NMAX][NMAX];
 
int n, m; 

char getCell(int i, int j) {
	if (i < 0 || n <= i || j < 0 || m <= j) return 'X';
	else return grid[i][j];
}

char invert(char c) {
//	printf("%c inverted becomes %c\n", c, ('0' + '1') - c);
	return ('0' + '1') - c;
}

int main() {
	int t; scanf("%d %d %d", &n, &m, &t);
	for (int i = 0; i < n; ++i) scanf("%s", grid[i]);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			bool isLoner = true;
			for (int mt = 0; mt < 4; ++mt) {
				int ni = i + dx[mt], nj = j + dy[mt];
				if (getCell(ni, nj) != 'X' && getCell(ni, nj) == getCell(i, j)) isLoner = false;
			}
			if (isLoner) distReached[i][j] = -1;
			else distReached[i][j] = 0;
		}
	}
	queue<pair<int, int>> q;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (distReached[i][j] == 0) {
				q.emplace(i, j);
			}
		}
	}
	while (!q.empty()) {
		int ci, cj;
		tie(ci, cj) = q.front(); q.pop();
		for (int mt = 0; mt < 4; ++mt) {
			int ni = ci + dx[mt], nj = cj + dy[mt];
			if (getCell(ni, nj) != 'X' && distReached[ni][nj] == -1) {
				distReached[ni][nj] = distReached[ci][cj] + 1;
				q.emplace(ni, nj);
			}
		}
	}
	for (int tc = 0; tc < t; ++tc) {
		int i, j; ll p; scanf("%d %d %lld", &i, &j, &p); --i; --j;
//		printf("dr %d %d %d\n", i, j, distReached[i][j]);
		if (distReached[i][j] == -1) {
			printf("%c\n", grid[i][j]);
		} else if (p < distReached[i][j]) {
			printf("%c\n", grid[i][j]);
		} else {
//			if ((p - distReached[i][j]) % 2 == 1) printf("THIS SHOULD INVERT\n");
			printf("%c\n", ((p - distReached[i][j]) % 2 == 0 ? grid[i][j] : invert(grid[i][j])));
		}
	}
	return 0;
}