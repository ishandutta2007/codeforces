#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

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

template <class T> T sqr (T x) {return x * x;}

int n, m, k;
string name[100];
int a[100][100], b[100][100], c[100][100];
vector <pii> A;

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n >> m >> k;
	forn (i, n) {
		cin >> name[i];
		forn (j, m)
			cin >> a[i][j] >> b[i][j] >> c[i][j];
	}		
	int res = 0;
	forn (i, n)
		forn (j, n)
			if (i != j) {
				A.clear ();
				forn (l, m)
					if (b[i][l] - a[j][l] > 0)
						A.pb (mp (b[i][l] - a[j][l], c[j][l]));
				sort (all (A));
				reverse (all (A));
				int cnt = 0;
				int K = k;
				forn (l, A.size()) {
					int d = min (K, A[l].sc);
					cnt += d * A[l].fs;
					K -= d;
				}
				res = max (res, cnt);
			}
	cout << res << endl;
	return 0;
}