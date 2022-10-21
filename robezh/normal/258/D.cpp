#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)1e3 + 50;

int n, m;
double dp[N][N];
int p[N];

struct Up{
    int i, j;
    double val;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 0, n) cin >> p[i], p[i]--;
    rep(i, 0, n) {
        rep(j, 0, n) if(p[i] > p[j]) dp[i][j] = 1;
    }
    rep(i, 0, m) {
        vector<Up> us;
        int a, b; cin >> a >> b; a--, b--;
        for(int j = 0; j < n; j++) {
            if(j == a || j == b) continue;
            us.push_back({j, a, 0.5 * (dp[j][a] + dp[j][b])});
            us.push_back({a, j, 0.5 * (dp[a][j] + dp[b][j])});
            us.push_back({j, b, 0.5 * (dp[j][a] + dp[j][b])});
            us.push_back({b, j, 0.5 * (dp[a][j] + dp[b][j])});
        }
        us.push_back({a, b, 0.5 * (dp[a][b] + dp[b][a])});
        us.push_back({b, a, 0.5 * (dp[a][b] + dp[b][a])});
        for(auto u : us) {
            dp[u.i][u.j] = u.val;
        }
    }
    double res = 0;
    rep(i, 0, n) rep(j, i + 1, n) res += dp[i][j];
    cout << fixed << setprecision(9) << res << '\n';

}