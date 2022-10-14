#include <bits/stdc++.h>

#define int long long
#define pb push_back
#define ld long double
using namespace std;
const int M = 998244353;

int binpow(int a, int x) {
    int ans = 1;
    while (x) {
        if (x % 2 == 1) {
            ans *= a;
            ans %= M;
        }
        a *= a;
        a %= M;
        x /= 2;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> pows2 = {1};
    for (int i = 0; i <= 200228; i++) {
        pows2.pb((2 * pows2.back()) % M);
    }
    vector<int> fact = {1};
    for (int i = 1; i <= 200228; i++) fact.pb((i * fact.back()) % M);
    if (n == 2) {
        cout << 0;
    } else if (n == 3) {
        int ans = (m - 1) * m / 2 % M;
        cout << ans;
    } else {
        int ans = 0;
        for (int a = n - 1; a <= m; a++) {
            int cnt = (n - 2);
            cnt *= pows2[n - 3];
            cnt %= M;
            cnt *= fact[a - 1];
            cnt %= M;
            cnt *= binpow((fact[n - 2] * fact[(a - 1) - (n - 2)] % M), M - 2);
            cnt %= M;
            ans += cnt;
            ans %= M;
        }
        cout << ans;
    }
}