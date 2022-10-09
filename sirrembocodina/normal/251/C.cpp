#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <queue>
#include <deque>
#include <set>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef double ld;
typedef long long int64;

int64 a, b;
int k;
int64 d[400100], d1[400100];

int gcd(int a, int b) {
	return (a ? gcd(b % a, a) : b);
}

int f(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	cin >> a >> b >> k;
	int sz = 1;
	forn (i, k) {
		sz = f(sz, i + 1);
	}
	cerr << sz << endl;
	d[0] = 0;
	forn (i, sz) {
		d[i + 1] = d[i] + 1;
		forn (j, k - 1) {
			d[i + 1] = min(d[i + 1], d[(i + 1) - (i + 1) % (j + 2)] + 1);
		}
	}
	forn (i, sz + 1) {
		d1[i] = 2000000000000000000ll;
	}
	d1[b % sz] = 0;
	for (int i = b % sz; i < sz; ++i) {
		d1[i + 1] = d1[i] + 1;
		forn (j, k - 1) {
			d1[i + 1] = min(d1[i + 1], d1[(i + 1) - (i + 1) % (j + 2)] + 1);
		}
	}/*
	forn (i, sz + 1) {
		cerr << d[i] << " ";
	}
	cerr << endl;
	forn (i, sz + 1) {
		cerr << d1[i] << " ";
	}
	cerr << endl;*/
	if (a / sz == b / sz) {
		cout << d1[a % sz] << endl;
		return 0;
	}
	cout << d[a % sz] + d1[sz] + (a / sz - b / sz - 1) * d[sz] << endl;
}