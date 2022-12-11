#include <cassert>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb(i) push_back(i)
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)

typedef long long ll;
typedef long double ldb;

const int INF = 1e9;
const ldb EPS = 1e-8;
const int MAXN = 1e5;
const int MAX = 3e4;

int main() {
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
    ll c, h1, h2, w1, w2;
    cin >> c >> h1 >> h2 >> w1 >> w2;
//    ll g = __gcd(w1, w2);
 //   w1 /= g;
  //  w2 /= g;
  //  c /= g;
    if (h1 * w2 > h2 * w1) {
        swap(h1, h2);
        swap(w1, w2);
    }
    ll ans = 0;
    if (w2 > MAX) {
        for (ll k2 = 0; k2 * w2 <= c; ++k2) {
            ll k1 = (c - k2 * w2) / w1;
            ans = max(ans, k1 * h1 + k2 * h2);
        }
    } else {
        for (ll k1 = 0; k1 < w2 && k1 * w1 <= c; ++k1) {
            ll k2 = (c - k1 * w1) / w2;
            ans = max(ans, k1 * h1 + k2 * h2);
        }
    }
    cout << ans << '\n';




	return 0;
}