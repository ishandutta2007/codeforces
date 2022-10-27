#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int MAXN = 10000 + 10;
ll dp[MAXN], p[MAXN], s[MAXN];
int main()
{
    ll n, c, i, j;
    cin >> n >> c;
    for(i = 1; i <= n; i++) cin >> p[i];
    for(i = 1; i <= n; i++) cin >> s[i];
    dp[0] = 0;
    for(i = 1; i <= n; i++)
    {
        dp[i] = 1e18;
        for(j = i; j >= 1; j--)
        {
            dp[j] = min(dp[j] + p[i] + j*c, dp[j-1] + s[i]);
        }
        dp[0] += p[i];
    }
    ll res = 1e18;
    for(i = 0; i <= n; i++) res = min(res, dp[i]);
    cout << res << endl;
}