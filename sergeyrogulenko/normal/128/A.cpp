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

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

char a[10][10];
int n;
bool u[10][10][100];
int qx[10000], qy[10000], qz[10000];
const int dx[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
const int dy[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	n = 8;
	forn (i, n)
		forn (j, n)
			scanf (" %c", &a[i][j]);
	a[n-1][0] = a[0][n-1] = '.';
	seta (u, 0);
	int h, t;
	h = t = 0;
	u[n-1][0][0] = 1;
	qx[h] = n-1;
	qy[h] = 0;
	qz[h] = 0;
	while (h <= t) {
		int x, y, z;
		x = qx[h];
		y = qy[h];
		z = qz[h];
		h ++;
		forn (i, 9) {
			int vx = x + dx[i];
			int vy = y + dy[i];
			int vz = z + 1;
			if (vz >= 100)
				continue;
			if (0 <= vx && vx < n && 0 <= vy && vy < n) {
				int px1 = vx - z;
				int px2 = vx - vz;
				if (px1 >= 0 && a[px1][vy] == 'S')
					continue;
				if (px2 >= 0 && a[px2][vy] == 'S')
					continue;
				if (!u[vx][vy][vz]) {
					u[vx][vy][vz] = 1;
					t ++;
					qx[t] = vx;
					qy[t] = vy;
					qz[t] = vz;
				}
			}
		}
	}
	if (u[0][n-1][99])
		cout << "WIN" << endl;
	else
		cout << "LOSE" << endl;
	return 0;
}