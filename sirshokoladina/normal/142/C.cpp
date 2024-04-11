#pragma comment(linker, "/STACK:32000000")
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <memory.h>
#include <ctime>
#include <cctype>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define mp make_pair
#define fs first
#define sc second
#define pb push_back

typedef long double ld;
typedef long long ll;
typedef unsigned char uc;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ld PI = 3.141592653589793238462643l;

bool fig[5][3][3] = {
	{
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	}, {
		{1, 1, 1},
		{0, 1, 0},
		{0, 1, 0}
	}, {
		{0, 0, 1},
		{1, 1, 1},
		{0, 0, 1}
	}, {
		{0, 1, 0},
		{0, 1, 0},
		{1, 1, 1}
	}, {
		{1, 0, 0},
		{1, 1, 1},
		{1, 0, 0}
	}
};

typedef pair<int, vi> Pr;
typedef pair<int, Pr> Ans;

map<pii, Ans> ans;

int m;

Ans make(int n, int msk) {
	pii pr = mp(n, msk);
	if (ans.count(pr)) {
		return ans[pr];
	}
	Ans res = mp(0, mp(0, vi(0)));
	if (n == 0) {
		ans[pr] = res;
		return res;
	}
	vector<vector<vi> > fil(m - 1);
	fil[0] = vector<vi>(1);
	forn (i, m - 2) {
		forn (k, fil[i].size()) {
			forn (t, 5) {
				bool ok = 1;
				forn (dx, 2) {
					forn (dy, 3) {
						if (fig[t][dx][dy] && (msk & (1 << (dx * m + i + dy)))) {
							ok = 0;
						}
					}
				}
				forn (s, 3) {
					if (i > 0) {
						if (fig[t][s][0] && fig[fil[i][k][i - 1]][s][1]) {
							ok = 0;
						}
						if (fig[t][s][1] && fig[fil[i][k][i - 1]][s][2]) {
							ok = 0;
						}
					}
					if (i > 1) {
						if (fig[t][s][0] && fig[fil[i][k][i - 2]][s][2]) {
							ok = 0;
						}
					}
				}
				if (ok) {
					vi newv = fil[i][k];
					newv.pb(t);
					fil[i + 1].pb(newv);
				}
			}
		}
	}
	forn (i, fil[m - 2].size()) {
		int msk1 = msk >> m;
		int c = 0;
		forn (j, m - 2) {
			if (fil[m - 2][i][j]) {
				c++;
			}
			forn (x, 2) {
				forn (y, 3) {
					if (fig[fil[m - 2][i][j]][x + 1][y]) {
						msk1 += (1 << (x * m + j + y));
					}
				}
			}
		}
		Ans res1 = mp(c + make(n - 1, msk1).fs, mp(msk1, fil[m - 2][i]));
		res = max(res, res1);
	}
	ans[pr] = res;
	return res;
}

int main() {
	//freopen("input.txt", "rt", stdin)
	//freopen("output.txt", "wt", stdout)
	int n;
	cin >> n >> m;
	if (n < 3 || m < 3) {
		cout << 0 << endl;
		forn (i, n) {
			forn (j, m) {
				cout << '.';
			}
			cout << endl;
		}
		return 0;
	}
	Ans res = make(n - 2, 0);
	int ret = res.fs;
	vector<vector<char> > c(n, vector<char>(m, '.'));
	int k = 0;
	forn (i, n - 2) {
		forn (j, m - 2) {
			forn (x, 3) {
				forn (y, 3) {
					if (fig[res.sc.sc[j]][x][y]) {
						c[i + x][j + y] = 'A' + k;
					}
				}
			}
			if (res.sc.sc[j]) {
				k++;
			}
		}
		res = ans[mp(n - 3 - i, res.sc.fs)];
	}
	cout << ret << endl;
	forn (i, n) {
		forn (j, m) {
			cout << c[i][j];
		}
		cout << endl;
	}
	return 0;
}