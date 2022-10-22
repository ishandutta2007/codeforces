#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> a('z' - 'a' + 1, 0);
    for (int i = 0; i < n; ++i) {
        ++a[s[i] - 'a'];
    }
    vector<int> tot(4 * n + 1, 0);
    tot[0] = 10000000;
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 1; j <= n; ++j) {
            tot[j] += a[i] / j;
        }
    }
    int ans = 0;
    int m2d = 1;
    while (m2d <= n) {
        m2d *= 2;
    }
    for (int d = 1; d <= k; ++d) {
        if (k % d != 0) {
            continue;
        }
        int ci = 0;
        for (int c2d = m2d; c2d > 0; c2d /= 2) {
            if (tot[ci + c2d] >= d) {
                ci += c2d;
            }
        }
        ans = max(ans, ci * d);
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