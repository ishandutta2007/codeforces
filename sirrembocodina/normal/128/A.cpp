#include <iostream>
#include <vector>

using namespace std;

#define pb push_back
#define forn(i, n) for (int64 i = 0; i < int64(n); i++)
#define forab(i, a, b) for (int64 i = a; i < int64(b); i++)
#define all(a) a.begin(), a.end()
#define mp make_pair
#define fs first
#define sc second
#define divUp(a, b) ((a) % (b) ? (a) / (b) + 1 : (a) / (b))

typedef long long int64;

string a[8];

bool statue(int i, int j, int t) {
	i -= t; 
	if (i < 0) {
		return false;
	}
	return a[i][j] == 'S';
}

bool used[8][8][100];

void dfs(int i, int j, int t) {
	if (i < 0 || i > 7 || j < 0 || j > 7 || t > 100) {
		return;
	}
	cerr << i << " " << j << " " << t << endl;
	used[i][j][t] = true;
	forab (x, -1, 2) {
		forab (y, -1, 2) {
			if (i + x < 0 || i + x > 7 || j + y < 0 || j + y > 7 || t + 1 > 100) {
				continue;
			}
			if (!used[i + x][j + y][t + 1] && !statue(i + x, j + y, t) && !statue(i + x, j + y, t + 1)) {
				dfs(i + x, j + y, t + 1);
			}
		}
	}
}

int main() {
//	freopen("input.txt", "rt", stdin);
	forn (i, 8) {
		forn (j, 8) {
			forn (k, 100) {
				used[i][j][k] = false;
			}
		}
	}
	forn (i, 8) {
		cin >> a[i];
	}
	dfs(7, 0, 0);
	bool ok = false;
	forn (i, 100) {
		if (used[0][7][i]) {
			ok = true;
		}
	}
	cout << (ok ? "WIN" : "LOSE");
}