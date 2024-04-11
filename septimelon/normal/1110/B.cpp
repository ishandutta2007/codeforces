#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 998244353;
const int MAX = 1000000009;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    
    vector<int> d(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        d[i] = b[i + 1] - b[i] - 1;
    }
    sort(d.begin(), d.end());
    
    int ans = n;
    for (int i = n; i > k; --i) {
        ans += d[n - i];
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t = 1;
    //cin >> t;
    for (int qq = 0; qq < t; ++qq) {
        solve();
    }
    
    return 0;
}