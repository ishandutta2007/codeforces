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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> cou(n + 1, 0LL);
    vector<vector<ll>> sa(n, vector<ll>(n, 0LL));
    for (int j = n - 2; j >= 0; --j) {
        ++cou[a[j + 1]];
        ll curs = 0LL;
        for (int i = j - 2; i >= 0; --i) {
            curs += cou[a[i + 1]];
            sa[i][j] = curs;
            //cout << "(" << i << ";" << j << ") " << curs << "\n";
        }
    }

    ll ans = 0LL;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 2; j < n - 1; ++j) {
            if (a[i] == a[j]) {
                ans += sa[i][j];
            }
        }
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