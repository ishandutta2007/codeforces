#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;
typedef long double ld;

const long double pi = 3.1415926535897932384626433832795028841971l;

int gcd(int a, int b) {
	if (a) {
		return gcd(b % a, a);
	} else {
		return b;
	}
}

int x[300], y[300];

vector<pair<int, int> > a[1000010];
int obr[1000010];

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	for (int i = 1; i * (i - 1) / 2 < 1000010; i++) {
		obr[i * (i - 1) / 2] = i;
	}
	int n, m;
	cin >> n >> m;
	forn (i, m) {
		cin >> x[i] >> y[i];
		x[i]--;
	}
	forn (i, m) {
		forn (j, i) {
			int dx = x[i] - x[j];
			int dy = y[i] - y[j];
			if (dy == 0) {
				continue;
			}
			if (dy < 0) {
				dx = -dx;
				dy = -dy;
			}
			int g = gcd(dx, abs(dy));
			dx /= g;
			dy /= g;
			if (y[i] % dy) {
				continue;
			}
			ll X = ll(x[i]) - ll(y[i] / dy) * ll(dx);
			if (X < 0 || X >= n) {
				continue;
			}
			a[X].pb(mp(dx, dy));
		}
	}
	int s = 0;
	forn (i, n) {
		sort(a[i].begin(), a[i].end());
		int mx = 0;
		for (int j = 0; j < a[i].size();) {
			int k = j;
			while (k < a[i].size() && a[i][k] == a[i][j]) {
				k++;
			}
			mx = max(mx, k - j);
			j = k;
		}
		s += obr[mx];
		
	}
	cout << s;
        return 0;
}