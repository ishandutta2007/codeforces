#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>
#include <memory.h>
#include <set>
#include <cmath>
#include <queue>

using namespace std;

#define forab(i, a, b) for (int i = a; i < (int)(b); i++)
#define fordab(i, a, b) for (int i = b - 1; i >= (int)(a); i--)
#define forn(i, n) forab (i, 0, n)
#define ford(i, n) fordab (i, 0, n)
#define forv(i, n) forn (i, n.size())
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long int64;
typedef long double ld;

string s[110], ans;

int main() {
	int n, m;
	cin >> n >> m;
	forn (i, n) {
		cin >> s[i];
	}
	ans = "";
	forn (i, n) {
		forn (j, m) {
			bool ok = true;
			forn (k, n) {
				if (s[i][j] == s[k][j] && k != i) {
					ok = false;
				}
			}
			forn (k, m) {
				if (s[i][j] == s[i][k] && k != j) {
					ok = false;
				}
			}
			if (ok) {
				ans += s[i][j];
			}
		}
	}
	cout << ans;
}