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

int n, m;
set <int> S[100500];
vector <int> divs[100500];
bool on[100500];

vector <int> factor (int n) {
	vector <int> res;
	for (int i = 2; i * i <= n; i ++)
		if (n % i == 0) {
			res.pb (i);
			while (n % i == 0)
				n /= i;
		}
	if (n > 1)
		res.pb (n);
	return res;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
		divs[i] = factor (i);
	seta (on, 0);
	forn (i, m) {
		char c;
		int x;
		scanf (" %c %d", &c, &x);
		if (c == '-') {
			if (!on[x]) 
				printf ("Already off\n");
			else {
				printf ("Success\n");
				forn (j, divs[x].size())
					S[divs[x][j]].erase (x);
				on[x] = 0;
			}
		} else {
			if (on[x]) 
				printf ("Already on\n");
			else {
				int ok = 0;
				forn (j, divs[x].size())
					if (S[divs[x][j]].size() > 0)
						ok = *S[divs[x][j]].begin();
				if (ok)
					printf ("Conflict with %d\n", ok);
				else {
					on[x] = 1;
					forn (j, divs[x].size())
						S[divs[x][j]].insert (x);
					printf ("Success\n");
				}
			}
		}
	}
	return 0;
}