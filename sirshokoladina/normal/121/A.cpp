#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)
#define ford(i,n) for (int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int main() {
	long long s = 0, last;
	long long l, r;
	cin >> l >> r;
	last = l - 1;
	forn (len, 11) {
		forn (m, 1 << len) {
			long long a = 0;
			ford (i, len) {
				a = a * 10 + ((m & (1 << i)) ? 7 : 4);
			}
			if (a >= l) {
				if (a < r) {
					s += a * (a - last);
				} else {
					s += a * (r - last);
					cout << s;
					return 0;
				}
				last = a;
			}
		}
	}
}