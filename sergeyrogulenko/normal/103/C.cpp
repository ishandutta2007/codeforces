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

int64 n, k;
int p;

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n >> k >> p;
	if (n == k) {
		forn (i, p)
			cout << "X";
		cout << endl;
		return 0;
	}
	int64 l, r;
	l = 1;
	r = n;
	if (n < k*2) {
		int64 a = k*2-n;
		r -= a;
		n -= a;
		k -= a;
	}
	if ((n - k * 2) & 1) {
		n --;
		r --;
		k --;
	}
	if (n > k*2) {
		l += n-k*2;
		n = k*2;
	}
	forn (i, p) {
		int64 x;
		cin >> x;
		if (x < l)
			cout << ".";
		else
		if (x > r)
			cout << "X";
		else {
			if ((x-l)&1)
				cout << "X";
			else
				cout << ".";
		}
	}
	cout << endl;
	return 0;
}