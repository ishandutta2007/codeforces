#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <cassert>
 
using namespace std;
 
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sqr(a) ((a) * (a))
#define all(a) a.begin(), a.end()

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;

const ld pi = 3.1415926535897932384626433832795l;

const ll mod = 1000000007;
const int K = 330;

ll n, m, d, ns, ms, nr, xs, ys;

ll gcj(ll a, ll b) {
	return b ? gcj(b, a % b) : a;
}

ll ans(ll x, ll y) {
	if (x % d != y % d) {
		return 1000000000000000000ll;
	}
//	x + a * n = y + b * m
	xs = x / d;
	ys = y / d;
//	xs + a * ns = ys + b * ms
//	a * ns =ms= ys - xs
//	a =ms= (ys - xs) * nr
	ll a = (((ys + ms - (xs % ms)) % ms) * nr) % ms;
	return x + a * n;
}

int main() {
	int k;
	cin >> n >> m >> k;
	n *= 2;
	m *= 2;
	d = gcj(n, m);
	ns = n / d;
	ms = m / d;
//	x + n * k = y;
//	k = (y - x) / n
	forn (i, ms) {
		if ((i * ns) % ms == 1) {
			nr = i;
		}
	}
	forn (i, k) {
		ll x, y;
		cin >> x >> y;
		ll res = min(min(ans(x, y), ans(x, m - y)), min(ans(n - x, y), ans(n - x, m - y)));
		if (res == 1000000000000000000ll) {
			cout << -1;
		} else {
			cout << res;
		}
		cout << endl;
	}
    return 0;
}