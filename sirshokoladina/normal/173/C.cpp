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

typedef long double ld;
typedef long long ll;
typedef unsigned char uc;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ld PI = 3.141592653589793238462643l;

int a[510][510];
int s[510][510];

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	int n, m;
	cin >> n >> m;
	forn (i, 510) {
		s[i][0] = s[0][i] = 0;
	}
	forn (i, n) {
		forn (j, m) {
			scanf("%d", &a[i][j]);
			s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j] + a[i][j];
		}
	}
	int ans = -1000000000;
	forn (i, n) {
		forn (j, m) {
			int k = min(min(i + 1, n - i), min(j + 1, m - j));
			int d = a[i][j];
			for (int e = 1; e < k; e++) {
				d = s[i + e + 1][j + e + 1] - s[i + e + 1][j - e] - s[i - e][j + e + 1] + s[i - e][j - e] - d - a[i - e + 1][j - e];
				if (d > ans) {
					ans = d;
				}
			}
		}
	}
	cout << ans;
	return 0;
}