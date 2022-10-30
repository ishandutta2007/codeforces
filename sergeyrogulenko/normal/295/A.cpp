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

int64 add[100500], sadd[100500];
int64 a[100500];
int n, m, k;
int64 l[100500], r[100500], d[100500], s[100500];

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n >> m >> k;
	forn(i, n)
		scanf("%I64d", &a[i]);
	forn(i, m)
		scanf("%I64d%I64d%I64d", &l[i], &r[i], &d[i]);
	seta(add, 0);
	seta(sadd, 0);
	forn(i, k) {
	        int x, y;
	        scanf("%d%d", &x, &y);
	        x--;
	        y--;
	        sadd[x]++;
	        sadd[y+1]--;
	}
	int64 scur = 0;
	forn(i, m) {
		scur += sadd[i];
		l[i]--;
		r[i]--;
		add[l[i]] += scur * d[i];
		add[r[i]+1] -= scur * d[i];
	}
	scur = 0;		
	forn(i, n) {
		scur += add[i];
		printf("%I64d ", scur + a[i]);
	}
	cout << endl;
	return 0;
}