#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 105;

int n, m;
int lb[N][N], rb[N][N];
int dp[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 0, n) {
        int k; cin >> k;
        rep(j, 0, k) {
            int a, b; cin >> a >> b; a--, b--;
            rep(l, a, b + 1) lb[i][l] = a, rb[i][l] = b;
        }
    }
    for(int len = 1; len <= m; len++) {
        for(int l = 0; l + len <= m; l++) {
            int r = l + len - 1;
            for(int k = l; k <= r; k++) {
                int cnt = 0;
                for(int i = 0; i < n; i++) {
                    cnt += (l <= lb[i][k] && rb[i][k] <= r);
                }
                int val = cnt * cnt;
                if(k > l) val += dp[l][k - 1];
                if(k < r) val += dp[k + 1][r];
                dp[l][r] = max(dp[l][r], val);
            }
        }
    }
    cout << dp[0][m - 1];

}