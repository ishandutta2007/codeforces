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
char buf[100500];
string s1, s2;

int main () {
//	freopen ((task + ".in").data(), "r", stdin);
//	freopen ((task + ".out").data(), "w", stdout);
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf("%d", &n);
	scanf(" %s", buf);
	s1 = buf;
	scanf(" %s", buf);
	s2 = buf;
	int l = 0;
	while (s1[l] == s2[l]) l++;
	int r = n - 1;
	while (s1[r] == s2[r]) r--;
	if (l == r) {
		cout << 2 << endl;
		return 0;
	}
	int res = 0;
	int d = r - l + 1;
	if (s1.substr(l + 1, d - 1) == s2.substr(l, d - 1)) {
		res++;
	}
	if (s1.substr(l, d - 1) == s2.substr(l + 1, d - 1)) {
		res++;
	}
	if (res == 2 && s1.substr(l, d) + s2[r] == s2.substr(l, d) + s1[r]) {
		res = 1;
	}
	cout << res << endl;
	return 0;
}