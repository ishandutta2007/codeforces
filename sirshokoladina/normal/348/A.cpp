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
#define sc s econd
#define sqr(a) ((a) * (a))
#define all(a) a.begin(), a.end()

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;

const ld pi = 3.1415926535897932384626433832795l;

int a[100010];

int main () {
#ifndef SUKPZDC
	//freopen(".in", "rt", stdin);
	//freopen(".out", "wt", stdout);
#else
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	int n;
	cin >> n;
	ll l = 0;
	forn (i, n) {
		scanf("%d", &a[i]);
		l = max(l, ll(a[i]));
	}
	ll r = 2000000010;
	while (l < r) {
		ll m = (l + r) / 2;
		ll s = 0;
		forn (i, n) {
			s += m - a[i];
		}
		if (s < m) {
			l = m + 1;
		} else {
			r = m;
		}
	}
	cout << l << endl;
	return 0;
}