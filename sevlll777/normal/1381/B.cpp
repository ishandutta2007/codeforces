#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

#define pb push_back
// #define int long long
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> P(2 * n + 1);
        for (int i = 1; i <= 2 * n; i++) cin >> P[i];
        vector<bool> used(2 * n + 1, false);
        int mem = 2 * n;
        int now = 2 * n;
        vector<int> Y = {0};
        while (now >= 1) {
            int sz = 1;
            while (now >= 1 && P[now] != mem) {
                used[P[now]] = true;
                now--;
                sz++;
            }
            Y.pb(sz);
            mem--;
            now--;
            while (mem >= 1 && used[mem]) {
                mem--;
            }
        }
        int ys = (int) Y.size();
        vector<vector<bool>> dp(ys + 2, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 1; i < ys; i++) {
            for (int c = 0; c <= n; c++) {
                if (dp[i - 1][c]) dp[i][c] = true;
                if (c >= Y[i] && dp[i - 1][c - Y[i]]) dp[i][c] = true;
            }
        }
        if (dp[ys-1][n]) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << '\n';
    }

}