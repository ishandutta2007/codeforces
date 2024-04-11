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

int a[100010];

int main () {
#ifndef SUKPZDC
	//freopen(".in", "rt", stdin);
	//freopen(".out", "wt", stdout);
#else
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	ll n, l, r, ql, qr;
	cin >> n >> l >> r >> ql >> qr;
	ll s = 0, t = 0;
	forn (i, n) {
		scanf("%d", &a[i]);
		t += a[i];
	}
	ll mn = 1000000000ll * 1000000000ll;
	forn (i, n + 1) {
		ll cur = l * s + r * t;
		int j = n - i;
		if (i > j) {
			cur += (i - j - 1) * ql;
		}
		if (i < j) {
			cur += (j - i - 1) * qr;
		}
		mn = min(mn, cur);
		if (i < n) {
			s += a[i];
			t -= a[i];
		}
	}
	cout << mn << endl;
	return 0;
}