#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 5100;
const ll MOD = 998244353;

int N;
ll ccnt[MAXN][MAXN]; // # of i at j
ll cfac[MAXN];
ll ifac[MAXN];

ll cpow (ll b, int e)
{
    if (e == 0) return 1;
    if (e == 1) return (b % MOD);
    ll vv = cpow (b, e / 2);
    vv = (vv * vv) % MOD;
    if (e & 1)
        vv = (vv * b) % MOD;
    return vv;
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    ccnt[1][1] = 1;

    cfac[0] = 1;
    for (int i = 1; i < MAXN; i++)
        cfac[i] = (i * cfac[i-1]) % MOD;
    ifac[MAXN-1] = cpow (cfac[MAXN-1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; i--)
        ifac[i] = (ifac[i+1] * (i + 1)) % MOD;

    for (int j = 1; j < N; j++)
    {
        for (int i = 1; i <= j; i++)
        {
            ccnt[i][j+1] += i * ccnt[i][j];
            ccnt[i][j+1] %= MOD;
            ccnt[i+1][j+1] += (j - i + 1) * ccnt[i][j];
            ccnt[i+1][j+1] %= MOD;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        ll res = 0;
        for (int j = 1; j <= N; j++)
        {
            ll gg = cfac[N] * ifac[j];
            res = (res + ccnt[i][j] * (gg % MOD)) % MOD;
        }

        if (i > 1) cout << " ";
        cout << res % MOD;
    }
    cout << "\n";
}