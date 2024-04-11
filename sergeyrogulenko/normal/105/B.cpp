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

int n, k, A;
int b[8], l[8];
double res;

double check () {
	double tmpres;
	double ans = 0;
	forn (mask, 1 << n) {
		tmpres = 0;
		double prob = 1.;
		int sum, s;
		sum = s = 0;
		forn (i, n) 
			if (mask & (1 << i)) {
				prob = prob * (l[i] / 100.);
				s ++;
			}
			else {
				prob = prob * (1. - l[i] / 100.);
				sum += b[i];
			}
		if (s * 2 > n)
			tmpres = prob;
		else
			tmpres = prob * (double)A / (double)(A + sum);
		ans += tmpres;
	}
	return ans;
}

void go (int cur, int last) {
	if (cur == n) {
		double tmp = check ();
		if (tmp > res)
			res = tmp;
		return;
	}
	go (cur+1, last);
	if (last > 0 && l[cur] < 100) {
		l[cur] += 10;
		go (cur, last-1);
		l[cur] -= 10;
	}
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n >> k >> A;
	forn (i, n)
		cin >>	b[i] >> l[i];
	res = 0;
	go (0, k);
	printf ("%.10lf\n", res);
	return 0;
}