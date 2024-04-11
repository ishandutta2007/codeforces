#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 4005, INF = (int)1e9;

int n, k;
int u[N][N];
int dp[N][N];
int c[N][N];

void solve(int b, int l, int r, int tl, int tr) {
    if(l > r) return ;
    int mid = (l + r) / 2;
    int best = INF, tmid = -1;
    for(int t = tl; t <= tr && t < mid; t++) {
        int curval = dp[b - 1][t] + c[t][mid];
        if(curval < best) {
            best = curval;
            tmid = t;
        }
    }
    dp[b][mid] = best;
    solve(b, l, mid - 1, tl, tmid);
    solve(b, mid + 1, r, tmid, tr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    rep(i, 1, n + 1) rep(j, 1, n + 1) {
        cin >> u[i][j];
        u[i][j] += u[i-1][j] + u[i][j-1] - u[i-1][j-1];
    }
    rep(i, 0, n + 1) {
        rep(j, i + 1, n + 1) c[i][j] = (u[j][j] - u[i][j] - u[j][i] + u[i][i]) / 2;
    }
    rep(i, 0, n + 1) dp[0][i] = INF;
    dp[0][0] = 0;
    rep(b, 1, k + 1) {
        solve(b, 1, n, 0, n - 1);
    }
    cout << dp[k][n] << '\n';
}