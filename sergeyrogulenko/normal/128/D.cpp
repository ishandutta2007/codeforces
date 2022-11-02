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

int n;
multiset <int> S;

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf ("%d", &n);
	forn (i, n) {
		int x;
		scanf ("%d", &x);
		S.insert (x);
	}
	int cur = *S.rbegin();
	int l = cur;
	int r = cur;
	S.erase (S.find (cur));
	while (S.size() > 0) {
		if (S.find (l+1) != S.end()) {
			l = l + 1;
			S.erase (S.find (l));
		} else 
		if (S.find (l-1) != S.end()) {
			l = l - 1;
			S.erase (S.find (l));
		} else {
			cout << "NO" << endl;
			return 0;
		}
		swap (l, r);
	}
	if (abs (l - r) != 1)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	return 0;
}