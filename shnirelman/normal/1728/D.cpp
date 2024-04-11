#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int M = 998244353;
const int N = 2000 + 13;
const int A = 26;
const int B = 400;

int dp[N][N];

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    for(int i = 0; i < n; i++) {
        dp[i][i + 1] = -1;
    }

    for(int i = 0; i < n - 1; i++) {
        if(s[i] == s[i + 1])
            dp[i][i + 2] = 0;
        else
            dp[i][i + 2] = 1;
    }

    for(int len = 3; len <= n; len++) {
        for(int l = 0; l + len <= n; l++) {
            int r = l + len;
            dp[l][r] = -1;
            for(int x = 0; x < 2; x++) {
                char cx = (x == 0 ? s[l] : s[r - 1]);
                int mn = 1;
                for(int y = 0; y < 2; y++) {
                    char cy = (y == 0 ? s[l + (x == 0)] : s[r - 1 - x]);
                    int lf = l + (x == 0) + (y == 0);
                    int rg = r - x - y;

                    if(dp[lf][rg] == 0) {
                        mn = min(mn, cx == cy ? 0 : (cx < cy ? 1 : -1));
                    } else {
                        mn = min(mn, dp[lf][rg]);
                    }
                }

                dp[l][r] = max(dp[l][r], mn);
            }
        }
    }

    if(dp[0][n] == 1)
        cout << "Alice" << endl;
    else if(dp[0][n] == 0)
        cout << "Draw" << endl;
    else
        cout << "Bob" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}