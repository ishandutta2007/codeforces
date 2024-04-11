#include <bits/stdc++.h>

#define int long long

using namespace std;

const int mod = 1e9 + 7;
const int max_n = 2e5 + 10;

vector<int> f(max_n);
vector<int> inv_f(max_n);

int bin_pow(int a, int b) {
    if (b == 0) {
        return 1;
    }
    int res = bin_pow(a, b / 2);
    res *= res;
    res %= mod;
    if (b % 2) {
        res *= a;
        res %= mod;
    }
    return res;
}

int inv(int x) {
    return bin_pow(x, mod - 2);
}

int c(int n, int k) {
    return f[n] * inv_f[k] % mod * inv_f[n - k] % mod;
}

int32_t main() {
    f[0] = 1;
    for (int i = 1; i < max_n; i++) {
        f[i] = f[i - 1] * i % mod;
    }
    for (int i = 0; i < max_n; i++) {
        inv_f[i] = inv(f[i]);
    }
    ios_base::sync_with_stdio(0);
    int f, w, h;
    cin >> f >> w >> h;
    if (w == 0) {
        cout << 1 << endl;
        return 0;
    }
    h++;
    int ans = 0;
    for (int k = 1; ; k++) {
        if (h * k > w) {
            break;
        }
        if (k - 1 > f) {
            break;
        }
        int left_w = w - h * k;
        int left_f = f - (k - 1);
        int cur = c(left_w + k - 1, k - 1);
        cur *= c(left_f + k, k);
        cur %= mod;
        ans += cur;
        ans %= mod;
    }
    cout << ans * inv(c(w + f, w)) % mod << endl;
}