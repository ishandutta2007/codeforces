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

vector<pii> a;
int64 t[100500];
map<int, int> M;
int n;

int main () {
//	freopen ((task + ".in").data(), "r", stdin);
//	freopen ((task + ".out").data(), "w", stdout);
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n;
	forn(i, n) {
		int x;
		scanf("%d", &x);
		M[x]++;	
	}
	a = vector<pii>(all(M));
	n = a.size();
	t[0] = 0;
	for (int i = 1; i <= n; i++) {
		t[i] = t[i-1];
		if (i == 1) {
			t[i] = (int64)a[i-1].fs * (int64)a[i-1].sc;
			continue;
		}
		int pr = i - 2;
		if (a[i-1].fs == a[i-2].fs + 1)
			pr = i - 2;
		else
			pr = i - 1;
		t[i] = max(t[i], t[pr] + (int64)a[i-1].fs * (int64)a[i-1].sc);
	}
	cout << t[n] << endl;
	return 0;
}