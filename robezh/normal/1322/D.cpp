#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 2005, M = 4005;
const int INF = (int)1e9;

int n, m;
int l[N], s[N];
int c[M];
int dp[M][M];

void umax(int &to, int val) {
    to = max(to, val);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> l[i];
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 1; i <= n + m; i++) cin >> c[i];

    for(int i = 0; i < M; i++) {
        fill(dp[i], dp[i] + M, -INF);
        dp[i][0] = 0;
    }
    for(int i = n - 1; i >= 0; i--) {
        for(int j = M - 1; j >= 1; j--) {
            if(dp[l[i]][j - 1] != -INF) umax(dp[l[i]][j], dp[l[i]][j - 1] + c[l[i]] - s[i]);
        }
        int up = M - 1;
        for(int a = l[i]; a <= m + n - 1; a++) {
            for(int j = 0; j <= up; j++) {
                if(dp[a][j] != -INF) umax(dp[a + 1][j / 2], dp[a][j] + (j / 2) * c[a + 1]);
            }
            up = up / 2;
        }
    }
    int res = -INF;
    for(int i = 0; i <= n + m; i++) for(int j = 0; j <= 1; j++) {
        res = max(res, dp[i][j]);
//        cout << i << ", " << j << ": " << dp[i][j] << endl;

    }
    cout << res << '\n';


}