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

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	int n;
	cin >> n;
	if (n == 1) {
		cout << "a" << endl;
		cout << "a" << endl;
		cout << "b" << endl;
		cout << "b" << endl;
		return 0;
	}
	char c[2];
	c[0] = 'a';
	c[1] = 'b';
	char c1[2];
	c1[0] = 'z';
	c1[1] = 'y';
	char c2[2];
	c2[0] = 'g';
	c2[1] = 'h';
	if (n % 2 == 0) {
		forn (i, n)
			cout << c[(i/2)&1];
		cout << endl;
		cout << "c";
		forn (i, (n-2))
			cout << c1[((i)/2)&1];
		cout << "d" << endl;
		cout << "c";
		forn (i, (n-2))
			cout << c2[((i)/2)&1];
		cout << "d" << endl;
		forn (i, n)
			cout << c[(i/2)&1];
		cout << endl;
	} else {
		cout << "c";
		forn (i, n-1)
			cout << c[(i/2)&1];
		cout << endl;
		cout << "c";
		forn (i, n-1)
			cout << c1[(i/2)&1];
		cout << endl;

		forn (i, n-1)
			cout << c2[(i/2)&1];
		cout << "d";
		cout << endl;

		forn (i, n-1)
			cout << c[(i/2)&1];
		cout << "d";
		cout << endl;
	}

	return 0;
}