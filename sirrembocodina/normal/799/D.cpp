#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <set>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

set<pair<ll, ll> > s;

int a, b, w, h, n;
int A[100100];

bool good(ll w, ll h) {
    return (w >= a && h >= b) || (w >= b && h >= a);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> a >> b >> w >> h >> n;
//    a = 100000, b = 100000, w = h = 1;
    forn (i, n) {
        cin >> A[i];
//        A[i] = rand() + 2;
    }
    sort(A, A + n);
    s.insert(mp(min(w, h), max(w, h)));
    forn (i, n + 1) {
        for (auto x: s) {
//            cerr << x.fs << " " << x.sc << endl;
            if (good(x.fs, x.sc)) {
                cout << i << endl;
                return 0;
            }
        }
//        cerr << endl;
        if (i == n) {
            break;
        }
        ll m = A[n - i - 1];
        vector<pair<ll, ll> > nval;
        for (auto x: s) {
            if (x.fs <= 100000) {
                nval.pb(mp(min(x.fs * m, x.sc), max(x.fs * m, x.sc)));
            }
            if (x.sc <= 100000) {
                nval.pb(mp(min(x.sc * m, x.fs), max(x.sc * m, x.fs)));
            }
        }
        s.clear();
        for (auto x: nval) {
            s.insert(x);
        }
    }
    cout << -1 << endl;
    return 0;
}