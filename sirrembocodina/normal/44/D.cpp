#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <list>
#include <stack>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <memory.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = n - 1; i >= 0; i--)
#define forab(i, a, b) for(int i = a; i < b; i++)
#define fordab(i, a, b) for(int i = b - 1; i >= a; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define int64 long long       
#define ld long double
#define PI 3.1415926535897932
#define INF 1000000000
#define sqr(n) ((n) * (n))

vector<int> x, y, z;

ld d(int i, int j) {
	return sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j]) + sqr(z[i] - z[j]));
}

int main() {
	int n;
	cin >> n;
	ld ans = 1000000000.0;
	x.resize(n);
	y.resize(n);
	z.resize(n);
	forn (i, n) {
		cin >> x[i] >> y[i] >> z[i];
	}
	forab (i, 1, n) {
		forab (j, i + 1, n) {
			ans = min(ans, (d(i, j) + d(i, 0) + d(j, 0)) / 2.0);
		}
	}
	cout.precision(11);
	cout << ans;
}