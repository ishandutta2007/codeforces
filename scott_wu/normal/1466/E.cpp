#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXB = 62;
const ll MOD = 1e9 + 7;

int N;
int ntot[MAXB];
int nco[MAXB][MAXB];

void gogo()
{
    cin >> N;
    for (int i = 0; i < MAXB; i++)
    {
        ntot[i] = 0;
        for (int j = 0; j < MAXB; j++)
            nco[i][j] = 0;
    }

    for (int i = 0; i < N; i++)
    {
        ll v; cin >> v;

        for (int j = 0; j <= 60; j++)
            if (v & (1LL << j))
            {
                ntot[j]++;
                for (int k = 0; k <= j; k++)
                {
                    nco[j][k] += (v >> k) & 1;
                }
            }
    }
    for (int i = 0; i < MAXB; i++)
        for (int j = i + 1; j < MAXB; j++)
            nco[i][j] = nco[j][i];

    ll ans = 0;
    for (int i = 0; i < MAXB; i++)
        for (int j = 0; j < MAXB; j++)
        {
            ll vc = ntot[i];
            ll vy = nco[i][j];
            ll vn = ntot[i] - nco[i][j];

            ll r1 = vc * vy * N;
            ll r2 = vc * vn * ntot[j];

            ll r = (r1 + r2) % MOD;
            ll p1 = (1LL << i) % MOD;
            ll p2 = (1LL << j) % MOD;
            r = (r * p1) % MOD;
            r = (r * p2) % MOD;
            ans = (ans + r) % MOD;
        }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}