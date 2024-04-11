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
const string task = "";

template <class T> T sqr (T x) {return x * x;}

int n;
vector<string> a;
vector<vector<string> > q, w;
int s[1024];
vector<string> t1, t2;

void split1(int x) {
	x += '1';
	w.clear();
	forn(i, q.size()) {
		t1.clear();
		t2.clear();
		forn(j, q[i].size())
			if (q[i][j][1] == x)
				t1.pb(q[i][j]);	
			else
				t2.pb(q[i][j]);
		if (t1.size() > 0)
			w.pb(t1);
		if (t2.size() > 0)
			w.pb(t2);
	}
	q = w;
}

string W = "RGBYW";

void split2(int x) {
	x = W[x];
	w.clear();
	forn(i, q.size()) {
		t1.clear();
		t2.clear();
		forn(j, q[i].size())
			if (q[i][j][0] == x)
				t1.pb(q[i][j]);	
			else
				t2.pb(q[i][j]);
		if (t1.size() > 0)
			w.pb(t1);
		if (t2.size() > 0)
			w.pb(t2);
	}
	q = w;
}

bool check(int mask) {
	q.clear();
	q.pb(a);
	forn(i, 5)
		if (mask & (1 << i)) {
			split1(i);
		}
	forn(i, 5)
		if (mask & (1 << (i + 5))) {
			split2(i);
		}
	forn(i, q.size())
		forn(j, q[i].size() - 1)
			if (q[i][j] != q[i][j+1])
				return false;
	return true;
}

int main () {
	cin >> n;
	a.resize(n);
	forn(i, n)
		cin >> a[i];
	seta(s, 0);
	forn(i, 1<<10)
		s[i] = s[i/2] + (i & 1);
	int ans = 10;
	forn(i, 1 << 10)
		if (check(i))
			ans = min(ans, s[i]);
	cout << ans << endl;
	return 0;
}