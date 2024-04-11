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
    int n;
    cin >> n;
    vector<ll> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    
    vector<ll> bea(1000000, 0LL);
    for (int i = 0; i < n; ++i) {
        bea[b[i] - i + 500000] += b[i];
    }
    
    int md = 0;
    for (int i = 0; i < 1000000; ++i) {
        if (bea[i] > bea[md]) {
            md = i;
        }
    }
    cout << bea[md] << "\n";
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