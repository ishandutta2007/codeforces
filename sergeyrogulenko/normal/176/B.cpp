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

const int64 P = 1000000007;

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	string s1, s2;
	cin >> s1 >> s2;
	s2 = s2 + s2;
	pair <int64, int64> A = mp (1LL, 0LL), B;
	int k;
	cin >> k;
	int n = s1.length();
	forn (i, k) {
		B.fs = A.sc * (n-1);
		B.sc = A.sc * (n-2) + A.fs;
		B.fs %= P;
		B.sc %= P;
		A = B;
	}	
	int64 ans = 0;
	forn (i, s1.length())
		if (s2.substr (i, s1.length()) == s1) {
			if (i == 0)
				ans += A.fs;
			else
				ans += A.sc;
		}
	ans %= P;
	cout << ans << endl;

	return 0;
}