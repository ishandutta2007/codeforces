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

const long double eps = 1e-5;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

int n, k;
int64 h;
int64 m[100000];
int64 v[100000];
vector <pair < pair <int64, int64>, int> > nums;

bool check (double tm, int tp) {
	int cur = 0;
	vector <int> ans;
	forn (i, k) {
		double cur_h = (double)h * (i+1);
		while (cur < n && tm * v[nums[cur].sc] < cur_h)
			cur ++;
		if (cur == n)
			return 0;
		ans.pb (nums[cur].sc);
		cur ++;
	}
	if (tp == 1) {
		forn (i, ans.size())
			printf ("%d ", ans[i]+1);
		printf ("\n");
	}
	return 1;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n >> k >> h;
	forn (i, n) 
		scanf ("%I64d", &m[i]);
	forn (i, n) 
		scanf ("%I64d", &v[i]);
	nums.resize (n);
	forn (i, n)
		nums[i] = mp ( mp (m[i], v[i]), i);
	sort (all (nums));
	double l = 0;
	double r = 1e10;
	forn (i, 100) {
		double m = (l + r) / 2.;
		if (check (m, 0))
			r = m;
		else
			l = m;
	}
	while (!check (r, 0))
		r += eps;
	check (r, 1);
	return 0;
}