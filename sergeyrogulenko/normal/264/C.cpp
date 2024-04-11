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

int64 s[100500];
pair<int64, int> m1, m2;
int n;
pii a[100500];	
int64 p, q;

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	int m;
	scanf("%d%d", &n, &m);
	forn(i, n)
		scanf("%d", &a[i].fs);
	forn(i, n)
		scanf("%d", &a[i].sc);
	forn(i, n)
		a[i].sc--;
	forn(j, m) {
		int64 ans = 0;
		cin >> p >> q;
		m1 = mp(0LL, -1);
		m2 = mp(0LL, -2);
		seta(s, 128);
		forn(i, n) {
		        int col = a[i].sc;
			int64 cur = s[col] + p * a[i].fs;
			if (m1.sc == col)
				cur = max(cur, m2.fs + q * a[i].fs);
			else
				cur = max(cur, m1.fs + q * a[i].fs);
			if (s[col] < cur) {
				ans = max(ans, cur);
				if (col == m1.sc)
					m1.fs = cur;
				if (col == m2.sc)
					m2.fs = cur;
				if (m2.fs > m1.fs)
					swap(m1, m2);
				if (col != m1.sc && col != m2.sc) {
					if (cur > m1.fs) {
						m2 = m1;
						m1 = mp(cur, col);
					} else if (cur > m2.fs) {
						m2 = mp(cur, col);
					}
				}
				s[col] = cur;
			}
		}	
		cout << ans << endl;
	}						
	return 0;
}