#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < (N); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back

using ll = long long;
using i_i = tuple<int, int>;

int INF = INT_MAX / 2;

int dp[1000100][3][3];

int main() {
    int N, X;
    cin >> N >> X;
    X += 10;
    vector<int> a(X);
    rep(i, N) {
        int x; scanf("%d", &x);
        a[x]++;
    }
    rep(x, X) {
        rep(p, 3) rep(q, 3) dp[x + 1][p][q] = -INF;
        rep(p, 3) rep(q, 3) rep(r, 3) {
            int t = a[x] - p - q - r;
            if (t < 0) continue;
            dp[x + 1][q][r] = max(dp[x + 1][q][r], dp[x][p][q] + r + t / 3);
        }
    }
    cout << dp[X][0][0] << endl;
}