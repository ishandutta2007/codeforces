#include <iostream>
using namespace std;
typedef long long ll;

const ll INF = 1000000000000000;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        ll a[300005];
        for(int i = 0; i < n; i++) cin >> a[i];
        ll dp[300005][2];
        dp[0][0] = 0;
        dp[0][1] = -INF;
        for(int i = 1; i <= n; i++){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - a[i - 1]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + a[i - 1]);
        }
        cout << max(dp[n][0], dp[n][1]) << endl;
    }
}