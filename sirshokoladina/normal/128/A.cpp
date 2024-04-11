#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)
#define ford(i,n) for (int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define S(i,j) ((i >= 0 && i < 8 && j >= 0 && j < 8) ? s[i][j] : '*')

string s[10];
int sx, sy, fx, fy;
int dx[3] = {-1, 0, 1};
bool u[10][10][10][2];

bool dfs(int x, int y, int l, int q) {
	if (S(x, y) == '*' || S(x - l, y) == 'S' || u[x][y][l][q]) {
		return 0;
	}
	if (x == fx && y == fy) {
		return 1;
	}
	if (l > 8) {
		return 1;
	}
	u[x][y][l][q] = 1;
	if (q) {
		forn (i, 3) {
			forn (j, 3) {
				if (dfs(x + dx[i], y + dx[j], l, 0)) {
					return 1;
				}
			}
		}
	} else {
		return dfs(x, y, l + 1, 1);
	}
	return 0;
}

int main() {
	forn (i, 8) {
		getline(cin, s[i]);
	}
	forn (i, 8) {
		forn (j, 8) {
			if (s[i][j] == 'M') {
				sx = i, sy = j;
			}
			if (s[i][j] == 'A') {
				fx = i, fy = j;
			}
		}
	}
	forn (i, 10) {
		forn (j, 10) {
			forn (k, 10) {
				forn (q, 2) {
					u[i][j][k][q] = 0;
				}
			}
		}
	}
	if (dfs(sx, sy, 0, 1)) {
		cout << "WIN\n";
	} else {
		cout << "LOSE\n";
	}
}