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

typedef long long int64;

pair<int, int> a[100100], b[100100];
vector<pair<int, int> > ans;

int main() {
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	y += x + 1;
	forn (i, n) {
		cin >> a[i].fs;
		a[i].fs -= x;
		a[i].sc = i;
	}
	sort(a, a + n);
	forn (i, m) {
		cin >> b[i].fs;
		b[i].sc = i;
	}
	sort(b, b + m);
	int beg = 0, end = 0;
	forn (i, n) {
		while (beg < m && b[beg].fs < a[i].fs) {
			beg++;
		}
		while (end < m && b[end].fs < a[i].fs + y) {
			end++;
		}
		if (end > beg) {
			ans.pb(mp(a[i].sc, b[beg].sc));
			beg++;
		}
	}
	cout << ans.size() << endl;
	forn (i, ans.size()) {
		cout << ans[i].fs + 1 << " " << ans[i].sc + 1 << endl;
	}
}