#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
const int N = (int)1e5 + 50, INF = (int)1e9;
int n;
string str;
int dp[N][2][2];

bool good(int cur, int i, int j, int k) {
    if(cur == 1) return true;
    if(cur >= 2 && str[cur - 1] == str[cur] && j == 0 && k == 0) return false;
    if(cur >= 3 && str[cur - 2] == str[cur] && i == 0 && k == 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> str;
        n = str.length();
        str = " " + str;
        for(int i = 0; i <= n; i++) {
            rep(k, 0, 2) rep(t, 0, 2) dp[i][k][t] = INF;
        }
        dp[0][0][0] = 0;
        int res = INF;
        rep(i, 1, n + 1) {
            for(int j = 0; j < 2; j++) {
                for(int k = 0; k < 2; k++) {
                    for(int t = 0; t < 2; t++) {
                        if(good(i, j, k, t)) dp[i][k][t] = min(dp[i][k][t], dp[i - 1][j][k] + t);
                        if(i == n) res = min(res, dp[i][k][t]);
                    }
                }
            }
        }
        cout << res << '\n';

    }


}