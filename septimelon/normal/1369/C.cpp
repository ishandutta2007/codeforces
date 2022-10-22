#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 998244353;

ll am(ll a, ll b) {
    return (a + b) % MOD;
}

ll mm(ll a, ll b) {
    return (a * b) % MOD;
}

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> w(k);
    for (int i = 0; i < k; ++i) {
        cin >> w[i];
    }
    sort(a.begin(), a.end());
    sort(w.begin(), w.end());
    
    int k1 = 0;
    for (int i = 0; i < k; ++i) {
        if (w[i] == 1) {
            ++k1;
        }
    }
    
    ll ans = 0LL;
    for (int i = 0; i < k; ++i) {
        ans += a[n - i - 1];
    }
    for (int i = 0; i < k1; ++i) {
        ans += a[n - i - 1];
    }
    int ci = 0;
    for (int i = k - 1; i >= k1; --i) {
        ans += a[ci];
        ci += w[i] - 1;
    }
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    for (int qq = 0; qq < t; ++qq) {
        solve();
    }
    
    return 0;
}