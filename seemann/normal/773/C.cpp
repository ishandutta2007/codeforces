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
const int LOG = 60;
int cp[LOG];
int cr[LOG];
int sumr[LOG];

int main() {
#ifdef LOCAL
    freopen("c.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int n;
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>> n;
    int ans = 0;
    forn(i, n) {
        ll a;
        cin >> a;
        if (__builtin_popcountll(a) == 1) {
            cp[__builtin_popcountll(a - 1)]++;
        } else {
            ans++;
            int k = 0;
            while ((((ll)1) << k) <= a) {
                cp[k]--;
                k++;
            }
            cr[k]++;
        }
    }
    for (int j = LOG - 1; j > 0; --j) {
        if (cp[j] < 0) {
            cout << -1 << '\n';
            return 0;
        }
    }
    bool fail = true;
    for (int i = 0; i <= cp[0]; ++i) {
        int s = i;
        int fs = i;
        bool good = true;
        for (int j = 0; j < LOG; ++j) {
            s += cr[j];
            if  (cp[j] > s + fs) {
                good = false;
                break;
            }
            s = min(cp[j], s);
            fs -= max(0, cp[j] - s);
            assert(fs >= 0);
            fs = min(s, fs);
        }
        if (good)  {
            fail = false;
            cout << i + ans << ' ';
        }
    }
    if (fail)
        cout << -1;
    cout << '\n';
/*
    for (int j = LOG - 1; j > 0; --j) {
        sumr[j] += cr[j];
        cp[j] -= sumr;
        if (cp[j] > cp[0]) {
            int d = cp[j] - cp[0];
            cerr << j << ' ' << d << '\n';
            ans += d;
            cp[j] -= d;
            for (int i = 0; i <= j; ++i) {
                cp[i] -= d;
                if (cp[i] < 0) {
                    cout << -1 << '\n';
                    return 0;
                }
            }
        }
    }
    int r = cp[0];
    cp[0] -= cp[1];
    int l = cp[1];
    cp[0] -= l;
    if (cp[0] > 0) {
        l += (cp[0] + 1) / 2;
    }
    l += ans;
    r += ans;
    assert(l > 0 && l <= r);
    for (int i = l; i <= r; ++i) {
        cout << i << ' ';
    }
    cout << '\n';
  */  
    return 0;
}