#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 52;

int n, h, m;
int dp[N][N][N], ssum[N][N][N][N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> h >> m;
    rep(i, 0, m) {
        int l, r, x, c;
        cin >> l >> r >> x >> c;
        for(int li = 1; li <= l; li++) {
            for(int ri = r; ri <= n; ri++) {
                for(int mx = l; mx <= r; mx++) {
                    ssum[li][ri][mx][x + 1] += c;
                }
            }
        }
    }
    for(int li = 1; li <= n; li++) {
        for(int ri = li; ri <= n; ri++) {
            for(int mx = li; mx <= ri; mx++) {
                for(int x = 1; x <= h; x++) ssum[li][ri][mx][x] += ssum[li][ri][mx][x - 1];
            }
        }
    }
    for(int k = 1; k <= h; k++) {
        for (int len = 1; len <= n; len++) {
            for (int i = 1; i + len - 1 <= n; i++) {
                int j = i + len - 1;
                dp[i][j][k] = dp[i][j][k - 1];
                for (int mx = i; mx <= j; mx++) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i][mx - 1][k - 1] + dp[mx + 1][j][k] - ssum[i][j][mx][k] + k * k);
                }
//                cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
            }
        }

    }
    cout << dp[1][n][h] << endl;
}