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

int main() {
	int64 a, b, m;
	cin >> a >> b >> m;
	int64 t = 1000000000 % m;
	forn (i, min(a + 1, m)) {
		if (0 < (int64(i) * t) % m && (int64(i) * t) % m + b < m) {
			cout << 1 << " ";
			vector<int> ans;
			while (i) {
				ans.pb(i % 10);
				i /= 10;
			}
			forn (j, 9 - ans.size()) {
				cout << '0';
			}
			for (int j = ans.size() - 1; j >= 0; j--) {
				cout << ans[j];
			}
			return 0;
		}
	}
	cout << 2;
}