#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

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
    string s;
    cin >> s;

    vector<int> a;
    int ci = -1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            a.push_back(i - ci - 1);
            ci = i;
        }
    }
    a.push_back(s.size() - ci - 1);

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < a.size(); i += 2) {
        ans += a[i];
    }

    cout << ans << "\n";
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