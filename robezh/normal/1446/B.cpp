#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 5005, INF = (int)1e9;

int n, m;
string s, t;
int dp[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> s >> t;
    s = " " + s;
    t = " " + t;
    int res = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = 0;
            dp[i][j] = max(dp[i][j], dp[i - 1][j] - 1);
            dp[i][j] = max(dp[i][j], dp[i][j - 1] - 1);
            if(s[i] == t[j]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 2);
            res = max(res, dp[i][j]);
        }
    }
    cout << res << '\n';


}