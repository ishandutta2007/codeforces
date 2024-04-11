#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <memory.h>
#include <ctime>
#include <cctype>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define all(a) a.begin(), a.end()
#define sqr(a) ((a) * (a))

typedef long double ld;
typedef long long ll;
typedef unsigned char uc;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ld pi = 3.141592653589793238462643l;

ll l, t;

ld calc (ll d) {
	return ld((t * 2 + d) / l + (t * 2 + l - d) / l) / 4;
}

ll a[1000010];

int main () {
#ifdef LOCAL
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	ll n;
	cin >> n >> l >> t;
	forn (i, n) {
		cin >> a[i];
	}
	ll d1 = t * 2 % l + 1;
	ll d2 = l - t * 2 % l;
	if (d1 > d2) {
		swap(d1, d2);
	}
	ld c1 = calc(0);
	ld c2 = calc(d1);
	ld c3 = calc(d2);
	ll i2 = 0, i3 = 0;
	ld ans = 0;
	for (ll i1 = 0; i1 < n; ++i1) {
		while (i2 < n && a[i2] - a[i1] < d1) {
			i2++;
		}
		while (i3 < n && a[i3] - a[i1] < d2) {
			i3++;
		}
		ans += c1 * (i2 - i1 - 1);
		ans += c2 * (i3 - i2);
		ans += c3 * (n - i3);
	}
	printf("%0.20lf\n", double(ans));
	return 0;
}