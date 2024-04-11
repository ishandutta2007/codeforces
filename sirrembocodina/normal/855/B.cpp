#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cstring>
#include <memory>
#include <string>
#include <vector>
#include <cstdio>
#include <ctime>
#include <set>
#include <iostream>

using namespace std;

#define fs first
#define sc second
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int mod = 1000000007;

ll a[100100];
ll ml[100100], mr[100100];
ll inf = 4000000000000000000ll;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    ll p, q, r;
    cin >> p >> q >> r;
    forn (i, n) {
        cin >> a[i];
    }
    ml[0] = a[0] * p;
    forn (i, n - 1) {
        ml[i + 1] = max(ml[i], a[i + 1] * p);
    }
    mr[n] = -inf;
    for (int i = n - 1; i >= 0; --i) {
        mr[i] = max(mr[i + 1], a[i] * r);
    }
    ll ans = -inf;
    forn (i, n) {
        ans = max(ans, q * a[i] + ml[i] + mr[i]);
    }
    cout << ans << endl;
    return 0;
}