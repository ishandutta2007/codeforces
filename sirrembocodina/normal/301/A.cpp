#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define forv(i, a) forn (i, a.size())
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define sqr(x) ((x) * (x))

typedef long long int64;
typedef long double ld;

int a[210];

int main() {
	int n;
	cin >> n;
	int mx = -1000000000, mn = 1000000000, m = 0, sum = 0;
	forn (i, 2 * n - 1) {
		cin >> a[i];
		sum += abs(a[i]);
		if (a[i] > 0) {
			mn = min(mn, a[i]);
			continue;
		}
		mx = max(mx, a[i]);
		++m;
	}
	if ((n & 1) == 0 && (m & 1)) {
		sum += 2 * mx;
		sum = max(sum, sum - 2 * (mx + mn));
	}
	cout << sum;
}