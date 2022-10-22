#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

ll dp[302][202][202];

int main()
{
    int r, g, b;
    cin >> r >> g >> b;
    ll x[202], y[202], z[202];
    for(int i = 0; i < r; i++) cin >> x[i];
    for(int i = 0; i < g; i++) cin >> y[i];
    for(int i = 0; i < b; i++) cin >> z[i];
    sort(x, x + r, greater<ll>());
    sort(y, y + g, greater<ll>());
    sort(z, z + b, greater<ll>());
    ll ans = 0;
    for(int i = 0; i <= (r + g + b) / 2; i++){
        for(int j = 0; j <= r; j++){
            for(int k = 0; k <= g; k++){
                int l = i * 2 - j - k;
                if(l < 0 || l > b) continue;
                if(j < r && k < g){
                    dp[i + 1][j + 1][k + 1] = max(dp[i + 1][j + 1][k + 1], dp[i][j][k] + x[j] * y[k]);
                }
                if(j < r && l < b){
                    dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k] + x[j] * z[l]);
                }
                if(k < g && l < b){
                    dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k] + y[k] * z[l]);
                }
                ans = max(ans, dp[i][j][k]);
            }
        }
    }
    cout << ans << endl;
}