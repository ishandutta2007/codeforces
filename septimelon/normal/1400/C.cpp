#include <vector>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 998244353;

ll sum(ll a, ll b) {
    ll ans = a + b;
    while (ans > MOD) {
        ans -= MOD;
    }
    return ans;
}

ll mul(ll a, ll b) {
    return (a * b) % MOD;
}

void solve() {
    int n, x;
    string s;
    cin >> s >> x;
    n = s.size();

    string w = "";
    for (int i = 0; i < n; ++i) {
        w += "1";
        if (i + x < n && s[i + x] == '0') {
            w[i] = '0';
        }
        if (i - x >= 0 && s[i - x] == '0') {
            w[i] = '0';
        }
    }

    for (int i = 0; i < n; ++i) {
        if (s[i] == '1' && (i - x < 0 || w[i - x] == '0') && (i + x >= n || w[i + x] == '0')) {
            cout << "-1\n";
            return;
        }
    }

    cout << w << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        solve();
    }

    return 0;
}