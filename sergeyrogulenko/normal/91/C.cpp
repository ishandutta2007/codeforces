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

int n, m, k;
int l[100000];

int leader (int v) {
	if (l[v] != v)
		l[v] = leader (l[v]);
	return l[v];
}

void unite (int x, int y) {
	x = leader (x);
	y = leader (y);
	l[y] = x;
}

int power[1000000];
const int P = 1000000009;

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf ("%d%d", &n, &m);
	power[0] = 1;
	for (int i = 1; i < 1000000; i ++)
		power[i] = (power[i-1] * 2) % P;	
	forn (i, n)
		l[i] = i;
	k = 0;
	forn (i, m) {
		int x, y;
		scanf ("%d%d", &x, &y);
		if (leader (x) != leader (y)) 
			unite (x, y);
		else
			k ++;
		printf ("%d\n", (power[k] + P - 1) % P);
	}
	return 0;
}