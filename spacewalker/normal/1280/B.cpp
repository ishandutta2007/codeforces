#include <bits/stdc++.h>

using namespace std;

char grid[70][70];

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int r, c; scanf("%d %d", &r, &c);
		for (int i = 0; i < r; ++i) {
			scanf("%s", grid[i]);
		}
		int bCount = 0;
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				if (grid[i][j] == 'A') bCount++;
			}
		}
		if (bCount == 0) {
			printf("MORTAL\n"); continue;
		} else if (bCount == r * c) {
			printf("0\n"); continue;
		}
		int ans = 4;
		if (grid[0][0] == 'A' || grid[0][c-1] == 'A' || grid[r-1][0] == 'A' || grid[r-1][c-1] == 'A') ans = min(ans, 2);
		int sumA = 0, sumB = 0;
		for (int i = 0; i < r; ++i) {
			if (grid[i][0] == 'A') ++sumA;
			if (grid[i][c-1] == 'A') ++sumB;
		}
		if (sumA == r || sumB == r) ans = min(ans, 1);
		if (sumA > 0 || sumB > 0) ans = min(ans, 3);
		sumA = 0, sumB = 0;
		for (int j = 0; j < c; ++j) {
			if (grid[0][j] == 'A') ++sumA;
			if (grid[r-1][j] == 'A') ++sumB;
		}
		if (sumA == c || sumB == c) ans = min(ans, 1);
		if (sumA > 0 || sumB > 0) ans = min(ans, 3);
		for (int i = 0; i < r; ++i) {
			bool allA = true;
			for (int j = 0; j < c; ++j) {
				if (grid[i][j] == 'P') allA = false;
			}
			if (allA) ans = min(ans, 2);
		}
		for (int j = 0; j < c; ++j) {
			bool allA = true;
			for (int i = 0; i < r; ++i) {
				if (grid[i][j] == 'P') allA = false;
			}
			if (allA) ans = min(ans, 2);
		}
		printf("%d\n", ans);
	}
	return 0;
}