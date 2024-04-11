#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

#include <bitset>
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
#define next NEXT64
#define prev PREV64
#define y1 Y164

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "";

template <class T> T sqr(T x) { return x * x; }

int n;
int a[100500];
int t[100500];

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	forn(i, n) scanf("%d", &a[i+1]);
	t[0] = 0;
	for (int i = 1; i <= n; i++) {
		t[i] = t[i-1] + 20;
		int p = (lower_bound(a+1, a+n+1, a[i] - 90 + 1) - a);
		if (p < i) t[i] = min(t[i], t[p-1] + 50);
		p = (lower_bound(a+1, a+n+1, a[i] - 1440 + 1) - a);
		if (p < i) t[i] = min(t[i], t[p-1] + 120);
	}
	forn (i, n) printf("%d\n", t[i+1] - t[i]);
	return 0;
}