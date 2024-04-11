#pragma comment(linker, "/STACK:600000000")
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

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

const int dx[4] = {1, -1, 1, -1};
const int dy[4] = {1, -1, -1, 1};
int n, m;
bool u[10000000][4];

int ok (int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void go (int x, int y) {
	if (u[x][y])
		return;
	u[x][y] = 1;
	int X, Y;
	X = Y = 0;
	if (y & 1) {
		X = n-1;
		Y = m-1;
	}
	if (y & 2)
		Y = x;
	else
		X = x;
	forn (i, 4) {
		int l;
		if (i == 0) 
			l = min (n-1-X, m-1-Y);
		else if (i == 1) 
			l = min (X, Y);
		else if (i == 2)
			l = min (n-1-X, Y);
		else
			l = min (X, m-1-Y);
		int x1 = X + dx[i] * l;
		int y1 = Y + dy[i] * l;
		int tp, w;
		
		if (y1 == 0) {
			tp = 0;
			w = x1;
		}
		else 
		if (y1 == m-1) {
			tp = 1;
			w = x1;
		} else
		if (x1 == 0) {
			tp = 2;
			w = y1;
		}
		else 
		if (x1 == n-1) {
			w = y1;
			tp = 3;
		}
		go (w, tp);
	}
}

int main ()
{
	cin >> n >> m;
	if (n > m)
		swap (n, m);
	seta (u, 0);
	int res = 0;
	forn (i, n)
		forn (j, 2)
			if (!u[i][j]) {
				go (i, j);
				res ++;
			}
	for (int i = 1; i < m-1; i ++)	
		forn (j, 2)
			if (!u[i][j+2]) {
				go (i, j);
				res ++;
			}
	cout << res << endl;
	return 0;
}