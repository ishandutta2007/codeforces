#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

struct my_hash {
    inline size_t operator()(const pair<int, int>& a) const {
        return a.first * 31 + a.second;
    }
};

int mod = 998244353;

int f(int x) {
    if (x > 2) {
        return x - 2;
    }
    return x / 2;
}

int32_t main() {
    srand(time(nullptr));
    ios_base::sync_with_stdio(0);
    vector<int> a(500001);
    int mx = 0;
    for (int i = 2; i < 500001; i++) {
        vector<bool> b(15);
        for (int j = 0; j <= min(i - 2, 50ll); j++) {
            b[a[j] ^ a[i - 2 - j]] = true;
        }
        a[i] = -1;
        for (int x = 0; x < 15; x++) {
            if (!b[x]) {
                a[i] = x;
                break;
            }
        }
    }
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool all_eq = true;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[0]) {
                all_eq = false;
            }
        }
        if (all_eq) {
            cout << (s[0] == 'B' ? "Bob\n" : "Alice\n");
            continue;
        }
        vector<int> g = {1};
        for (int i = 1; i < n; i++) {
            if (s[i - 1] != s[i]) {
                g.back()++;
            } else {
                g.push_back(1);
            }
        }
        int cnt_b = 0;
        for (int i = 0; i < n; i++) {
            cnt_b += s[i] == 'B';
        }
        int cnt_r = n - cnt_b;
        if (cnt_r > cnt_b) {
            cout << "Alice\n";
            continue;
        }
        if (cnt_r < cnt_b) {
            cout << "Bob\n";
            continue;
        }
        int ans = 0;
        for (int x: g) {
            ans ^= a[x];
        }
        cout << (ans == 0 ? "Bob\n" : "Alice\n");
    }
}