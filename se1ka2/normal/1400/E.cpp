#include <iostream>
using namespace std;
typedef long long ll;

const ll INF = 100000000000000;

ll dp[5002][5002];

int main()
{
    int n;
    cin >> n;
    ll a[5002];
    a[0] = 0;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++) dp[i][j] = INF;
    }
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            if(a[j] <= a[i - 1]){
                if(a[j] == a[i]) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                dp[i][i] = min(dp[i][i], dp[i - 1][j] + max(0ll, a[i] - a[j]));
            }
        }
    }
    ll ans = n;
    for(int j = 0; j <= n; j++) ans = min(ans, dp[n][j]);
    cout << ans << endl;
}