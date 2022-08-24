#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 510;
const int MAXD = MAXN * MAXN / 2;

int N, M;
ll MOD;
ll nd[MAXD+2];
ll ps[MAXD+2];
ll pps[MAXD+2];

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
        //int MAXD = (i * (i + 3)) / 2;
        if (i == 1)
        {
            ps[0] = 0;
            for (int j = 0; j <= MAXD; j++)
            {
                ps[j+1] = (ps[j] + nd[j]) % MOD;
            }
        }

        for (int j = 0; j <= MAXD; j++)
        {
            nd[j] = ps[j+1];
            if (j >= i)
                nd[j] = (nd[j] + MOD - ps[j-i+1]) % MOD;
        }

        ps[0] = pps[0] = 0;
        for (int j = 0; j <= MAXD; j++)
        {
            ps[j+1] = (ps[j] + nd[j]) % MOD;
            pps[j+1] = (pps[j] + ps[j+1]) % MOD;
        }

        ll np = 0;
        ll off = 0;
        for (int k = 1; k <= ((i + 2) * (i + 3)) / 2; k++)
        {
            np = (np + ((ps[k] * i * (i + 1) / 2) % MOD) * nd[k]) % MOD;

            
            ll v = 0;
            if (k >= 2) v = pps[k-2];
            if (k > i + 1)
            {
                v -= pps[k-i-2];
            }
            v = ps[k-1] * i - v;
            v = (v % MOD + MOD) % MOD;
            v = v - (i * (i + 1) / 2) * nd[k-1];
            v = (v % MOD + MOD) % MOD;

            off = (off + v) % MOD;
            np = (np + off * nd[k]) % MOD;

            /*ll off2 = 0;
            for (int j = max (0, k - i); j < k; j++)
            {
                ll nt = (i - (k - j)) + 1;
                ll pp = -(nt * (nt + 1)) / 2;
                off2 = (off2 + pp * nd[j]) % MOD;
                //np = (np + pp * nd[j] % MOD * nd[k]) % MOD;
            }
            off2 = (off2 % MOD + MOD) % MOD;*/
            //cout << i << " " << k << " " << off << " " << off2 << "\n";
        }
        np %= MOD;
        for (int j = i + 2; j <= N; j++)
            np = (np * j) % MOD;
        res = (res + np) % MOD;
    }
    res = (res % MOD + MOD) % MOD;
    cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T = 1;
    for (int t = 0; t < T; t++)
        gogo();
}