#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

#include <bitset>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <complex>
#include <queue>
#include <functional>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)
#define next NEXTHUI
#define prev PREVHUI
#define y1 Y1HUI

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "";

template <class T> T sqr (T x) {return x * x;}

int n, m;
set<pii> S;
vector<pii> a, ans;
double best;

double dist(pii p1, pii p2) {
	return hypot(p1.fs - p2.fs, p1.sc - p2.sc);
}

int main () {
//	freopen ((task + ".in").data(), "r", stdin);
//	freopen ((task + ".out").data(), "w", stdout);
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n >> m;
	S.clear();
	forn(i, 3)
		forn(j, 3)
			if (i <= n && j <= m) {
				S.insert(mp(i, j));
				S.insert(mp(n - i, m - j));
				S.insert(mp(n - i, j));
				S.insert(mp(i, m - j));
			}
	a = vector<pii>(all(S));
	best = -1;
	forn(i, a.size())
		forn(j, a.size()) if (j != i)
			forn(k, a.size()) if (k != i && k != j)
				forn(l, a.size()) if (l != i && l != j && l != k) {
					double ndist = dist(a[i], a[j]) + dist(a[j], a[k]) + dist(a[k], a[l]);
					if (ndist > best) {
						best = ndist;
						ans.clear();
						ans.pb(a[i]);
						ans.pb(a[j]);
						ans.pb(a[k]);
						ans.pb(a[l]);
					}
				}
	forn(i, 4)
		cout << ans[i].fs << " " << ans[i].sc << endl;
	return 0;
}