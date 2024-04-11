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
	forn (i, n) {
		cin >> a[i];
	}
	int k = 0;
	forn (i, n) {
		forn (j, i) {
			if (a[j] > a[i]) {
				k++;
			}
		}
	}
	cout << k % 2 + 4 * (k / 2);
	return 0;
}