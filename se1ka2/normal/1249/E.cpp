#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll n, c;
    cin >> n >> c;
    ll a[200005];
    for(int i = 0; i < n - 1; i++) cin >> a[i];
    ll b[200005];
    for(int i = 0; i < n - 1; i++) cin >> b[i];
    ll dp[200005][2];
    dp[0][0] = 0;
    dp[0][1] = 1000000000;
    for(int i = 1; i < n; i++){
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + a[i - 1];
        dp[i][1] = min(dp[i - 1][0] + b[i - 1] + c, dp[i - 1][1] + b[i - 1]);
    }
    for(int i = 0; i < n; i++) cout << min(dp[i][0], dp[i][1]) << " ";
    cout << endl;
}