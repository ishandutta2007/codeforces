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
    ll n, m;
    cin >> n >> m;
    vector<int> t(m), l(m), r(m);
    for (int i = 0; i < m; ++i) {
        cin >> t[i] >> l[i] >> r[i];
        --l[i];
        --r[i];
    }
    
    vector<int> a(n);
    a[0] = n;
    vector<int> b(n, 0);
    for (int i = 0; i < m; ++i) {
        if (t[i] == 1) {
            ++b[l[i]];
            --b[r[i]];
        }
    }
    
    int cur = 0;
    for (int i = 0; i < n - 1; ++i) {
        cur += b[i];
        if (cur == 0) {
            a[i + 1] = a[i] - 1;
        } else {
            a[i + 1] = a[i];
        }
    }
    
    for (int i = 0; i < m; ++i) {
        if (t[i] == 0) {
            if (a[l[i]] == a[r[i]]) {
                cout << "NO\n";
                return;
            }
        }
    }
    
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
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