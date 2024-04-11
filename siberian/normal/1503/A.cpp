#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()
#define mp make_pair

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

const int BUBEN = 10;
const int N = 2e5 + 10;
int n;
string s;
int dp[N][BUBEN][BUBEN];

void solve() {
    cin >> n >> s;
    // reverse(all(s));
    for (int i = 0; i <= n; ++i) {
        for (int bal1 = 0; bal1 < BUBEN; ++bal1) {
            for (int bal2 = 0; bal2 < BUBEN; ++bal2) {
                dp[i][bal1][bal2] = -1;
            }
        }
    }

    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int bal1 = 0; bal1 < BUBEN; ++bal1) {
            for (int bal2 = 0; bal2 < BUBEN; ++bal2) {
                if (dp[i][bal1][bal2] == -1) continue;

                if (s[i] == '1') {
                    if (max(bal1, bal2) + 1 < BUBEN) {
                        dp[i + 1][bal1 + 1][bal2 + 1] = 0;
                    }
                    if (min(bal1, bal2) > 0) {
                        dp[i + 1][bal1 - 1][bal2 - 1] = 1;
                    }
                } else {
                    if (bal1 + 1 < BUBEN && bal2 > 0) {
                        dp[i + 1][bal1 + 1][bal2 - 1] = 2;
                    }
                    if (bal1 > 0 && bal2 + 1 < BUBEN) {
                        dp[i + 1][bal1 - 1][bal2 + 1] = 3;
                    }
                }
            }
        }
    }

    if (dp[n][0][0] == -1) {
        cout << "NO\n";
        return;
    }
    string ans1 = "";
    string ans2 = "";
    int bal1 = 0, bal2 = 0;
    for (int pos = n; pos >= 1; --pos) {
        // cout << "pos = " << pos << " bal1 = " << bal1 << " bal2 = " << bal2 << endl;
        int val = dp[pos][bal1][bal2];
        assert(val != -1);
        if (val == 0) {
            ans1 += "(";
            ans2 += "(";
            bal1--;
            bal2--;
        } else if (val == 1) {
            ans1 += ")";
            ans2 += ")";
            bal1++;
            bal2++;
        } else if (val == 2) {
            ans1 += "(";
            ans2 += ")";
            bal1--;
            bal2++;
        } else if (val == 3) {
            ans1 += ")";
            ans2 += "(";
            bal1++;
            bal2--;
        }
    }
    reverse(all(ans1));
    reverse(all(ans2));
    cout << "YES\n";
    cout << ans1 << '\n';
    cout << ans2 << '\n';
    cout.flush();
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}