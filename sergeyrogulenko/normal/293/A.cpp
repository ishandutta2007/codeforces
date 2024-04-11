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

int n;
int c[2][2];
char s[2005000];
char t[2005000];
int x[2];

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n;
	scanf("%s", s);
	scanf("%s", t);
	seta(c, 0);
	forn(i, n*2)
		c[s[i]-'0'][t[i]-'0']++;
	seta(x, 0);
	forn(i, n*2) {
		int v = i & 1;
		if (c[1][1] > 0) {
			c[1][1]--;
			x[v]++;
		} else {
			if (v == 0) {
				if (c[1][0] > 0) {
					x[0]++;
					c[1][0]--;
				} else if (c[0][1] > 0) {
					c[0][1]--;
				} else
					c[0][0]--;
			} else {
				if (c[0][1] > 0) {
					x[1]++;
					c[0][1]--;
				} else if (c[1][0] > 0) {
					c[1][0]--;
				} else
					c[0][0]--;
			}
		}
	}
	if (x[0] > x[1])
		cout << "First" << endl;
	else if (x[0] < x[1])
		cout << "Second" << endl;
	else
		cout << "Draw" << endl;					
	return 0;
}