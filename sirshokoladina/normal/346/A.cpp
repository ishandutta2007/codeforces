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

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define bp push_back
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

int gcd (int a, int b) {
	if (!a) {
		return b;
	}
	return gcd(b % a, a);
}

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
	int d = 0;
	int mx = 0;
	forn (i, n) {
		int a;
		cin >> a;
		mx = max(a, mx);
		d = gcd(a, d);
	}
	if ((mx / d - n) & 1) {
		puts("Alice");
	} else {
		puts("Bob");
	}
	return 0;
}