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

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define int64 long long       
#define ld long double
#define pi 3.1415926535897932
#define all(a) a.begin(), a.end()

vector<pair<int, int> > d;
bool a[8][8];

void f(int x, int y) {
	forn (i, d.size()) {
		if (x + d[i].fs < 0 || x + d[i].fs >= 8 || y + d[i].sc < 0 || y + d[i].sc >= 8) {
			continue;
		}
		a[x + d[i].fs][y + d[i].sc] = true;
	}
}

int main() {
	d.pb(mp(1, 2));
	d.pb(mp(1, -2));
	d.pb(mp(-1, 2));
	d.pb(mp(-1, -2));
	d.pb(mp(2, 1));
	d.pb(mp(2, -1));
	d.pb(mp(-2, 1));
	d.pb(mp(-2, -1));
	d.pb(mp(0, 0));
	forn (i, 8) {
		forn (j, 8) {
			a[i][j] = false;
		}
	}
	char c1, c2;
	cin >> c1 >> c2;
	f(c1 - 'a', c2 - '1');
	forn (i, 8) {
		a[c1 - 'a'][i] = true;
		a[i][c2 - '1'] = true;
	}
	cin >> c1 >> c2;
	f(c1 - 'a', c2 - '1');
	int ans = 0;
	forn (i, 8) {
		forn (j, 8) {
			ans += int(!a[i][j]);
		}
	}
	cout << ans;
}