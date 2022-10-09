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

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define int64 long long       
#define pi 3.1415926535897932
#define all(a) a.begin(), a.end()

typedef long double ld;

vector<ld> x, y, m, a;

int main() {
	int n;
	cin >> n;
	forn (i, n) {
		ld x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x.pb((x1 + x2) / 2);
		y.pb((y1 + y2) / 2);
		m.pb(abs(x1 - x2) * (x1 - x2) * (x1 - x2));
		a.pb(abs(x1 - x2) / 2);
	}
	forn (i, n) {
		forn (j, i) {
			ld cm = 0, cx = 0, cy = 0;
			for (int k = j + 1; k <= i; k++) {
				cm += m[k];
				cx += x[k] * m[k];
				cy += y[k] * m[k];
			}
			cx /= cm;
			cy /= cm;
			cout.precision(5);
//			cout << cx << " " << cy << endl;
			if (abs(cx - x[j]) > a[j] + 0.00000001 || abs(cy - y[j]) > a[j] + 0.00000001) {
				cout << i;
				return 0;
			}
		}
	}
	cout << n;
}