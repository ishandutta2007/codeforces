#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <list>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
        
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = n - 1 ; i >= 0 ; i--)
#define forv(i, a) for (int i = 0; i < (int)(a.size()); i++)
#define forab(i, a, b) for (int i = a; i < (int)(b); i++)
#define fordab(i, a, b) for (int i = b - 1; i >= (int)(a); i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define pi 3.1415926535897932
#define all(a) a.begin(), a.end()

typedef long long int64;       
typedef long double ld;

int a[400], b[400][400], c[400][400];

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	int n;
	cin >> n;
	forn (i, n) {
		c[i][n] = n;
		forn (j, n) {
			int x;
			cin >> x;
			c[i][x - 1] = j;
		}
	}
	forn (i, n) {
		int x;
		cin >> x;
		a[x - 1] = i;
	}
	a[n] = n;
	forn (i, n) {
		forn (j, n) {
			b[i][j] = n;
			forn (k, i + 1) {
				if (k == j) {
					continue;
				}
				if (a[b[i][j]] > a[k]) {
					b[i][j] = k;
				}
			}
		}
	}
	forn (i, n) {
		int res = n, mn = n;
		forn (j, n) {
			if (mn > c[i][b[j][i]]) {
				mn = c[i][b[j][i]];
				res = j + 1;
			}
		}
		cout << res << " ";
	}
}