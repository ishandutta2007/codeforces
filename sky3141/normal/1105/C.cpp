#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;

typedef long long LL;

const int MAXN = 200000 + 9, mod = 1000000007;

int n;
int lb, rb;
LL dp[MAXN][3];
int cnt[3];

int main()
{
    cin >> n >> lb >> rb;
    for(int i=0; i<3; ++i)
    {
        cnt[i] = (rb - i + 9) / 3 - (lb - 1 - i + 9) / 3;
    }
    dp[0][0] = 1;
    for(int i=1; i<=n; ++i)
    {
        for(int j=0; j<3; ++j)
        {
            for(int k=0; k<3; ++k)
            {
                dp[i][j] += dp[i - 1][(j - k + 3) % 3] * cnt[k];
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[n][0] << std::endl;

    return 0;
}