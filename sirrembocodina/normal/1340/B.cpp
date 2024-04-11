#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define sqr(x) (x) * (x)

using namespace std;

bool submask(string& a, string& b) {
    forn (i, 7) {
        if (a[i] == '1' && b[i] == '0') {
            return false;
        }
    }
    return true;
}

int pc(string &s) {
    int res = 0;
    forn (i, 7) {
        res += s[i] == '1';
    }
    return res;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    vector<string> d = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    forn (i, n) {
        cin >> s[i];
    }
    reverse(s.begin(), s.end());
    vector<vector<bool> > can(n + 1, vector<bool>(10, false));
    vector<int> pc1(n), pc2(10);
    forn (i, n) {
        forn (j, 10) {
            can[i][j] = submask(s[i], d[j]);
        }
        pc1[i] = pc(s[i]);
    }
    forn (i, 10) {
        pc2[i] = pc(d[i]);
    }
    vector<vector<bool> > dp(n + 1, vector<bool>(k + 1, false));
    dp[0][0] = true;
    forn (i, n) {
        forn (j, k + 1) {
            if (!dp[i][j]) {
                continue;
            }
            forn (l, 10) {
                if (can[i][l] && pc2[l] - pc1[i] + j <= k) {
                    dp[i + 1][pc2[l] - pc1[i] + j] = true;
                }
            }
        }
    }
    if (!dp[n][k]) {
        cout << -1 << endl;
        return 0;
    }
    string ans = "";
    for (int i = n - 1; i >= 0; --i) {
        int mx = -1;
        forn (l, 10) {
            if (can[i][l] && pc2[l] - pc1[i] <= k && dp[i][k - pc2[l] + pc1[i]]) {
                mx = l;
            }
        }
        k -= pc2[mx] - pc1[i];
        ans += '0' + mx;
    }
    cout << ans << endl;
}