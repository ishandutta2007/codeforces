#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1000000007;

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

vector<ll> f;

ll func(int k) {
    if (k < 0) {
        return 0;
    }
    return mm(f[k], 4LL);
}

void prep() {
    f.resize(2000001);
    f[0] = 0;
    f[1] = 0;
    for (int i = 2; i < 2000001; ++i) {
        f[i] = am(f[i - 1], mm(f[i - 2], 2LL));
        if (i % 3 == 0) {
            f[i] = am(f[i], 1LL);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    cout << func(n) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    prep();
    
    int t;
    cin >> t;
    for (int qq = 0; qq < t; ++qq) {
        solve();
    }
    
    return 0;
}