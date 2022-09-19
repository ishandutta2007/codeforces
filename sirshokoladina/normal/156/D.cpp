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
bool u[100010];

int dfs(int v) {
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

vector<int> c;

int main() {
	//freopen("input.txt", "rt", stdin)
	//freopen("output.txt", "wt", stdout)
	ll n, m, k;
	cin >> n >> m >> k;
	forn (i, m) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		e[x].pb(y);
		e[y].pb(x);
	}
	c.clear();
	forn (i, n) {
		int q = dfs(i);
		if (q) {
			c.pb(q);
		}
	}
	if (c.size() == 1) {
		cout << 1 % k;
		return 0;
	}
	ll ans = 1;
	forn (i, c.size()) {
		(ans *= c[i]) %= k;
	}
	forn (i, c.size() - 2) {
		(ans *= n) %= k;
	}
	cout << ans << endl;
	return 0;
}