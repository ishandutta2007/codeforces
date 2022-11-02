#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

bool check(int pos, const vector<int>& a) {
    return pos > 0 && pos + 1 < a.size() && ((a[pos] < a[pos - 1] && a[pos] < a[pos + 1]) || (a[pos] > a[pos - 1] && a[pos] > a[pos + 1]));
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    vector<int> pref(n);
    vector<int> suff(n);
    for (int i = 0; i < n; ++i) {
        pref[i] = suff[i] = check(i, a);
    }
    for (int i = 1; i < n; ++i) {
        pref[i] += pref[i - 1];
    }
    for (int i = n - 2; i >= 0; --i) {
        suff[i] += suff[i + 1];
    }
    int ans = pref[n - 1];

    // 1 2 3 4 5 x 6 7 8 9 
    for (int i = 0; i < n; ++i) {
        int val = a[i];
        for (int d = -1; d <= 1; ++d) {
            if (i > 0) {
                a[i] = a[i - 1] + d;
                int fans = 0;
                if (i - 2 >= 0) {
                    fans += pref[i - 2];
                }
                if (i + 2 < n) {
                    fans += suff[i + 2];
                }
                for (int dx = -1; dx <= 1; ++dx) {
                    fans += check(i + dx, a);
                }
                chkmin(ans, fans);
            } 
            if (i + 1 < n) {
                a[i] = a[i + 1] + d;
                int fans = 0;
                if (i - 2 >= 0) {
                    fans += pref[i - 2];
                }
                if (i + 2 < n) {
                    fans += suff[i + 2];
                }
                for (int dx = -1; dx <= 1; ++dx) {
                    fans += check(i + dx, a);
                }
                chkmin(ans, fans);
            }
        }
        a[i] = val;
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}