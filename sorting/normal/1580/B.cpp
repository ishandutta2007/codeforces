#include <bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 100 + 3;

int n, m, k, p;
ll comb[N][N], f[N];
ll dp[N][N][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k >> p;
    --m;
    comb[0][0] = 1;
    for(int i = 1; i < N; ++i){
        comb[i][0] = 1;
        for(int j = 1; j <= i; ++j)
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % p;
    }
    f[0] = 1;
    for(int i = 1; i < N; ++i)
        f[i] = f[i - 1] * i % p;

    for(int add = m; add >= 0; --add){
        for(int n = 0; n <= ::n; ++n){
            for(int k = 0; k <= ::k; ++k){
                if(!n){
                    dp[add][n][k] = !k;
                    continue;
                }
                if(add == m){
                    if(k == 1) dp[add][n][k] = f[n];
                    else dp[add][n][k] = 0;
                    continue;
                }
                if(k && n < k + max(m - add, k - 1)){
                    dp[add][n][k] = 0;
                    continue;
                }

                dp[add][n][k] = 0;
                for(int i = 0; i <= (n - 1) / 2; ++i){
                    ll curr = 0;
                    for(int j = 0; j <= k; ++j)
                        curr = (curr + dp[add + 1][i][j] * dp[add + 1][n - 1 - i][k - j]) % p;
                    if(i * 2 == n - 1) dp[add][n][k] = (dp[add][n][k] + curr * comb[n - 1][i]) % p;
                    else dp[add][n][k] = (dp[add][n][k] + 2ll * curr * comb[n - 1][i]) % p;
                }
                //cout << ans << " - " << add << " " << n << " " << k << endl;
            }
        }
    }
    cout << dp[0][n][k] << "\n";
}