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

const int64 mod = 1000000007;
vector<int> a;
int64 d[15][15];

int64 f(int x, int p, int k) {
	if (k < 0) {
		return 0;
	}
	int64 ans = 0;
	forn (i, x) {
		if (i == 4 || i == 7) {
			if (k) {
				ans += d[p][k - 1];
			}
		} else {
			ans += d[p][k];
		}
		ans %= mod;
	}
	return ans;
}

int64 cnt[15];
int64 ans = 0;

void rec(int cur, int sum = 0, int64 num = 1) {
	if (cur == 6) {
		forn (i, 10) {
			if (i > sum) {
				ans += num * cnt[i];
				ans %= mod;
			}
		}
		return;
	}
	forn (i, 10) {
		if (cnt[i]) {
			--cnt[i];
			rec(cur + 1, sum + i, (num * (cnt[i] + 1)) % mod);
			++cnt[i];
		}
	}
}

int main() {
	int m;
	cin >> m;
	++m;
	while (m) {
		a.pb(m % 10);
		m /= 10;
	}
	while (a.size() < 15) {
		a.pb(0);
	}
	forn (i, 15) {
		forn (j, 15) {
			d[i][j] = 0;
		}
	}
	d[0][0] = 1;
	forn (i, 14) {
		forn (j, i + 1) {
			d[i + 1][j] += d[i][j] * 8ll;
			d[i + 1][j] %= mod;
			d[i + 1][j + 1] += d[i][j] * 2ll;
			d[i + 1][j + 1] %= mod;
		}
	}
	forn (i, 15) {
		cnt[i] = 0;
		int x = i;
		ford (j, 15) {
			cnt[i] += f(a[j], j, x);
			cnt[i] %= mod;
			if (a[j] == 4 || a[j] == 7) {
				--x;
			}
		}
	}
	--cnt[0];
	rec(0);
	cout << ans;
}