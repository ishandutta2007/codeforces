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

bool solve();

int main() {
	solve();
}

#define int ll

pair<pair<int, int>, int> a[100000];

vector<int> ans[100000];
bool u[100000];

bool solve() {
	//freopen("input.txt", "rt", stdin)
	//freopen("output.txt", "wt", stdout)
	int n, k;
	cin >> n >> k;
	int t = 0, p = 0, s = 0;
	forn (i, n) {
		cin >> a[i].fs.fs >> a[i].fs.sc;
		a[i].sc = i;
		t += (a[i].fs.sc == 1);
		p += (a[i].fs.sc == 2);
		s += a[i].fs.fs;
	}
	memset(u, 0, sizeof u);
	int w = 0;
	if (t >= k) {
		sort(a, a + n);
		int t1 = 0;
		for (int i = n - 1; t1 < k; i--) {
			if (a[i].fs.sc == 1) {
				ans[t1].pb(a[i].sc);
				u[a[i].sc] = 1;
				t1++;
				if (t1 != k) {
					w += a[i].fs.fs;
				}
			}
		}
		w += a[0].fs.fs;
		forn (i, n) {
			if (!u[i]) {
				ans[k - 1].pb(i);
			}
		}
	} else {
		int t1 = 0;
		forn (i, n) {
			if (a[i].fs.sc == 1) {
				ans[t1].pb(a[i].sc);
				u[a[i].sc] = 1;
				t1++;
				w += a[i].fs.fs;
			}
		}
		forn (i, n) {
			if (!u[i]) {
				ans[t1].pb(a[i].sc);
				if (t1 + 1 < k) {
					t1++;
				}
			}
		}
	}
	cout << (2 * s - w) / 2 << '.' << 5 * ((2 * s - w) % 2) << endl;
	forn (i, k) {
		cout << ans[i].size();
		forn (j, ans[i].size()) {
			cout << ' ' << ans[i][j] + 1;
		}
		cout << endl;
	}
	return 0;
}