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

vector <int64> A;

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	int64 n;
	cin >> n;
	if (n == 1) {
		cout << "1\n0\n" << endl;
		return 0;
	}
	for (int64 i = 2; i * i <= n; i ++)
		while (n % i == 0) {
			A.pb (i);
			n /= i;
		}
	if (n > 1)
		A.pb (n);
	if (A.size() == 1) {
		cout << 1 << endl;
		cout << 0 << endl;
		return 0;
	}
	if (A.size() == 2) {
		cout << 2 << endl;
		return 0;
	}
	cout << 1 << endl;
	cout << A[0] * A[1] << endl;
	return 0;
}