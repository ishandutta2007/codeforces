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
#include <bitset>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb push_back
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-8;
const ld PI = acos(-1.0L);
const int MAXN = 1e5;

ll templ(ll x) {
    ll res = 0;
    ll pw = 1;
    while (x > 0) {
        ll d = x % 2;
        res += d * pw;
        x /= 10;
        pw *= 10;
    }
    return res;
}
int main() {
#ifdef LOCAL
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    map<ll, ll> s;
    int q;
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    forn(i, q) {
        char c;
        ll x;
        cin >> c >> x;
        if (c == '?') {
            cout << s[x] << '\n';
        } else {
            x = templ(x);
            if (c == '-') {
                s[x]--;
            } else {
                s[x]++;
            }
        }
    }
    return 0;
}