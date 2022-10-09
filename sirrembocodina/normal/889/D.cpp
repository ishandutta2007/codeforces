#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <set>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;
typedef long double ld;

ll x[2010], y[2010];
set<pair<ll, ll> > ln;

ll gcd(ll a, ll b) {
    return a ? gcd(b % a, a) : b;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<ll, ll> > p;
    forn (i, n) {
        cin >> x[i] >> y[i];
        p.pb(mp(x[i] * n * 2, y[i] * n * 2));
    }
    sort(p.begin(), p.end());
    ll sx = 0;
    ll sy = 0;
    forn (i, n) {
        sx += x[i] * 2;
        sy += y[i] * 2;
    }
    int ind = -1;
    forn (i, n) {
        if (sx * 2 != p[i].fs + p[n - i - 1].fs ||
            sy * 2 != p[i].sc + p[n - i - 1].sc) {
            if (p[i] < mp(sx * 2 - p[n - i - 1].fs, sy * 2 - p[n - i - 1].sc)) {
                ind = i;
            } else {
                ind = n - i - 1;
            }
            break;
        }
    }
    if (ind == -1) {
        cout << -1 << endl;
        return 0;
    }
    forn (i, n) {
        ll mx = (p[ind].fs + p[i].fs) / 2;
        ll my = (p[ind].sc + p[i].sc) / 2;
        mx -= sx;
        my -= sy;
        vector<ll> res(n);
        forn (j, n) {
            res[j] = x[j] * my - y[j] * mx;
        }
        sort(res.begin(), res.end());
        bool good = true;
        ll sum = res[0] + res.back();
        forn (j, n) {
            if (res[j] + res[n - j - 1] != sum) {
                good = false;
            }
        }
        if (!good) {
            continue;
        }
        if (mx < 0 || (mx == 0 && my < 0)) {
            mx = -mx;
            my = -my;
        }
        ll d = gcd(abs(mx), abs(my));
        mx /= d;
        my /= d;
        ln.insert(mp(mx, my));
    }
    cout << ln.size() << endl;
    return 0;
}