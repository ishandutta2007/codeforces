//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<li, li>;
//using matr

const li INF = 2e18 + 13;
const int N = 2e5 + 13;
const int M = 998244353;
const int B = 300;
//const int A = 26;
const ld e = 1e-8;
const int LOGN = 20;
const int K = 170;

mt19937 rnd(0);

/*

*/

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    vector<vector<int>> dp(n + 1, vector<int>(8, INF));
    dp[0][0] = 0;

    vector<int> res(8, 0);
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 3; j++) {
            if((i >> j) & 1) {
                res[i]++;
            } else {
                break;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        int x = (s[i] - '0');
        for(int mask = 0; mask < 8; mask++) {
            int nmask = mask | (1 << x);
            dp[i + 1][nmask] = min(dp[i + 1][nmask], dp[i][mask] + res[nmask] - res[mask]);
            dp[i + 1][1 << x] = min(dp[i + 1][1 << x], dp[i][mask] + res[1 << x]);
        }
    }

    int mn = INF;
    for(int i = 0; i < 8; i++)
        mn = min(mn, dp[n][i]);

    cout << mn << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}