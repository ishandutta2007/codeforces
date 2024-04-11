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

string s[30];

int d[2][1 << 20];

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
		cin >> s[i];
	}
	for (int l = 2 * n - 1; l > 0; --l) {
		forn (msk0, 1 << (min(l, 2 * n - l))) {
			int msk = msk0;
			if (l > n) {
				msk <<= l - n;
			}
			if (msk == 0) {
				d[l & 1][msk] = 10000;
				continue;
			}
			if (l == 2 * n - 1) {
				d[l & 1][msk] = 0;
				continue;
			}
			int kuda[26];
			memset(kuda, 0, sizeof kuda);
			forn (i, n) {
				if (msk & (1 << i)) {
					int j = l - i - 1;
					if (i + 1 < n) {
						kuda[s[i + 1][j] - 'a'] |= 1 << (i + 1);
					}
					if (j + 1 < n) {
						kuda[s[i][j + 1] - 'a'] |= 1 << i;
					}
				}
			}
			int mx = -10000;
			forn (i, 26) {
				int cur = -d[(l + 1) & 1][kuda[i]];
				if (i == 0) {
					if (l & 1) {
						cur--;
					} else {
						cur++;
					}
				}
				if (i == 1) {
					if (l & 1) {
						cur++;
					} else {
						cur--;
					}
				}
				mx = max(mx, cur);
			}
			d[l & 1][msk] = mx;
		}
	}
	int ans = -d[1][1];
	if (s[0][0] == 'a') {
		ans++;
	}
	if (s[0][0] == 'b') {
		ans--;
	}
	if (ans > 0) {
		puts("FIRST");
	} else if (ans < 0) {
		puts("SECOND");
	} else {
		puts("DRAW");
	}
	return 0;
}