#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 510;
const int MAXD = MAXN * MAXN / 2;

int N, M;
ll MOD;
ll nd[MAXD];
ll ps[MAXD];

void gogo()
{
    cin >> N >> M;
    MOD = M;

    for (int i = 0; i < MAXD; i++)
        nd[i] = 0;
    nd[0] = 1;

    //cout << "YO" << endl;
    ll res = 0;
    for (int i = 1; i < N; i++)
    {
        if (i == 1)
        {
            ps[0] = 0;
            for (int j = 0; j + 1 < MAXD; j++)
            {
                ps[j+1] = (ps[j] + nd[j]) % MOD;
            }
        }

        for (int j = 0; j < MAXD - 1; j++)
        {
            nd[j] = ps[j+1];
            if (j >= i)
                nd[j] = (nd[j] + MOD - ps[j-i+1]) % MOD;
        }

        ps[0] = 0;
        for (int j = 0; j + 1 < MAXD; j++)
        {
            ps[j+1] = (ps[j] + nd[j]) % MOD;
        }

        ll np = 0;
        for (int k = 0; k < MAXD; k++)
        {
            if (!nd[k]) continue;
            if (k > i)
                np = (np + ((ps[k-i] * i * (i + 1) / 2) % MOD) * nd[k]) % MOD;
            for (int j = max (0, k - i); j < k; j++)
            {
                ll nt = (i - (k - j)) + 1;
                ll pp = (i * (i + 1) / 2) - (nt * (nt + 1)) / 2;
                np = (np + pp * nd[j] % MOD * nd[k]) % MOD;
            }
        }
        np %= MOD;
        for (int j = i + 2; j <= N; j++)
            np = (np * j) % MOD;
        res = (res + np) % MOD;
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