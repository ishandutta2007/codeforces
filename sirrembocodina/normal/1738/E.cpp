#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int mod = 998244353;
int max_n = 1e5 + 10;

vector<int> f, inv_f;

int bin_pow(int a, int b) {
    if (b == 0) {
        return 1;
    }
    if (b % 2) {
        return bin_pow(a, b - 1) * a % mod;
    }
    int res = bin_pow(a, b / 2);
    return res * res % mod;
}

int inv(int a) {
    return bin_pow(a, mod - 2);
}

int c(int n, int k) {
    return f[n] * inv_f[k] % mod * inv_f[n - k] % mod;
}

int32_t main() {
    f.resize(max_n, 1);
    for (int i = 0; i + 1 < max_n; i++) {
        f[i + 1] = f[i] * (i + 1) % 998244353;
    }
    inv_f.resize(max_n);
    for (int i = 0; i < max_n; i++) {
        inv_f[i] = inv(f[i]);
    }
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n = rand() % 5 + 1;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            //a[i] = rand() % 5;
            //cerr << a[i] << ' ';
        }
        //cerr << "!!!" << endl;
        vector<int> pref(n + 1);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + a[i];
        }
        vector<int> suf(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1] + a[i];
        }
        vector<pair<int, int>> pg;
        for (int i = 1; i < n; i++) {
            if (i == 1 || pref[i] != pg.back().first) {
                if (pref[i] * 2 >= pref[n]) {
                    break;
                }
                pg.push_back({pref[i], 1});
            } else {
                pg.back().second++;
            }
        }
        vector<pair<int, int>> sg;
        for (int i = n - 1; i > 0; i--) {
            if (i == n - 1 || suf[i] != sg.back().first) {
                if (suf[i] * 2 >= pref[n]) {
                    break;
                }
                sg.push_back({suf[i], 1});
            } else {
                sg.back().second++;
            }
        }
        /*for (int i = 0; i < pg.size(); i++) {
            cout << pg[i].first << '-' << pg[i].second << endl;
        }
        cout << endl;
        for (int i = 0; i < sg.size(); i++) {
            cout << sg[i].first << '-' << sg[i].second << endl;
        }
        cout << endl;*/
        int j = 0;
        int ans = 1;
        for (int i = 0; i < pg.size(); i++) {
            while (j < sg.size() && sg[j].first < pg[i].first) {
                j++;
            }
            if (j == sg.size() || sg[j].first != pg[i].first) {
                continue;
            }
            int cur = 0;
            for (int k = 0; k <= min(sg[j].second, pg[i].second); k++) {
                (cur += c(sg[j].second, k) * c(pg[i].second, k)) %= mod;
            }
            (ans *= cur) %= mod;
        }
        for (int i = 1; i < n; i++) {
            if (pref[i] * 2 == pref[n]) {
                (ans *= 2) %= mod;
            }
        }
        cout << ans << '\n';
    }
}