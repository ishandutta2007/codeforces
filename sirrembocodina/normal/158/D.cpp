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
typedef unsigned int uint;

vector<int> d;
int a[21000];

int main() {
	int n;
	cin >> n;
	forn (i, n) {
		cin >> a[i];
	}
	for (int i = 1; i * i <= n; i++) {
		if (n % i) {
			continue;
		}
		if (n / i >= 3) {
			d.pb(i);
		}
		if (i >= 3) {
			d.pb(n / i);
		}
	}
	int ans = -2000000000;
	forv (i, d) {
		vector<int> sum(d[i], 0);
		forn (j, n) {
			sum[j % d[i]] += a[j];
		}
		forn (j, d[i]) {
			ans = max(ans, sum[j]);
		}
	}
	cout << ans;
}