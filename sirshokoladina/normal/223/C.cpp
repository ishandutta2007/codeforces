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
typedef unsigned long long ull;

const ld PI = 3.141592653589793238462643l;

ll mod = 1000000007ll;

ll a[3000];
ll n, k;

ll f[3000], fk_1[3000];

ll mypow(ll a, ll n) {
	ll ans = 1;
	forn (i, 30) {
		if (n & 1) {
			(ans *= a) %= mod;
		}
		(a *= a) %= mod;
		n >>= 1;
	}
	return ans;
}

ll C(ll a) {
	return (fk_1[a] * mypow(f[a], mod - 2)) % mod;
}

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	cin >> n >> k;
	f[0] = fk_1[0] = 1;
	forn (i, 2995) {
		f[i + 1] = (f[i] * (i + 1)) % mod;
		fk_1[i + 1] = (fk_1[i] * (k + i)) % mod;
	}
	forn (i, n) {
		cin >> a[i];
	}
	if (k == 0) {
		forn (i, n) {
			cout << a[i] << ' ';
		}
		cout << endl;
		return 0;
	}
	forn (i, n) {
		ll ans = 0;
		forn (j, n) {
			if (j > i) {
				continue;
			}
			ll d = i - j;
			ll c = C(d);
			(ans += c * a[j]) %= mod;
		}
		cout << ans << ' ';
	}
	cout << endl;
	return 0;
}