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
int w[200500], h[200500];
int s, h1, h2;
int sm[1050];

int main () {
//	freopen ((task + ".in").data(), "r", stdin);
//	freopen ((task + ".out").data(), "w", stdout);
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf("%d", &n);
	s = 0;
	h1 = h2 = 0;
	seta(sm, 0);
	forn(i, n) {
		scanf("%d%d", &w[i], &h[i]);
		s += w[i];
		if (h[i] > h1) {
			h2 = h1;
			h1 = h[i];
		}
		else if (h[i] > h2) {
			h2 = h[i];
		}
		sm[h[i]]++;
	}
	forn(i, n) {
		int W = s - w[i], H;
		sm[h[i]]--;
		if (sm[h1] == 0) {
			H = h2;
		} else {
			H = h1;
		}
		sm[h[i]]++;
		printf("%d ", W * H);
	}
	printf("\n");
	return 0;
}