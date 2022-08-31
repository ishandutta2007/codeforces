#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 510;
const ll MOD = 998244353;

int N;
ll op[MAXN];

bool pre (int x, int c)
{
    if (op[x] < op[c]) return true;
    if (op[x] == op[c] && x < c) return true;
    return false;
}

ll dp[MAXN];

int gogo (int c)
{
    for (int i = 0; i < MAXN; i++)
        dp[i] = 0;
    dp[0] = 1;

    for (int i = 0; i < N; i++)
    {
        if (i == c) continue;
        else if (op[i] == -1)
        {
            if (i < c)
            {
                dp[0] = (2 * dp[0]) % MOD;
            }
            for (int j = 0; j < N; j++)
            {
                dp[j] = (dp[j] + dp[j+1]) % MOD;
            }
        }
        else if (pre (i, c))
        {
            for (int j = N; j >= 1; j--)
            {
                dp[j] = (dp[j] + dp[j-1]) % MOD;
            }
        }
        else
        {
            for (int j = 0; j <= N; j++)
                dp[j] = (2 * dp[j]) % MOD;
        }
    }

    ll res = 0;
    for (int i = 0; i <= N; i++)
        res += dp[i];
    return res % MOD;
}

void gogo()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        char c; cin >> c;
        if (c == '-') op[i] = -1;
        else
        {
            cin >> op[i];
        }
    }

    ll res = 0;
    for (int i = 0; i < N; i++)
        if (op[i] >= 0)
        {
            //cout << i << " " << op[i] << " " << gogo (i) << "\n";
            res = (res + gogo (i) * op[i]) % MOD;
        }
    cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T = 1;
    for (int t = 0; t < T; t++)
        gogo();
}