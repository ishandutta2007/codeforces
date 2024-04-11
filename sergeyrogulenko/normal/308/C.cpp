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
int a[1005000], b[1005000];
multiset<int> S, T;

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n >> m;
	forn(i, n)
		scanf("%d", &a[i]);
	sort(a, a + n);
	forn(i, m)
		scanf("%d", &b[i]);
	forn(i, m)
		b[i] = 1 << b[i];
	sort(b, b + m);
	forn(i, n)
		S.insert(-a[i]);
	int res = 0;
	T.clear();
	ford(i, m) {
		if (S.size() > 0 && -(*S.begin()) >= b[i]) {
			res++;
			int v = -(*S.begin());
			S.erase(S.begin());
			T.insert(-b[i]);
			v -= b[i];
			if (v > 0)
				S.insert(-v);
		} else if (-(*T.begin()) >= b[i]) {
			int v = -(*T.begin());
			T.erase(T.begin());
			T.insert(-b[i]);
			v -= b[i];
			if (v > 0)
				S.insert(-v);
		}	
	}
	cout << res << endl;					
	return 0;
}