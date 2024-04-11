#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
        
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = n - 1 ; i >= 0 ; i--)
#define forv(i, a) for (int i = 0; i < (int)(a.size()); i++)
#define forab(i, a, b) for (int i = a; i < (int)(b); i++)
#define fordab(i, a, b) for (int i = b - 1; i >= (int)(a); i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define pi 3.1415926535897932
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x))

typedef long long int64;       
typedef long double ld;

vector<int> to, d, s;
vector<bool> used;
vector<pair<pair<int, int>, int> > ans;
int n, m;

void dfs(int v, int st, int mn) {
	used[v] = true;
	if (to[v] != -1) {
		dfs(to[v], st, min(mn, d[v]));
	} else {
		if (v == st) {
			return;
		}
		ans.pb(mp(mp(st + 1, v + 1), mn));
	}
}

int main() {
	cin >> n >> m;
	to.assign(n, -1);
	d.resize(n);
	s.assign(n, 0);
	forn (i, m) {
		int x, y, z;
		cin >> x >> y >> z;
		x--;
		y--;
		to[x] = y;
		d[x] = z;
		s[y]++;
    }
    used.assign(n, false);
	forn (i, n) {
		if (!used[i] && s[i] == 0) {
			dfs(i, i, 2000000000);
		}
    }
    cout << ans.size() << endl;
    forv (i, ans) {
    	cout << ans[i].fs.fs << " " << ans[i].fs.sc << " " << ans[i].sc << endl;
    }
}