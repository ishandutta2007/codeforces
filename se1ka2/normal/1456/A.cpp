#include <iostream>
using namespace std;
typedef long long ll;

const ll INF = 10000000000009;

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll n, p, k;
        cin >> n >> p >> k;
        p--;
        string s;
        cin >> s;
        ll x, y;
        cin >> x >> y;
        ll dp[200005];
        for(int i = 0; p + i < n; i++){
            dp[p + i] = i * y;
            if(s[p + i] == '0') dp[p + i] += x;
        }
        for(int i = p + k; i < n; i++){
            if(s[i] == '0') dp[i] = min(dp[i - k] + x, dp[i]);
            else dp[i] = min(dp[i], dp[i - k]);
        }
        ll ans = INF;
        for(int i = n - 1; i + k >= n && i >= p; i--) ans = min(ans, dp[i]);
        cout << ans << endl;
    }
}