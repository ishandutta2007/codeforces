#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <cstring>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i ++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i --)
#define sqr(a) ((a) * (a))
#define mp make_pair
#define pb push_back
#define fs first
#define sc second

typedef long long ll;
typedef long double ld;

int c[200];

int main() {
	//freopen ("input.txt", "rt", stdin);
	//freopen ("output.txt", "wt", stdout);
	int n, a, b;
	cin >> n >> a >> b;
	if (n == 1) {
		cout << 1;
		return 0;
	}
	c[0] = 1;
	int s = 1, mx = 1, k = 1;
	if (b == 0) {
		if (a == n - 1) {
			cout << -1;
			return 0;
		}
		c[1] = 1;
		s = 2, mx = 1, k = 2;
	}
	forn (i, n - k) {
		if (i >= a + b) {
			c[i + k] = 1;
		} else if (i < b) {
			c[i + k] = s + 1;
		} else {
			c[i + k] = mx + 1;
		}
		mx = max(mx, c[i + k]);
		s += c[i + k];
	}
	if (mx > 50000) {
		cout << -1;
		return 0;
	}
	forn (i, n) {
		cout << c[i] << ' ';
	}
	return 0;
}