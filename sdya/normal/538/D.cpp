#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 60;
char s[maxN][maxN];
char t[maxN][maxN];
int n;

bool ways[2 * maxN][2 * maxN];

bool valid(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", &s[i]);
	}

	for (int dx = - (n - 1); dx <= (n - 1); ++dx) {
		for (int dy = - (n - 1); dy <= (n - 1); ++dy) {
			if (dx == 0 && dy == 0) {
				continue;
			}

			bool isValid = true;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (!valid(i + dx, j + dy)) {
						continue;
					}
					if (s[i][j] != 'o') {
						continue;
					}
					if (s[i + dx][j + dy] == '.') {
						isValid = false;
					}
				}
			}
			if (isValid) {
				ways[maxN + dx][maxN + dy] = true;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (s[i][j] == 'o') {
				t[i][j] = 'o';
			} else {
				t[i][j] = '.';
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (t[i][j] != 'o') {
				continue;
			}
			for (int dx = - (n - 1); dx <= (n - 1); ++dx) {
				for (int dy = - (n - 1); dy <= (n - 1); ++dy) {
					if (ways[maxN + dx][maxN + dy] && valid(i + dx, j + dy) && t[i + dx][j + dy] == '.') {
						t[i + dx][j + dy] = 'x';
					}
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (t[i][j] != s[i][j]) {
				printf("NO\n");
				return 0;
			}
		}
	}

	printf("YES\n");
	for (int dx = - (n - 1); dx <= (n - 1); ++dx) {
		for (int dy = - (n - 1); dy <= (n - 1); ++dy) {
			if (dx == 0 && dy == 0) {
				printf("o");
			} else {
				if (ways[maxN + dx][maxN + dy]) {
					printf("x");
				} else {
					printf(".");
				}
			}
		}

		printf("\n");
	}



	return 0;
}