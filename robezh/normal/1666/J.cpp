#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
typedef long long ll;

const int N = 205;
const ll INF = (ll)1e18;

int n;
ll c[N][N];
ll dp[N][N];

ll get_rect(int il, int ir, int jl, int jr) {
    return c[ir][jr] - c[il - 1][jr] - c[ir][jl - 1] + c[il - 1][jl - 1];
}

ll get_contri(int l, int r) {
    if(r < l) return 0;
    return get_rect(l, r, 1, n) - get_rect(l, r, l, r);
}

ll solve(int l, int r) {
    if(dp[l][r] != -1) return dp[l][r];
    if(l >= r) {
        return dp[l][r] = 0;
    }
    dp[l][r] = INF;
    for (int mid = l; mid <= r; mid++) {
        dp[l][r] = min(dp[l][r], get_contri(l, mid - 1) + get_contri(mid + 1, r) +
            solve(l, mid - 1) + solve(mid + 1, r));
    }
    return dp[l][r];
}
int res[N];

void recur(int l, int r, int p) {
    if(l > r) {
        return ;
    }
    if(l == r) {
        res[l] = p;
        return ;
    }
    for (int mid = l; mid <= r; mid++) {
        if(solve(l, r) == get_contri(l, mid - 1) + get_contri(mid + 1, r) +
                                      solve(l, mid - 1) + solve(mid + 1, r)) {
            res[mid] = p;
            recur(l, mid - 1, mid);
            recur(mid + 1, r, mid);
            return ;
        }
    }
    assert(false);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 1, n + 1) {
        rep(j, 1, n + 1) {
            cin >> c[i][j];
            c[i][j] += c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1];
        }
    }
    memset(dp, -1, sizeof dp);
//    cout << solve(1, n);
    recur(1, n, 0);
    rep(i, 1, n + 1) cout << res[i] << " ";
    cout << endl;

}