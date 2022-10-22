#include <iostream>
using namespace std;
typedef long long ll;

ll dp[5005][5005];

ll dfs(int l, int r, ll s, ll *a, ll *b){
    if(r - l <= 1) return s;
    if(dp[l][r]) return dp[l][r];
    return dfs(l + 1, r - 1, s, a, b) - a[l] * b[l] - a[r - 1] * b[r - 1] + a[l] * b[r - 1] + a[r - 1] * b[l];
}

int main()
{
    int n;
    cin >> n;
    ll a[5005], b[5005];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    ll s = 0;
    for(int i = 0; i < n; i++) s += a[i] * b[i];
    ll ans = s;
    for(int k = 0; k <= n; k++){
        for(int l = 0; l <= n - k; l++){
            int r = l + k;
            if(k == 0 || k == 1) dp[l][r] = s;
            else dp[l][r] = dp[l + 1][r - 1] - a[l] * b[l] - a[r - 1] * b[r - 1] + a[l] * b[r - 1] + a[r - 1] * b[l];
            ans = max(ans, dp[l][r]);
        }
    }
    cout << ans << endl;
}