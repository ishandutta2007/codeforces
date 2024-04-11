#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 998244353;
const ll MAXN = 5007;
const double EPS = 1e-8;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    ll a, b, c;
    cin >> a >> b >> c;
    vector <vector <ll> > dp(MAXN, vector <ll> (MAXN, 1));
    for (ll i = 1; i < MAXN; i++) {
        for (ll j = 1; j < MAXN; j++) {
            dp[i][j] = (j * dp[i - 1][j - 1] + dp[i - 1][j]) % INF;
        }
    }
    cout << dp[a][b] * dp[b][c] % INF * dp[a][c] % INF;
}