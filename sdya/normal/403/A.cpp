#define _CRT_SECURE_NO_WARNINGS
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
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

bool isGood(vector < vector < bool > > used, int p) {
	int n = used.size();
	for (int i = 0; i < (1 << n); ++i) {
		int cnt = 0, m = 0;
		for (int j = 0; j < n; ++j) {
			if (i & (1 << j)) {
				++cnt;

				for (int k = j + 1; k < n; ++k) {
					if ((i & (1 << k)) && used[j][k]) {
						++m;
					}
				}
			}
		}
		if (m > cnt * 2 + p) {
			return false;
		}
	}
	return true;
}

void solve(int n, int p) {
	vector < vector < bool > > used(n, vector < bool > (n, false));
	for (int i = 0; i < n; ++i) {
		int x = i % n;
		int y = (i + 1) % n;
		int z = (i + 2) % n;
		printf("%d %d\n", x + 1, y + 1);
		printf("%d %d\n", x + 1, z + 1);
		used[x][y] = used[y][x] = true;
		used[x][z] = used[z][x] = true;
	}

	for (int i = 0; i < p; ++i) {
		while (true) {
			int u = rand() % n;
			int v = rand() % n;
			if (u == v || used[u][v]) {
				continue;
			}
			printf("%d %d\n", u + 1, v + 1);
			used[u][v] = used[v][u] = true;
			break;
		}
	}
	return;
	if (!isGood(used, p)) {
		cerr << n << " " << p << ": BAD" << endl;
		exit(0);
	} else {
		cerr << n << " " << p << ": GOOD" << endl;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	/*for (int n = 5; n <= 24; ++n) {
		for (int p = 0; 2 * n + p <= n * (n - 1) / 2; ++p) {
			solve(n, p);
		}
	}*/

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n, p;
		scanf("%d%d", &n, &p);
		solve(n, p);
	}


	return 0;
}