#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

#define forab(i, a, b) for (int i = a; i < (int)(b); i++)
#define fordab(i, a, b) for (int i = b - 1; i >= (int)(a); i--)
#define forn(i, n) forab (i, 0, n)
#define ford(i, n) fordab (i, 0, n)
#define forv(i, a) forn (i, a.size())
#define mp make_pair
#define fs first
#define sc second
#define pb push_back

typedef long long int64;

const int64 mod = 1000000007;

inline int64 sum(int64 a, int64 b) {
	return (a + b) % mod;
}

inline int64 mult(int64 a, int64 b) {
	return (a * b) % mod;
}

int main() {
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	int64 res = 1;
	if (k == 1 || n < k) {
		forn (i, n) {
			res = mult(res, m);
		}
	} else if (n == k) {
		forn (i, (n + 1) >> 1) {
			res = mult(res, m);
		}
	} else if (k % 2) {
		res = m * m;
	} else {
		res = m;
	}
	cout << res;
}