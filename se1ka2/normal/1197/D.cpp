#include <iostream>
using namespace std;
typedef long long ll;

const ll INF = 100000000000000000;

ll dp[300005][10];

int main()
{
    ll n, m, p;
    cin >> n >> m >> p;
    ll a[300005];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i <= n; i++) for(int j = 1; j < m; j++) dp[i][j] = -INF;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            ll s = 0;
            for(int k = 1; k <= m; k++){
                if(k > i) continue;
                s += a[i - k];
                if(j > k) dp[i][j] = max(dp[i][j], dp[i - k][j - k] + s);
                else dp[i][j] = max(dp[i][j], dp[i - k][(j - k + m) % m] + s - p);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
}