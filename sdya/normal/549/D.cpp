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

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;
	vector < string > s(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	int res = 0;
	for (int i = 0; i + 1 < n; ++i) {
		res += (s[i][m - 1] != s[i + 1][m - 1]);
	}
	for (int i = 0; i + 1 < m; ++i) {
		res += (s[n - 1][i] != s[n - 1][i + 1]);
	}
	for (int i = 0; i + 1 < n; ++i) {
		for (int j = 0; j + 1 < m; ++j) {
			int cnt = 0;
			for (int a = 0; a < 2; ++a) {
				for (int b = 0; b < 2; ++b) {
					if (s[i + a][j + b] == 'W') {
						++cnt;
					}
				}
			}
			if (cnt == 0 || cnt == 4) {
				continue;
			}
			if (cnt == 2 && (s[i][j] == s[i + 1][j] || s[i][j] == s[i][j + 1])) {
				continue;
			}
			++res;
		}
	}

	printf("%d\n", res + 1);

	return 0;
}