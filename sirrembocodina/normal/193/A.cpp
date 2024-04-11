#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

#define forab(i, a, b) for (int i = a; i < int(b); ++i)
#define fordab(i, a, b) for (int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab (i, 0, n)
#define ford(i, n) fordab (i, 0, n)
#define forv(i, a) forn (i, a.size())

typedef long long int64;

int n, m, k1;
string s[60];
bool used[60][60];

void clear() {
	forn (i, n) {
		forn (j, m) {
			used[i][j] = false;
		}
	}
}

void dfs(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m || s[x][y] == '.' || used[x][y]) {
		return;
	}
	used[x][y] = true;
	++k1;
	dfs(x - 1, y);
	dfs(x + 1, y);
	dfs(x, y - 1);
	dfs(x, y + 1);
}

int main() {
	cin >> n >> m;
	int k = 0;
	forn (i, n) {
		cin >> s[i];
		forn (j, m) {
			k += s[i][j] == '#';
		}
	}
	if (k <= 2) {
		cout << -1;
		return 0;
	}
	forn (i, n) {
		forn (j, m) {
			if (s[i][j] == '.') {
				continue;
			}
			s[i][j] = '.';
			clear();
			k1 = 0;
			forn (l, n) {
				forn (q, m) {
					if (s[l][q] == '#') {
						dfs(l, q);
						break;
					}
				}
				if (k1) {
					break;
				}
			}
			if (k1 != k - 1) {
				cout << 1;
				return 0;
			}
			s[i][j] = '#';
		}
	}
	cout << 2;
}