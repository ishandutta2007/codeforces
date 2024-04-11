#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n < 3) {
		cout << "-1\n";
		return 0;
	}

	vector<vector<int>> a(n, vector<int>(n, 0));

	int cur = 1;
	int x = 0;
	int y = n - 1;
	for (int it = n - 1; it >= 3; it--) {
		for (int i = 0; i < it; i++) {
			a[y][x] = cur++;
			if (x < y) x++; else y++;
		}
		a[y][x] = cur++;
		if ((n - it) % 2) y--; else x--;
		for (int i = 1; i < it; i++) {
			a[y][x] = cur++;
			if (x < y) x--; else y--;
		}
		a[y][x] = cur++;
		if ((n - it) % 2) x--; else y--;
	}

	a[0][0] = cur++; a[0][1] = cur++; a[1][1] = cur++;
	a[0][2] = cur++; a[1][0] = cur++; a[2][1] = cur++;
	a[2][2] = cur++; a[1][2] = cur++; a[2][0] = cur++;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}