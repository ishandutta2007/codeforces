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

char buf[200000];
vector <string> a;
vector <int> b;
string end[3][2];

void answer (string s) {
	cout << s << endl;
	exit (0); 
}

int calc (string s) {
	forn (i, 3)
		forn (j, 2)
			if (s.size() >= end[i][j].size() && 
				s.substr (s.size()-end[i][j].size()) == end[i][j])
				return i * 2 + j;
	answer ("NO");
	return -1;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	while (scanf ("%s", buf) > 0)
		a.pb ((string)buf);
	end[0][0] = "lios";
	end[0][1] = "liala";
	end[1][0] = "etr";
	end[1][1] = "etra";
	end[2][0] = "initis";
	end[2][1] = "inites";
	b.resize (a.size());
	forn (i, a.size())
		b[i] = calc (a[i]);
	if (b.size() == 1)
		answer ("YES");
	forn (i, b.size()-1)
		if ((b[i] % 2) != (b[i+1] % 2))
			answer ("NO");
	int cnt = 0;
	forn (i, b.size()) {
		b[i] /= 2;
		if (b[i] == 1)
			cnt ++;
		if (cnt > 1)
			answer ("NO");
	}
	if (cnt != 1)
		answer ("NO");
	forn (i, b.size()-1)
		if (b[i] > b[i+1])
			answer ("NO");
	answer ("YES");
	return 0;
}