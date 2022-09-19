#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <cassert>
#include <set>
#include <algorithm>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sqr(a) ((a) * (a))
#define all(a) a.begin(), a.end()

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;

const ld pi = 3.1415926535897932384626433832795l;

int a[10000];

int main () {
#ifndef SUKPZDC
	//freopen(".in", "rt", stdin);
	//freopen(".out", "wt", stdout);
#else
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	int n;
	cin >> n;
	int s = 0;
	int k0 = 0, k1 = 0;
	forn (i, 2 * n) {
		double x;
		cin >> x;
		a[i] = int(x * 1000 + 0.1) % 1000;
		s += a[i];
		if (a[i]) {
			k1++;
		} else {
			k0++;
		}
	}
	int mn = 1000000000;
	forn (i, k1 + 1) {
		if (i <= n && k1 - i <= n) {
			mn = min(mn, abs(s - i * 1000));
		}
	}
	printf("%0.3lf\n", double(mn) / 1000);
	return 0;
}