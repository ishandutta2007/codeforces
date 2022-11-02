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
vector<pii> A;
int a[100500], b[100500];
int64 M;

int64 solve(int l, int r) {
	int pw = 0;
	for (int i = l + 1; i <= r; i ++)
		if (A[i].sc == A[i-1].sc) pw++;
	int n = r - l + 1;
	int64 res = 1;
	for (int i = 1; i <= n; i ++) {
		int64 x = i;
		while (pw > 0 && x % 2 == 0) {
			pw--;
			x /= 2;
		}
		res = res * x % M;
	}
	return res;	
}

int main ()
{
	cin >> n;
	forn(i, n)
		scanf("%d", &a[i]);
	forn(i, n)
		scanf("%d", &b[i]);
	A.clear();
	forn(i, n) {
		A.pb(mp(a[i], i));
		A.pb(mp(b[i], i));
	}
	cin >> M;
	sort(all(A));
	int l = 0;
	int64 res = 1;
	while (l < I A.size()) {
		int r = l;
		while (r + 1 < I A.size() && A[r+1].fs == A[l].fs) r++;
		res = res * solve(l, r) % M;		
		l = r + 1;
	}
	cout << res << endl;	
	return 0;
}