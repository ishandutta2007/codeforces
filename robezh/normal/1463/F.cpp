#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, x, y;
int dp[2][(1 << 22) + 2];

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> x >> y;
    int nw = 0, la = 1;
    dp[nw][0] = 0;
    int M = (1 << max(x, y));
    rep(i, 0, x + y) {
        int cost = (n - 1 - i + x + y) / (x + y);
        swap(nw, la);

        memset(dp[nw], -1, sizeof(dp[nw]));
        rep(mask, 0, M) {
            if(dp[la][mask] == -1) continue;
            int nmask = (mask << 1) & (M - 1);
            if(!(mask >> (x - 1) & 1) && !(mask >> (y - 1) & 1))
                dp[nw][nmask | 1] = max(dp[nw][nmask | 1], dp[la][mask] + cost);
            dp[nw][nmask] = max(dp[nw][nmask], dp[la][mask]);
        }
    }
    int res = 0;
    rep(i, 0, M) res = max(res, dp[nw][i]);
    cout << res << '\n';
}