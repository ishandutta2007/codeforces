#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

const int mod = 998244353;

int bin_pow(int a, int b) {
    if (b == 0) {
        return 1;
    }
    int res = bin_pow(a, b / 2);
    res *= res;
    res %= mod;
    if (b % 2) {
        res *= a;
        res %= mod;
    }
    return res;
}

int inv(int x) {
    return bin_pow(x, mod - 2);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    n *= 2;
    vector<int> a(n);
    forn (i, n) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = 0;
    n /= 2;
    forn (i, n) {
        ans -= a[i];
    }
    forn (i, n) {
        ans += a[i + n];
    }
    ans %= mod;
    forn (i, n) {
        ans *= n + 1 + i;
        ans %= mod;
    }
    forn (i, n) {
        ans *= inv(i + 1);
        ans %= mod;
    }
    cout << ans << endl;
}