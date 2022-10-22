#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 998244353;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void solve() {
    int n;
    cin >> n;
    int d2 = 0, d3 = 0;
    while (n % 2 == 0) {
        ++d2;
        n /= 2;
    }
    while (n % 3 == 0) {
        ++d3;
        n /= 3;
    }
    if (n != 1 || d2 > d3) {
        cout << "-1\n";
    } else {
        cout << d3 * 2 - d2 << "\n";
    }
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