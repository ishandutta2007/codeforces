#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
constexpr int NMAXS = 100000;
ll solve() {
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) if (a[i-1] % a[i] != 0) return 0;

    // for each divisor of a[0], find number of x <= m such that gcd(x, a[0]) = d

    vector<int> fdiv;
    for (int i = 1; i < NMAXS; ++i) {
        if (i > a[0] / i) break;
        if (a[0] % i == 0) {
            fdiv.push_back(i);
            if (i != a[0]/i) fdiv.push_back(a[0]/i);
        }
    }
    
    sort(begin(fdiv), end(fdiv));

    // find number of x <= m such that gcd(x, a) = f
    auto findExt = [&] (int a, int f) {
        if (a % f != 0) return 0LL;
        vector<int> sfdiv;
        for (int v : fdiv) {
            if (a % v != 0) continue;
            sfdiv.push_back(v);
            if (v == a) break;
        }
        map<ll, ll> gcdCount;
        for (int i = 0; i < sfdiv.size(); ++i) { 
            gcdCount[sfdiv[i]] = m/sfdiv[i];
        }
        for (int i = (int)sfdiv.size() - 1; i >= 0; --i) {
            for (int j = i + 1; j < sfdiv.size(); ++j) {
                if (sfdiv[j] % sfdiv[i] == 0) gcdCount[sfdiv[i]] -= gcdCount[sfdiv[j]];
            }
            if (sfdiv[i] == f) return gcdCount[f];
        }
        return gcdCount[f];
    };

    ll ans = 1;
    for (int i = 1; i < n; ++i) {
        ll cway;
        if (a[i] == a[i-1]) {
            cway = m/a[i];
        } else {
            cway = findExt(a[i-1], a[i]);
        }
        ans = (ans * cway) % MOD;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
}