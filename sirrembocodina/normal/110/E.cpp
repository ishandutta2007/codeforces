#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <list>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
        
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forv(i, n) forn (i, n.size())
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define ld long double
#define pi 3.1415926535897932
#define all(a) a.begin(), a.end()

typedef long long int int64;

vector<vector<int> > g;
vector<int> c;
vector<bool> used;

bool lucky(int a) {
	if (a == 0) {
		return false;
	}
	while (a) {
		if ((a % 10 != 4) && (a % 10 != 7)) {
			return false;
		}
		a /= 10;
	}
	return true;
}

void dfs(int v) {
	used[v] = true;
	c[c.size() - 1]++;
	forv (i, g[v]) {
		if (!used[g[v][i]]) {
			dfs(g[v][i]);
		}
	}
}

int main() {
	int n;
	cin >> n;
	g.resize(n);
	forn (i, n - 1) {
		int x, y, z;
		cin >> x >> y >> z;
		if (lucky(z)) {
			continue;
		}
		x--;
		y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	used.assign(n, false);
	forn (i, n) {
		if (!used[i]) {
			c.pb(0);
			dfs(i);
		}
	}
	int64 ans = 0;
	forv (i, c) {
		ans += int64(c[i]) * int64(n - c[i]) * int64(n - c[i] - 1);
	}
	cout << ans;
}