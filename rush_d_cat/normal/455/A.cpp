#include <iostream>
using namespace std;
const int NICO = 100000 + 10;
typedef long long ll;
ll sum[NICO], dp[NICO], x, n;
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> x;
        sum[x] += x;
    }
    dp[1] = sum[1];
    for(int i=2;i<NICO;i++)
    {
        dp[i] = dp[i-1];
        if(dp[i-2]+sum[i] > dp[i]) dp[i] = dp[i-2]+sum[i];
    }
    cout << dp[NICO-1] << endl;
}