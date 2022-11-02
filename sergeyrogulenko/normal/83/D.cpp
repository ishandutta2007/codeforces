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

int a, b, k;
vector <int> P;

bool prime (int x) {
	for (int i = 2; i * i <= x; i ++)
		if (x % i == 0)
			return 0;
	return 1;
}

int calc (int b, int n) {
	if (n < 0)
		return 0;
	if (b < P[n])
		return 0;
	b /= P[n];
	int64 res = b;
	forn (i, n)
		res -= calc (b, i);
	return res;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> a >> b >> k;
	if (!prime (k)) {
		cout << 0 << endl;
		return 0;
	}
	if (((int64)k) * ((int64)k) > b) {
		if (a <= k && k <= b)
			cout << 1 << endl;
		else
			cout << 0 << endl;
		return 0;
	}
	P.clear ();
	for (int i = 2; i < k; i ++)
		if (prime (i))
			P.pb (i);
	P.pb (k);
	cout << calc (b, P.size() - 1) - calc (a-1, P.size() - 1) << endl;
	return 0;
}