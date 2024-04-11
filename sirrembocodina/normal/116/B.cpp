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

string s[20];
int n, m;

bool is(int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= m) {
		return false;
	}
	return s[i][j] == 'P';
}

int main() {
	cin >> n >> m;
	forn (i, n) {
		cin >> s[i];
	}
	int ans = 0;
	forn (i, n) {
		forn (j, m) {
			if (s[i][j] != 'W') {
				continue;
			}
			ans += (is(i + 1, j) || is(i, j + 1) || is(i - 1, j) || is(i, j - 1));
		}
	}
	cout << ans;
}