#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int maxN = 20;
char s[maxN][maxN];
int a[maxN][maxN];
int n, m;

int dx[] = {-1, 0, 0, 1};
int dy[] = { 0,-1, 1, 0};

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	int res = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == 'P') {
				for (int k = 0; k < 4; ++k) {
					int x = i + dx[k];
					int y = j + dy[k];
					if (x >= 0 && x < n && y >= 0 && y < m && s[x][y] == 'W') {
						++a[x][y];
					}
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j]) ++res;
		}
	}
	cout << res << endl;
	return 0;
}