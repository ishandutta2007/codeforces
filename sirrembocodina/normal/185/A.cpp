#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

#define forab(i, a, b) for (int i = a; i < int(b); ++i)
#define fordab(i, a, b) for (int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab (i, 0, n)
#define ford(i, n) fordab (i, 0, n)
#define forv(i, a) forn (i, a.size())

typedef long long int64;

const int64 mod = 1000000007;

int main() {
	int64 n;
	cin >> n;
	if (n == 0) {
		cout << 1;
		return 0;
	}
	int64 p = 1, res = 1, cur = 2;
	while (p <= n - 1) {
		if (p & (n - 1)) {
			res = (res * cur) % mod;
		}
		cur = (cur * cur) % mod;
		p <<= 1;
	}
	res = (res * (res + res + 1)) % mod;
	cout << res;
}