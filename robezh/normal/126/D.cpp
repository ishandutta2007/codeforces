#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pl;
const int N = (int)87;
const ll INF = (ll)1e18;

ll fib[N], psum[N];
ll dp[2][N];
int bit[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fib[0] = 1;
    fib[1] = 1;
    for(int i = 2; i < N; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    int T;
    cin >> T;
    ll cnt = 0;
    while(T--) {
        memset(dp, 0, sizeof(dp));
        ll x; cin >> x;
        for(int i = N - 1; i >= 1; i--) {
            if(x >= fib[i]) bit[i] = 1, x -= fib[i];
            else bit[i] = 0;
        }
        dp[0][N-1] = 1;
        dp[1][N-1] = 0;
        for(int i = N - 1; i >= 1; i--) {
            if(!bit[i]) {
                dp[0][i-1] += (dp[1][i] + dp[0][i]);
                if(i >= 2 && !bit[i-1]) dp[1][i-2] += dp[1][i];
            }
            else {
                if(i >= 2 && !bit[i-1]) dp[1][i-2] += dp[1][i] + dp[0][i];
                dp[0][i-1] += dp[0][i];
            }
        }
        cout << dp[0][0] << "\n";
    }
}