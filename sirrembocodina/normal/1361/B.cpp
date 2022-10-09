#include "bits/stdc++.h"

#define int long long

using namespace std;

const int mod = 1e9 + 7;

int bin_pow(int a, int b) {
    if(b == 0) {
        return 1;
    }
    else {
        if(b % 2 == 0) {
            int c = bin_pow(a, b / 2);
            return (c * c) % mod;
        }
        else {
            return (bin_pow(a, b - 1) * a) % mod;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    for(int q = 0; q < t; q++) {
        int n, p;
        cin >> n >> p;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (p == 1) {
            cout << n % 2 << endl;
            continue;
        }
        sort(a.rbegin(), a.rend());
        vector<pair<int, int>> b;
        for (int i = 0; i < n; i++) {
            if (i == 0 || a[i] != a[i - 1]) {
                b.push_back({a[i], 1});
            } else {
                b.back().second++;
            }
        }
        bool inf = false;
        int dif = 0;
        int dif_r = 0;
        for (int i = 0; i < b.size(); i++) {
            if (i > 0) {
                dif_r *= bin_pow(p, b[i - 1].first - b[i].first);
            }
            for (int j = 0; !inf && j < b[i - 1].first - b[i].first; j++) {
                if (dif == 0) {
                    break;
                }
                dif *= p;
                if (dif > n) {
                    inf = true;
                }
            }
            if (!inf && b[i].second >= dif) {
                b[i].second -= dif;
                dif = b[i].second % 2;
                dif_r = b[i].second % 2;
            } else {
                dif -= b[i].second;
                dif_r -= b[i].second;
                dif_r += mod;
                dif_r %= mod;
            }
        }
        dif_r *= bin_pow(p, b.back().first);
        dif_r %= mod;
        cout << dif_r << endl;
    }
}