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
#define all(a) a.begin(), a.end()
#define sqr(a) ((a) * (a))

typedef long double ld;
typedef long long ll;
typedef unsigned char uc;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ld pi = 3.141592653589793238462643l;

int n, m;
string s[1000];

bool u[1000][1000];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void dfs (int x, int y, int &k) {
	if (x < 0 || x >= n || y < 0 || y >= m) {
		return;
	}
	if (s[x][y] == '#' || u[x][y]) {
		return;
	}
	u[x][y] = 1;
	forn (i, 4) {
		dfs(x + dx[i], y + dy[i], k);
	}
	if (!k) {
		return;
	}
	k--;
	s[x][y] = 'X';
}

int main () {
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	int k;
	cin >> n >> m >> k;
	getline(cin, s[0]);
	forn (i, n) {
		getline(cin, s[i]);
	}
	int x = 0, y = 0;
	for (x = 0; x < n; ++x) {
		for (y = 0; y < m; ++y) {
			if (s[x][y] == '.') {
				break;
			}
		}
		if (y < m) {
			break;
		}
	}
	memset(u, 0, sizeof u);
	dfs(x, y, k);
	forn (i, n) {
		puts(s[i].c_str());
	}
	return 0;
}