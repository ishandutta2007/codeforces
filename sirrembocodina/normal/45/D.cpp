#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <list>
#include <stack>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <memory.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = n - 1; i >= 0; i--)
#define forab(i, a, b) for(int i = a; i < b; i++)
#define fordab(i, a, b) for(int i = b - 1; i >= a; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define int64 long long       
#define ld long double
#define PI 3.1415926535897932
#define INF 1000000000
#define sqr(n) ((n) * (n))

vector<pair<pair<int, int>, int> > x;
vector<pair<int, int> > ans;
vector<bool> used;

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	if (a.fs.sc == b.fs.sc) {
		return a.fs.fs < b.fs.fs;
	} else {
		return a.fs.sc < b.fs.sc;
	}
}

int main() {
	int n;
	cin >> n;
	forn (i, n) {
		int a, b;
		cin >> a >> b;
		x.pb(mp(mp(a, b), i));
	}
	used.assign(n, false);
	forn (i, n) {
		int an;
		for (an = 0; used[an]; an++);
		forab (i, an + 1, n) {
			if (!used[i] && cmp(x[an], x[i])) {
				an = i;
			}
		}
		ans.pb(mp(x[an].sc, x[an].fs.sc));
		used[an] = true;
		forn (i, n) {
			if (used[i]) {
				continue;
			}
			x[i].fs.sc = min(x[i].fs.sc, x[an].fs.sc - 1);
		}
	}
	sort(ans.begin(), ans.end());
	forn (i, ans.size()) {
		cout << ans[i].sc << " ";
	}
}