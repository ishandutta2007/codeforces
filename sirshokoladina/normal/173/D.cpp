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

vector<int> e[100010];
int c[100010];

void dfs(int x, int q, vector<int> *v) {
	if (c[x] != -1) {
		return;
	}
	c[x] = q;
	v[q].pb(x);
	forn (i, e[x].size()) {
		dfs(e[x][i], q ^ 1, v);
	}
}

int n;
int u[100010];

bool solve(vector<int> v[][2]) {
	for (int i = 1; i < 3; i++)  {
		forn (q, 2) {
			forn (j, v[i][q].size()) {
				v[0][q].pb(v[i][q][j]);
			}
		}
	}
	if (v[0][0].size() % 3 == 2) {
		swap(v[0][0], v[0][1]);
	}
	memset(u, 0, sizeof u);
	int k = 0;
	forn (i, n) {
		c[i] = -1;
	}
	int ii;
	if (v[0][0].size() % 3) {
		for (ii = 0; ii < v[0][0].size(); ii++) {
			if (e[v[0][0][ii]].size() < v[0][1].size() - 1) {
				break;
			}
		}
		if (ii < v[0][0].size()) {
			u[v[0][0][ii]] = 1;
			k = 1;
			c[v[0][0][ii]] = 0;
			forn (i, v[0][1].size()) {
				u[v[0][1][i]] = 1;
			}
			forn (i, e[v[0][0][ii]].size()) {
				u[e[v[0][0][ii]][i]] = 0;
			}
			int qwe = 0;
			forn (i, v[0][1].size()) {
				if (u[v[0][1][i]]) {
					if (qwe < 2) {
						c[v[0][1][i]] = 0;
					} else {
						u[v[0][1][i]] = 0;
					}
					qwe++;
				}
			}
		} else {
			for (ii = 0; ii < v[0][1].size(); ii++) {
				if (e[v[0][1][ii]].size() < v[0][0].size() - 1) {
					break;
				}
			}
			int jj = ii;
			for (ii = jj + 1; ii < v[0][1].size(); ii++) {
				if (e[v[0][1][ii]].size() < v[0][0].size() - 1) {
					break;
				}
			}
			if (ii < v[0][1].size()) {
				u[v[0][1][ii]] = 1;
				u[v[0][1][jj]] = 1;
				k = 2;
				c[v[0][1][ii]] = 0;
				c[v[0][1][jj]] = 1;
				forn (i, v[0][0].size()) {
					u[v[0][0][i]] = 2;
				}
				forn (i, e[v[0][1][ii]].size()) {
					u[e[v[0][1][ii]][i]]--;
				}
				int qwe = 0;
				forn (i, v[0][0].size()) {
					if (u[v[0][0][i]] == 2) {
						if (qwe < 2) {
							c[v[0][0][i]] = 0;
						} else {
							u[v[0][0][i]]--;
						}
						qwe++;
					}
				}
				forn (i, e[v[0][1][jj]].size()) {
					u[e[v[0][1][jj]][i]]--;
				}
				qwe = 0;
				forn (i, v[0][0].size()) {
					if (u[v[0][0][i]] && c[v[0][0][i]] == -1) {
						if (qwe < 2) {
							c[v[0][0][i]] = 1;
						} else {
							u[v[0][0][i]]--;
						}
						qwe++;
					}
				}
			} else {
				return 0;
			}
		}
	}
	int l = 0;
	forn (i, v[0][0].size()) {
		if (!u[v[0][0][i]]) {
			c[v[0][0][i]] = k;
			l++;
			if (l == 3) {
				k++;
				l = 0;
			}
		}
	}
	forn (i, v[0][1].size()) {
		if (!u[v[0][1][i]]) {
			c[v[0][1][i]] = k;
			l++;
			if (l == 3) {
				k++;
				l = 0;
			}
		}
	}
	puts("YES");
	forn (i, n) {
		printf("%d", c[i] + 1);
		if (i < n - 1) {
			printf(" ");
		}
	}
	puts("");
	return 1;
}

vector<int> v[100010][2], w[3][2];

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	int m;
	cin >> n >> m;
	forn (i, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		e[x].pb(y);
		e[y].pb(x);
	}
	memset(c, -1, sizeof c);
	int k = 0;
	forn (i, n) {
		dfs(i, 0, v[k]);
		if (v[k][0].size()) {
			k++;
		}
	}
	int ii;
	for (ii = 0; ii < k; ii++) {
		if ((v[ii][0].size() - v[ii][1].size()) % 3) {
			break;
		}
	}
	if (ii < k) {
		swap(v[0][0], v[ii][0]);
		swap(v[0][1], v[ii][1]);
	}
	for (ii = 1; ii < k; ii++) {
		if ((v[ii][0].size() - v[ii][1].size()) % 3) {
			break;
		}
	}
	if (ii < k) {
		swap(v[1][0], v[ii][0]);
		swap(v[1][1], v[ii][1]);
	}
	for (int i = 3; i < k; i++) {
		forn (q, 2) {
			forn (j, v[i][q].size()) {
				v[2][q].pb(v[i][q][j]);
			}
		}
	}
	bool b[3];
	int x[3][2];
	forn (i, 3) {
		forn (q, 2) {
			x[i][q] = v[i][q].size() % 3;
		}
		b[i] = (x[i][0] != x[i][1]);
	}
	forn (mask, 4) {
		bool I[3];
		forn (i, 3) {
			I[i] = (mask & (1 << i));
		}
		forn (i, 3) {
			forn (q, 2) {
				w[i][q] = v[i][q ^ I[i]];
			}
		}
		if (solve(w)) {
			return 0;
		}
	}
	puts("NO");
	return 0;
}