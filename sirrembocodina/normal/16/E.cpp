#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
 
vector<vector<double>> p;

int main() {
    int n;
    cin >> n;
    p.resize(n, vector<double>(n));
    forn (i, n) {
        forn (j, n) {
            cin >> p[i][j];
        }
    }
    vector<vector<double>> dp(1 << n, vector<double>(n, 0));
    forn (i, n) {
        dp[1 << i][i] = 1;
    }
    forn (mask, 1 << n) {
        if (__builtin_popcount(mask) <= 1) {
            continue;
        }
        vector<int> a;
        forn (i, n) {
            if (mask & (1 << i)) {
                a.push_back(i);
            }
        }
        int len = a.size();
        double q = 2.0 / len / (len - 1);
        for (int i: a) {
            for (int j: a) {
                for (int k: a) {
                    if (k == j) {
                        continue;
                    }
                    dp[mask][i] += dp[mask ^ (1 << j)][i] * p[k][j] * q;
                }
            }
        }
    }
    forn (i, n) {
        cout << dp[(1 << n) - 1][i] << " ";
    }
}