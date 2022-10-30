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

int t[10][10];
int d[10][10];
int a[10][10];
int64 res;
int n, m, k;
int s[1024];

void go(int x, int y, int cmask, int64 w, int rem) {
	if (x == n) {
		res += w;
		return;
	}	
	int mask = 0;
	if (x > 0)
		mask |= t[x-1][y];
	if (y > 0)
		mask |= t[x][y-1];
	if (mask & d[x][y]) return;
	if (a[x][y] >= 0) {
	        t[x][y] = mask | (1 << a[x][y]);
		go(x + (y + 1) / m, (y + 1) % m, cmask, w, rem);
		return;
	}
	forn(i, k)
		if (!((mask|d[x][y]) & (1 << i)) && (cmask & (1 << i))) {
			t[x][y] = mask | (1 << i);
			go(x + (y + 1) / m, (y + 1) % m, cmask, w, rem);
		}
	forn(i, k)
		if (!((mask|d[x][y]) & (1 << i)) && !(cmask & (1 << i))) {
			t[x][y] = mask | (1 << i);
			go(x + (y + 1) / m, (y + 1) % m, cmask | (1 << i), w * rem, rem-1);
			break;
		}
} 

int64 calc(int cmask) {
	res = 0;
	int rem = k;
	forn(i, k)
		if (cmask & (1 << i))
			rem--;
	go(0, 0, cmask, 1, rem);
	return res;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n >> m >> k;
	if (n + m - 1 > k) {
		cout << 0 << endl;
		return 0;
	}
	forn(i, n)
		forn(j, m) {
			cin >> a[i][j];
			a[i][j]--;
		}
	int cmask = 0;
	ford(i, n)
		ford(j, m) {
			int mask = 0;
			if (a[i][j] != -1) {
				mask |= 1 << a[i][j];
			}
			cmask |= mask;
			if (i + 1 < n) {
				d[i][j] |= d[i+1][j];	
			}
			if (j + 1 < m) {
				d[i][j] |= d[i][j+1];	
			}
			if (d[i][j] & mask) {
				cout << 0 << endl;
				return 0;
			}
			d[i][j] |= mask;
		}
	cout << calc(cmask) % 1000000007 << endl;
	return 0;
}