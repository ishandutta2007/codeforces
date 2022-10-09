#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int solve(vector<int> a, int margin) {
    int n = a.size();
    /*forn (i, n) {
        cerr << a[i] << " ";
    }
    cerr << endl;*/
    vector<int> pref(n + 1, 0);
    forn (i, n) {
        pref[i + 1] = pref[i] + a[i];
    }
    vector<int> pref2(n + 2, 0);
    forn (i, n) {
        pref2[i + 2] = pref2[i] + a[i];
    }
    int res = 0;
    for (int len = 1; len < n; len++) {
        int l = -1, r = (n - len + 1) / 2;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            int sum = pref2[len + 1 + mid * 2] - pref2[len + 1];
            if (pref[len] + sum + margin < pref[n] - pref[len] - sum) {
                l = mid;
            } else {
                r = mid;
            }
        }
        res += l + 1;
        //cerr << l + 1 << endl;
    }
    return res;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        forn (i, n) {
            cin >> a[i];
        }
        if (n == 1) {
            cout << 1 << "\n";
            continue;
        }
        if (n == 2) {
            cout << 1 + (a[0] != a[1]) << "\n";
            continue;
        }
        if (n == 3) {
            cout << 1 + (a[0] != a[1] + a[2]) + (a[1] != a[0] + a[2]) + (a[2] != a[1] + a[0]) << "\n";
            continue;
        }
        int ans = 0;
        ans += solve(a, 0);
        auto b = a;
        b.pop_back();
        ans += solve(b, a.back());
        b.clear();
        for (int i = 1; i < a.size(); i++) {
            b.push_back(a[i]);
        }
        ans += solve(b, -a[0]);
        b.pop_back();
        ans += solve(b, a.back() - a[0]);
        int sum_r = 0;
        forn (i, n) {
            sum_r += a[i];
        }
        int sum_l = 0;
        for (int i = 0; i <= n; i++) {
            if (sum_l > sum_r) {
                ans++;
            }
            if (i < n) {
                sum_l += a[i];
                sum_r -= a[i];
            }
        }
        cout << ans % 998244353 << "\n";
    }
}