#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 16, INF = (int)1e9;

int dp[11][18][18][18];
int n, a, b;
int h[N];

int solve(int i, int l, int m, int r) {
    if(dp[i][l][m][r] != -1) return dp[i][l][m][r];
    if(l == 0 && m == 0 && r == 0 && i == n - 2) return 0;

    int &res = dp[i][l][m][r] = INF;
    if(l == 0 && i + 2 < n) {
        res = min(res, solve(i + 1, m, r, h[i + 2]));
    }
    if(l != 0 || m != 0 || r != 0) {
        res = min(res, 1 + solve(i, max(0, l - b), max(0, m - a), max(0, r - b)));
    }
    return res;
}

vi rs;

void track(int i, int l, int m, int r) {
    if(l == 0 && m == 0 && r == 0 && i == n - 2) return ;

    int &res = dp[i][l][m][r];
    if(l == 0 && i + 2 < n) {
        if(solve(i + 1, m, r, h[i + 2]) == res) {
            track(i + 1, m, r, h[i + 2]);
            return ;
        }
    }
    rs.push_back(i);
    track(i, max(0, l - b), max(0, m - a), max(0, r - b));
}

int main() {
    memset(dp, -1, sizeof(dp));

    cin >> n >> a >> b;
    rep(i, 0, n) cin >> h[i], h[i]++;
    cout << solve(1, h[0], h[1], h[2]) << '\n';
    track(1, h[0], h[1], h[2]);
    for(int x : rs) cout << x + 1 << " ";
    cout << '\n';

}