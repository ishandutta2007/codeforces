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

int main() {
	int a[4], l, r;
	cin >> a[0] >> a[1] >> a[2] >> a[3] >> l >> r;
	vector<int> x;
	x.assign(r - l + 1, 0);
	forn (i1, 4) {
		forn (i2, 4) {
			if (i1 == i2) {
				continue;
			}
			forn (i3, 4) {
				if (i1 == i3 || i2 == i3) {
					continue;
				}
				int i4 = 6 - i1 - i2 - i3;
				forab (i, l, r + 1) {
					if ((((i % a[i1]) % a[i2]) % a[i3]) % a[i4] == i) {
						x[i - l]++;
					}
				}
			}
		}
	}
	int ans = 0;
	forab (i, l, r + 1) {
		ans += x[i - l] >= 7;
	}
	cout << ans;
}