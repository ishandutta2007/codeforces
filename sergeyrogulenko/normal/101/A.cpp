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

char a[200000];
vector < pii > Q;
bool u[256];

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	Q.clear ();
	Q.resize (256);
	forn (i, 256)
		Q[i].sc = i;
	int n, k;
	gets (a);
	n = strlen (a);
	scanf ("%d", &k);
	forn (i, n)
		Q[I a[i]].fs ++;
	sort (all (Q));
	int last = 256;
	seta (u, 0);
	int p = 0;
	while (p < 256 && Q[p].fs <= k) {
		u[Q[p].sc] = 1;
		k -= Q[p].fs;
		p ++;
		last --;
	}
	printf ("%d\n", last);
	forn (i, n)
		if (!u[I a[i]])
			printf ("%c", a[i]);
	cout << endl;
	return 0;
}