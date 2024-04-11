#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 405;

ll dp[N][N];
int n, mod;

void add(ll &to, ll v) {
    to = (to + v) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> mod;

    dp[0][0] = 1;
    rep(i, 0, n) {
        rep(j, 0, n + 1) {
            add(dp[i + 1][j + 1], dp[i][j] * (j + 1));

            add(dp[i + 1][j], dp[i][j] * 2 * j);
            add(dp[i + 2][j], dp[i][j] * 2 * j);

            if(j >= 2) {
                add(dp[i + 2][j - 1], dp[i][j] * (j - 1) * 2);
                add(dp[i + 3][j - 1], dp[i][j] * (j - 1));
            }
        }
    }
    cout << dp[n][1] << '\n';
}