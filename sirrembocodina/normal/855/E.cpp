#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

const long long mod = 1000000007;

long long d[12][65][1024];
long long df[12][65];

long long f(int b, long long r) {
    int mask = 0;
    ll pw = 1, l = 0;
    while (pw <= r) {
        pw *= b;
        ++l;
        if (l == 19 && b == 10) {
            break;
        }
    }
    vector<int> a(l, 0);
    forn (i, l) {
        a[l - i - 1] = r % b;
        r /= b;
    }
//    forn (i, l) {
//        cerr << a[i];
//    }
//    cerr << endl;
    ll ans = 0;
    forn (i, l) {
        forn (dig, a[i]) {
            if (dig == 0 && i == 0) {
                continue;
            }
            mask ^= 1 << dig;
            ans += d[b][l - i - 1][mask];
//            cerr << ans << endl;
            mask ^= 1 << dig;
        }
        mask ^= 1 << a[i];
    }
    for (int i = 1; i < l; ++i) {
        for (int dig = 1; dig < b; ++dig) {
            ans += d[b][i - 1][1 << dig];
        }
    }
    return ans;
}

int main() {
    for (int b = 2; b <= 10; ++b) {
        d[b][0][0] = 1;
        for (int l = 1; l < 65; ++l) {
            for (int mask = 0; mask < (1 << b); ++mask) {
                forn (dig, b) {
                    d[b][l][mask] += d[b][l - 1][mask ^ (1 << dig)];
                }
//                cerr << d[b][l][mask] << endl;
            }
        }
    }
    ios::sync_with_stdio(false);
    int q;
    cin >> q;
    forn (i, q) {
        int b;
        ll l, r;
        cin >> b >> l >> r;
//        b = 10;
//        l = r= 999999999999999999;
        ++r;
        cout << f(b, r) - f(b, l) << endl;
    }
    return 0;
}