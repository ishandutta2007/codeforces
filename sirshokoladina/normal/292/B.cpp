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

vector<int> e[100010];

bool u[100010];

int dfs (int v) {
	if (u[v]) {
		return 0;
	}
	u[v] = 1;
	int ans = 1;
	forn (i, e[v].size()) {
		ans += dfs(e[v][i]);
	}
	return ans;
}

int main () {
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	int n, m;
	cin >> n >> m;
	forn (i, m) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		e[x].pb(y);
		e[y].pb(x);
	}
	int mx = 0;
	forn (i, n) {
		mx = max(mx, (int)e[i].size());
	}
	memset(u, 0, sizeof u);
	if (dfs(0) != n) {
		puts("unknown topology");
		return 0;
	}
	if (m == n - 1 && mx == n - 1) {
		puts("star topology");
		return 0;
	}
	if (m == n && mx == 2) {
		puts("ring topology");
		return 0;
	}
	if (m == n - 1 && mx == 2) {
		puts("bus topology");
		return 0;
	}
	puts("unknown topology");
	return 0;
}