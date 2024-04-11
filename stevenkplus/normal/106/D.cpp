#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1010;
const int MAXQ = 100100;
const int MAXC = 1010;
int csums[MAXN][MAXN];
int rsums[MAXN][MAXN];
char grid[MAXN][MAXN];
bool works[MAXC];

bool rowempt(int row, int x1, int x2) {
	if (x1 > x2) swap(x1, x2);
	return rsums[row][x2 + 1] == rsums[row][x1];
}

bool colempt(int col, int x1, int x2) {
	if (x1 > x2) swap(x1, x2);
	return csums[col][x2 + 1] == csums[col][x1];
}

int N, M, Q;

int numq = 0;
int xmoves[MAXQ];
int ymoves[MAXQ];

void put(char dir, int steps) {
	if (dir == 'N') {
		xmoves[numq] = -steps;
	} else if (dir == 'S') {
		xmoves[numq] = steps;
	} else if (dir == 'E') {
		ymoves[numq] = steps;
	} else if (dir == 'W') {
		ymoves[numq] = -steps;
	}
	++numq;
}

void check(int x, int y) {
	char c = grid[x][y];
	for(int i = 0; i < Q; ++i) {
		int nx = x + xmoves[i];
		int ny = y + ymoves[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) return;
		if (rowempt(x, y, ny) && colempt(y, x, nx)) {
			x = nx;
			y = ny;
		} else return;
	}
	works[c] = true;
}

int main() {
	scanf("%d %d", &N, &M);

	for(int i = 0; i < N; ++i) {
		scanf("%s", grid[i]);
	}
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			int add = grid[i][j] == '#';
			rsums[i][j + 1] = rsums[i][j] + add;
		}
	}
	for(int j = 0; j < M; ++j) {
		for(int i = 0; i < N; ++i) {
			int add = grid[i][j] == '#';
			csums[j][i + 1] = csums[j][i] + add;
		}
	}

	scanf("%d", &Q);
	for(int i = 0; i < Q; ++i) {
		char c;
		int steps;
		scanf(" %c %d", &c, &steps);
		put(c, steps);
	}

	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			if (grid[i][j] != '#' && grid[i][j] != '.') {
				check(i, j);
			}
		}
	}

	bool nosol = true;
	for(char c = 'A'; c <= 'Z'; ++c) {
		if (works[c]) {
			nosol = false;
			printf("%c", c);
		}
	}
	if (nosol) {
		printf("no solution");
	}

	printf("\n");
	return 0;
}