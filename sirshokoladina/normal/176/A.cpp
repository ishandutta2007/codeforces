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

int a[200][200], b[200][200], c[200][200];

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	forn (i, n) {
		string s;
		cin >> s;
		forn (j, m) {
			cin >> a[i][j];
			cin >> b[i][j];
			cin >> c[i][j];
		}
	}
	int ans = 0;
	forn (i1, n) {
		forn (i2, n) {
			vector<pair<int, int> > q(0);
			forn (j, m) {
				if (b[i2][j] > a[i1][j]) {
					q.pb(mp(a[i1][j] - b[i2][j], c[i1][j]));
				}
			}
			sort(q.begin(), q.end());
			int t = 0;
			int s = 0;
			forn (j, q.size()) {
				int e = min(k - t, q[j].sc);
				s -= e * q[j].fs;
				t += e;
			}
			ans = max(ans, s);
		}
	}
	cout << ans;
	return 0;
}