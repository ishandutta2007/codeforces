#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int M = 40000, N = 105, H = 20000;

int n;
int a[N], b[N];
int dp[2][M][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 1, n + 1) {
        cin >> a[i] >> b[i];
        a[i] *= 2, b[i] *= 2;
    }
    memset(dp, -1, sizeof(dp));
    int la = 0, nw = 1;
    dp[nw][H][0] = 0;
    rep(i, 1, n + 1) {
        swap(la, nw);
        memset(dp[nw], -1, sizeof(dp[nw]));
        rep(j, 0, M - (a[i] - b[i])) {
            int nrem = min(H, j + (a[i] - b[i])), rem = min(H, j);
            rep(k, 0, i) {
                if(dp[la][j][k] != -1) dp[nw][j + (a[i] - b[i])][k + 1] = dp[la][j][k] + b[i] + (nrem - rem);
            }
        }
        rep(j, b[i] / 2, M) {
            int nrem = max(H, j - b[i] / 2), rem = max(H, j);
            rep(k, 0, i + 1)
                if(dp[la][j][k] != -1)
                    dp[nw][j - b[i] / 2][k] = max(dp[nw][j - b[i] / 2][k], dp[la][j][k] + (rem - nrem));
        }
    }
    rep(i, 1, n + 1) {
        int res = 0;
        rep(j, 0, M) res = max(res, dp[nw][j][i]);
        cout << fixed << setprecision(10) << (double)res / 2 << " ";
    }
    cout << '\n';
}