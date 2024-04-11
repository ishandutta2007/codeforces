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

char s[200500];
int n;
int t[200500];
int best[26];
bool a[26][26];

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf ("%s%d", s, &n);
	seta (a, 1);
	forn (i, n) {
		string w;
		cin >> w;
		a[w[0]-'a'][w[1]-'a'] = 0;
		a[w[1]-'a'][w[0]-'a'] = 0;
	}
	seta (best, 0);
	seta (t, 0);
	int res = 0;
	n = strlen (s);
	for (int i = 0; i < n; i ++) {
		t[i] = 1;
		for (int j = 0; j < 26; j ++)
			if (a[j][s[i]-'a'])
				t[i] = max (t[i], best[j]+1);
		best[s[i]-'a'] = max (best[s[i]-'a'], t[i]);
		res = max (res, t[i]);
	}
	cout << n - res << endl;

	return 0;
}