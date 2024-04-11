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

int mod = 1000000007;

ll a[300100];
ll pw[300100];

int main() {
    pw[0] = 1;
    forn (i, 300050) {
        pw[i + 1] = pw[i] * 2 % mod;
    }
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    forn (i, n) {
        cin >> a[i];
    }
    sort(a, a + n);
    ll ans = 0;
    ll mns = 0;
    forn (i, n) {
        ans += ((pw[i] + mod - 1) % mod) * a[i] % mod;
        ans += mod - mns;
        ans %= mod;
        mns *= 2;
        mns += a[i];
        mns %= mod;
    }
    cout << ans << endl;
    return 0;
}