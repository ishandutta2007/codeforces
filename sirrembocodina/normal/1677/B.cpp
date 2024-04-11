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

int32_t main() {
    srand(time(nullptr));
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        forn (i, n * m) {
            s[i] -= '0';
        }
        s += s;
        forn (i, n * m) {
            s[i] = 0;
        }
        vector<int> sum1(s.size() + 1); // sum of s[i - m .. i)
        for (int i = n * m; i < s.size(); i++) {
            sum1[i + 1] = sum1[i] + s[i] - s[i - m];
        }
        vector<int> sum2(s.size() + 1); // sum of s[i - (n - 1) * m, ..., i - m, i]
        for (int i = n * m; i < s.size(); i++) {
            sum2[i] = sum2[i - m] + s[i] - s[i - n * m];
        }
        vector<int> cnt1(s.size() + 1); // cnt of sum1[i - (n - 1) * m, ..., i - m, i]
        for (int i = n * m; i <= s.size(); i++) {
            cnt1[i] = cnt1[i - m] + bool(sum1[i]) - bool(sum1[i - n * m]);
        }
        vector<int> cnt2(s.size() + 1); // cnt of sum2[i - m .. i)
        for (int i = n * m; i < s.size(); i++) {
            cnt2[i + 1] = cnt2[i] + bool(sum2[i]) - bool(sum2[i - m]);
        }
        //vector<int> ans(s.size());
        for (int i = n * m; i < s.size(); i++) {
            cout << cnt1[i + 1] + cnt2[i + 1] << ' ';
        }
        cout << '\n';
    }
}