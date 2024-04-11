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

int l[100];
int n, m;

int leader (int v) {
	if (l[v] != v)
		l[v] = leader (l[v]);
	return l[v];
}

void unite (int v1, int v2) {
	v1 = leader (v1);
	v2 = leader (v2);
	l[v1] = v2;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf ("%d%d", &n, &m);
	if (m != n) {
		cout << "NO" << endl;
		return 0;
	}
	forn (i, n)
		l[i] = i;
	forn (i, n) {
		int x, y;
		cin >> x >> y;
		x --;
		y --;
		unite (x, y);
	}
	forn (i, n-1)
		if (leader (i) != leader (i+1)) {
			cout << "NO" << endl;
			return 0;
		}
		cout << "FHTAGN!" << endl;
	return 0;
}