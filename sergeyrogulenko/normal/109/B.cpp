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
#define y1 botva

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "";

template <class T> T sqr (T x) {return x * x;}

int64 pl, pr;
int64 vl, vr;
int k;
vector <int64> A;

void go (int64 v) {
	if (v > 1000000000LL)
		return;
	A.pb (v);
	go (v * 10 + 4);
	go (v * 10 + 7);
}

int64 calc (int64 l1, int64 r1, int64 vl, int64 vr) {
	int64 l = max (l1, vl);
	int64 r = min (r1, vr);
	if (l <= r)
		return r - l + 1;
	return 0;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> pl >> pr >> vl >> vr >> k;
	A.clear ();
	go (4);
	go (7);
	A.pb (0);
	A.pb (1000000001);
	sort (all (A));
	int l = 1;
	int r = l + k;
	int64 res = 0;
	int64 sum = (pr - pl + 1) * (vr - vl + 1);
	while (r < I A.size()) {
		int l1 = A[l-1] + 1;
		int r1 = A[l];
		int l2 = A[r-1];
		int r2 = A[r] - 1;
		res += calc (l1, r1, pl, pr) * calc (l2, r2, vl, vr);
		res += calc (l2, r2, pl, pr) * calc (l1, r1, vl, vr);
		if (r1 == l2 && (pl <= r1 && r1 <= pr && vl <= r1 && r1 <= vr))
			res --;
		l ++;
		r ++;
	}
	printf ("%.10lf\n", (double)res / (double)sum);
	return 0;
}