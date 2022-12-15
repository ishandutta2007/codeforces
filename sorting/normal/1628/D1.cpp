#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 2000 + 3;
const ll MOD = 1e9 + 7;

pair<ll, ll> dp[N][N];
ll k;
int n, m;

ll fast_pow(ll base, ll exp){
    if(!exp) return 1ll;
    if(exp & 1) return base * fast_pow(base, exp - 1) % MOD;
    ll t = fast_pow(base, exp >> 1);
    return t * t % MOD;
}

void solve(){
    cin >> n >> m >> k;

    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= m; ++j){
            pair<ll, ll> &ans = dp[i][j];

            if(j == i){
                ans = {k * i % MOD, 1};
                continue;
            }
            if(!j){
                ans = {0, 1};
                continue;
            }

            auto down = dp[i  - 1][j - 1];
            auto up = dp[i - 1][j];

            ans.first = (up.first * down.second + up.second * down.first) % MOD;
            ans.second = up.second * down.second * 2 % MOD;
        }
    }

    cout << (dp[n][m].first * fast_pow(dp[n][m].second, MOD - 2)) % MOD << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        solve();
}