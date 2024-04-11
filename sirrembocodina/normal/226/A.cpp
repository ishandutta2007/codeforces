#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define forv(i, a) forn (i, a.size())
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sqr(x) ((x) * (x))

typedef long long int64;
typedef long double ld;

int main() {
	int n;
	int64 m, res = 1;
	cin >> n >> m;
	int64 sq = 3;
	for (int p = 1; p <= n; p <<= 1) {
		if (p & n) {
			res *= sq;
			res %= m;
		}
		sq *= sq;
		sq %= m;
	}
	cout << (res + m - 1) % m;
}