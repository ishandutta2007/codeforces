#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>

using namespace std;

#define forab(i, a, b) for (int i = a; i < (int)(b); i++)
#define fordab(i, a, b) for (int i = b - 1; i >= (int)(a); i--)
#define forn(i, n) forab (i, 0, n)
#define ford(i, n) fordab (i, 0, n)
#define forv(i, a) forn (i, a.size())
#define mp make_pair
#define fs first
#define sc second
#define pb push_back

bool g[5100][5100];
string str;
char h[5100];
short int mark[5100];
int n;
bool is = false;
vector<int> c, s;

void dfs(int v) {
	mark[v]++;
	s.pb(v);
	forn (i, n) {
		if (is) {
			return;
		}
		if (!g[v][i]) {
			continue;
		}
		if (mark[i] == 0) {
			dfs(i);
		} else if (mark[i] == 1) {
			while (s[s.size() - 1] != i) {
				c.pb(s[s.size() - 1]);
				s.pop_back();
			}
			c.pb(i);
			is = true;
			return;
		}
	}
	s.pop_back();
	mark[v]++;
}

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	cin >> n;
	if (n < 3) {
		cout << -1;
		return 0;
	}
	forn (i, n) {
		scanf("%s", &h);
		str = h;
		forn (j, n) {
			g[i][j] = (str[j] == '1');
		}
		mark[i] = 0;
	}
	forn (i, n) {
		if (!mark[i]) {
			dfs(i);
		}
		if (is) {
			break;
		}
	}
	vector<int> temp;
	for (int i = c.size() - 1; i >= 0; i--) {
		temp.pb(c[i]);
	}
	c = temp;
	if (!is) {
		cout << -1;
		return 0;
	}
	int m = c.size();
	for (int i = 2; i < m; i++) {
		if (g[c[i]][c[0]]) {
			cout << c[0] + 1 << " " << c[i - 1] + 1 << " " << c[i] + 1;
			return 0;
		}
	}
}