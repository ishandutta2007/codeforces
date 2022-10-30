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

int calc (char c1, char c2) {
	if (c1 == c2)
		return 0;
	string s = "";
	s += c1;
	s += c2;
	if (s == "RS" || s == "SP" || s == "PR")
		return 1;
	return -1;
}

pii go (string s, int ps, string t, int pt, int n) {
	pii res = mp (0, 0);
	ps = pt = 0;
	forn (i, n) {
		int x = calc (s[ps], t[pt]);
		ps ++;
		if (ps == s.length())
			ps = 0;
		pt ++;
		if (pt == t.length())
			pt = 0;
		if (x == 1)
			res.fs ++;
		if (x == -1)
			res.sc ++;				
	}
	return res;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	int n;
	string s, t;
	cin >> n;
	cin >> s >> t;	
	int ps, pt;
	ps = pt = 0;
	int d = s.length() * t.length();
	pii A = go (s, ps, t, pt, d);
	pii res;
	res.fs = A.fs * (n/d);
	res.sc = A.sc * (n/d);
	n %= d;
	A = go (s, ps, t, pt, n);
	res.fs += A.fs;
	res.sc += A.sc;
	cout << res.sc << " " << res.fs << endl;
	return 0;
}