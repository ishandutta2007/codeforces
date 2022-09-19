#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <memory.h>
#include <ctime>
#include <cctype>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define all(a) a.begin(), a.end()
#define sqr(a) ((a) * (a))

typedef long double ld;
typedef long long ll;
typedef unsigned char uc;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ld pi = 3.141592653589793238462643l;

bool check (int n, int a0, int a1, int k, string &s) {
	if (n == 1 && a0 != a1) {
		return 0;
	}
	if ((n - (a0 != 0) - (a1 != 2)) / 2 < k) {
		return 0;
	}
	s.resize(n);
	forn (i, n) {
		s[i] = 'B';
	}
	s[0] = a0 + 'A';
	s[n - 1] = a1 + 'A';
	forn (i, k) {
		s[2 * i + (a0 != 0)] = 'A';
		s[2 * i + 1 + (a0 != 0)] = 'C';
	}
	return 1;
}

ll a[100], b[100], ab[100], ba[100], bb[100];

int main () {
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	a[0] = 1, b[0] = 0, ab[0] = 0, ba[0] = 0, bb[0] = 0;
	a[1] = 0, b[1] = 1, ab[1] = 0, ba[1] = 0, bb[1] = 0;
	a[2] = 1, b[2] = 1, ab[2] = 1, ba[2] = 0, bb[2] = 0;
	for (int i = 3; i < 100; ++i) {
		a[i] = a[i - 2] + a[i - 1];
		b[i] = b[i - 2] + b[i - 1];
		ab[i] = ab[i - 2] + ab[i - 1];
		ba[i] = ba[i - 2] + ba[i - 1] + (i & 1);
		bb[i] = bb[i - 2] + bb[i - 1] + 1 - (i & 1);
	}
	ll k, x, n, m;
	cin >> k >> x >> n >> m;
	k--;
	forn (a0, 3) {
		forn (a1, 3) {
			forn (b0, 3) {
				forn (b1, 3) {
					ll x1 = x - ab[k] * (a1 == 0 && b0 == 2) - ba[k] * (b1 == 0 && a0 == 2) - bb[k] * (b1 == 0 && b0 == 2);
					if (x1 < 0) {
						continue;
					}
					forn (k1, n) {
						if (a[k] * k1 <= x1 && (x1 - a[k] * k1) % b[k] == 0) {
							int k2 = (x1 - a[k] * k1) / b[k];
							string s1;
							if (!check(n, a0, a1, k1, s1)) {
								continue;
							}
							string s2;
							if (!check(m, b0, b1, k2, s2)) {
								continue;
							}
							puts(s1.c_str());
							puts(s2.c_str());
							return 0;
						}
					}
				}
			}
		}
	}
	puts("Happy new year!");
	return 0;
}