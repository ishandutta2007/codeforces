#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 1e5 + 13;
const int LOGN = 30;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<vector<vector<pii>>> dp(n, vector<vector<pii>>(2, vector<pii>(2, pii(INF, INF))));
    dp[0][1][s[0] - '0'] = {0, 1};
    dp[0][1][(s[0] - '0') ^ 1] = {1, 1};

    for(int i = 1; i < n; i++) {
        for(int a = 0; a < 2; a++) {
            for(int x = 0; x < 2; x++) {
                for(int y = 0; y < 2; y++) {
                    if(x == y) {
                        pii res = {dp[i - 1][a][x].f + (y != s[i] - '0'), dp[i - 1][a][x].s};
                        dp[i][a ^ 1][y] = min(dp[i][a ^ 1][y], res);
                    } else if(a % 2 == 0) {
                        pii res = {dp[i - 1][a][x].f + (y != s[i] - '0'), dp[i - 1][a][x].s + 1};
                        dp[i][a ^ 1][y] = min(dp[i][a ^ 1][y], res);
                    }

                }
            }
        }

    }

    pii ans = min(dp[n - 1][0][0], dp[n - 1][0][1]);

    cout << ans.f << ' ' << ans.s << endl;

//    vector<int> a(1, 1);
//    for(int i = 1; i < n; i++) {
//        if(s[i] == s[i - 1])
//            a.back()++;
//        else
//            a.push_back(1);
//    }



//    cout << ans << ' ' << cnt << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}