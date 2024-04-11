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

template <class T> T sqr (T x) {return x * x;}

set<int> S;
int a[50];
int t[30];
const int T[30] = {0, 
1,
2,
1,
4,
3,
2,
1,
5,
6,
2,
1,
8,
7,
5,
9,
8,
7,
3,
4,
7,
4,
2,
1,
10,
9,
3,
6,
11,
12
};

string solve(int n) {
	seta(a, 0);
	a[1] = n;
	
	for (int i = 2; i * i <= n; i++) {
		if (S.count(i))
			continue;
		int64 x = 1;
		int k = 0;
		while (x * (int64)i <= n) {
			x *= i;
			S.insert(I x);
			k++;
		}
		a[k]++;
	}	
	a[1] -= S.size();
	forn(i, 50)
		a[i] %= 2;
	int ans = 0;
	forn(i, 50)
		if (a[i] == 1)
			ans ^= T[i];
	if (ans)
		return "Vasya";
	else
		return "Petya";
}
/*
char w[1<<29];
int q[40];

int calc(int v) {
	seta(w, 0);
	forn(i, 1 << v) {
		seta(q, 0);
		forn(j, v)
			if (i & (1 << j)) {
				int mask = i;
				int k = j;
				while (k < v) {
					mask = (mask | (1 << k)) ^ (1 << k);
					k += j + 1;
				}
				q[w[mask]] = 1;
			}
		forn(j, v + 1)
			if (q[j] == 0) {
				w[i] = j;
				break;
			}	
	}
	return w[(1<<v) - 1];
}
*/
int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
//	for (int i = 1; i <= 29; i++) {
//		t[i] = calc(i);
//		cout << t[i] << "," << endl;
//	}
	int n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}