#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>

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
typedef unsigned int uint;

uint a[2100][65], b[2100][65], x[65];
bool c[2100];
char temp[2100];

inline void setTrueA(int i, uint j) {
	a[i][j >> uint(5)] |= (uint(1) << (j & uint(31)));
}

inline void setTrueB(int i, uint j) {
	b[i][j >> uint(5)] |= (uint(1) << (j & uint(31)));
}

inline bool isTrueA(int i, uint j) {
	return a[i][j >> uint(5)] & (uint(1) << (j & uint(31)));
}

inline bool isTrueB(int i, uint j) {
	return b[i][j >> uint(5)] & (uint(1) << (j & uint(31)));
}

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	int n;
	cin >> n;
	forn (i, 2100) {
		forn (j, 65) {
			a[i][j] = b[i][j] = 0;
		}
		c[i] = false;
	}
	forn (i, n) {
		string s;
		scanf("%s", temp);
		s = temp;
		forn (j, n) {
			if (s[j] == '1') {
				setTrueA(i, j);
				setTrueB(i, j);
			}
		}
		c[i] = s[i] == '1';
	}
	int ans = 0;
	forn (i, n - 1) {
		forn (j, 65) {
			x[j] = 0;
		}
		fordab (j, i + 1, n) {
			if (isTrueA(i, j) != isTrueA(i, j + 1)) {
				ans++;
				c[i] = !c[i];
				c[j] = !c[j];
				x[uint(j) >> uint(5)] |= (uint(1) << (uint(j) & uint(31)));
			}
		}
		forab (j, i + 1, n) {
			forn (k, 65) {
				a[j][k] ^= x[k];
			}
		}
	}
	fordab (i, 1, n) {
		forn (j, 65) {
			x[j] = 0;
		}
		forn (j, i) {
			if ((j == 0 && isTrueB(i, j)) || (j && isTrueB(i, j) != isTrueB(i, j - 1))) {
				ans++;
				c[i] = !c[i];
				c[j] = !c[j];
				x[j >> uint(5)] |= (uint(1) << (j & uint(31)));
			}
		}
		forn (j, i) {
			forn (k, 65) {
				b[j][k] ^= x[k];
			}
		}
	}
	forn (i, n) {
		ans += c[i];
	}
	cout << ans;
}