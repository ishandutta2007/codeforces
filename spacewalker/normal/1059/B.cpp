#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

char grid[2000][2000];
char attempt[2000][2000];

int a, b;

bool reverse3x3(int i, int j) {
	i = min(i, a-3), j = min(j, b-3);
	for (int x = 0; x < 3; ++x) {
		for (int y = 0; y < 3; ++y) {
			// printf("working cell %d %d\n", x, y);
			if (x == 1 && y == 1) continue;
			if (grid[i+x][j+y] != '#') return false;
			attempt[i+x][j+y] = '#';
		}
	}
	// printf("here\n");
	return true;
}

int main() {
	scanf("%d %d", &a, &b);
	for (int i = 0; i < a; ++i) {
		scanf("%s", grid[i]);
		for (int j = 0; j < b; ++j) {
			// printf("grid c: %c\n", grid[i][j]);
			attempt[i][j] = '.';
		}
	}
	for (int i = 1; i < a - 1; ++i) {
		for (int j = 1; j < b - 1; ++j) {
			bool allFilled = true;
			for (int x = 0; x < 3; ++x) {
				for (int y = 0; y < 3; ++y) {
					if (x == 1 && y == 1) continue;
					if (grid[i+x-1][j+y-1] == '.') allFilled = false;
				}
			}
			// printf("center %d %d filled: %d\n", i, j, allFilled);
			if (!allFilled) continue;
			for (int x = 0; x < 3; ++x) {
				for (int y = 0; y < 3; ++y) {
					if (x == 1 && y == 1) continue;
					attempt[i+x-1][y+j-1] = '#';
				}
			}
		}
	}
	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) {
			if (grid[i][j] != attempt[i][j]) {
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	return 0;
	return 0;
}