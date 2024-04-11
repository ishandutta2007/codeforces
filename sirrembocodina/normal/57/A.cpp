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
	int n, x1, x2, y1, y2;
	cin >> n >> x1 >> y1 >> x2 >> y2;
	bool b1, b2, b3, b4;
	b1 = x1 == 0 || x1 == n;
	b2 = y1 == 0 || y1 == n;
	b3 = x2 == 0 || x2 == n;
	b4 = y2 == 0 || y2 == n;
//	cout << b1 << " " << b2 << " " << b3 << " " << b4 << endl;
	if ((!x1 && !x2) || (!y1 && !y2) || (x1 == n && x2 == n) || (y1 == n && y2 == n)) {
		cout << abs(x1 - x2) + abs(y1 - y2);
		return 0;
	}
	if ((b1 && b3) || (b2 && b4)) {
		int ans = n * 10;
		if (b1 && b3) {
			ans = min(min(y1 + y2 + n, 3 * n - y1 - y2), ans);
		}
		if (b2 && b4) {
			ans = min(min(x1 + x2 + n, 3 * n - x1 - x2), ans);
		}
		cout << ans;
		return 0;
	}
	cout << abs(x1 - x2) + abs(y1 - y2);
}