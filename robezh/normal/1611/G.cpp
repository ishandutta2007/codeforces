#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        vector<string> str(n);
        vector<vi> dp(n, vi(m, 0));
        rep(i, 0, n) cin >> str[i];
        int rs[2] = {0, 0};
        for(int j = m - 1; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                if(str[i][j] == '1') {
                    dp[i][j] = 1 + (j + 2 < m ? dp[i][j + 2] : 0);
                }
                if(i >= 1 && j + 1 < m) dp[i][j] = max(dp[i][j], dp[i - 1][j + 1]);
                if(i + 1 < n && j + 1 < m) dp[i][j] = max(dp[i][j], dp[i + 1][j + 1]);
                if(j + 2 < m) dp[i][j] = max(dp[i][j], dp[i][j + 2]);
                rs[(i + j) % 2] = max(rs[(i + j) % 2], dp[i][j]);
            }
        }
//        rep(i, 0, n) rs[i % 2] = max(rs[i % 2], dp[i][0]);
        cout << (rs[0] + rs[1]) << '\n';
    }
}