#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const int MAXM = 60;

int N, M;

int B;
vector <ll> basis;
int nc[MAXM];
ll ans[MAXM];

void gogo()
{
    ll cv = 0;
    for (int i = 1; i < (1 << B); i++)
    {
        nc[__builtin_popcountll(cv)]++;
        cv ^= basis[__builtin_ctz(i)];
    }
    nc[__builtin_popcountll(cv)]++;
}

int getp (ll x)
{
    return 63 - __builtin_clzll(x);
}

ll pascal[MAXM][MAXM];

int main()
{
    ios_base::sync_with_stdio(0);
    pascal[0][0] = 1;
    for (int i = 1; i < MAXM; i++)
        for (int j = 0; j < MAXM; j++)
        {
            pascal[i][j] = pascal[i-1][j];
            if (j) pascal[i][j] = (pascal[i][j] + pascal[i-1][j-1]) % MOD;
        }

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        ll x; cin >> x;

        for (ll b : basis)
            if ((x ^ b) < x)
                x ^= b;
        if (x > 0)
        {
            for (ll &b : basis)
                if ((b ^ x) < b)
                    b ^= x;
            basis.push_back(x);
            sort (basis.begin(), basis.end());
            reverse (basis.begin(), basis.end());
        }
    }

    B = basis.size();
    if (B * 2 <= M)
    {
        gogo();
        ll cmult = 1;
        for (int i = 0; i < N - basis.size(); i++)
            cmult = (cmult * 2) % MOD;
        for (int i = 0; i <= M; i++)
        {
            if (i) cout << " ";
            cout << (nc[i] * cmult) % MOD;
        }
        cout << "\n";
        return 0;
    }

    vector <ll> nbasis;
    for (int i = 0; i < M; i++)
    {
        bool bfound = false;
        for (ll b : basis)
            if (getp (b) == i)
                bfound = true;
        if (bfound) continue;

        ll nb = (1LL << i);
        for (ll b : basis)
            if (b & (1LL << i))
                nb ^= (1LL << getp (b));
        nbasis.push_back(nb);
    }
    basis = nbasis;
    B = basis.size();

    gogo();

    for (int i = 0; i <= M; i++)
    {
        ans[i] = 0;
        for (int j = 0; j <= M; j++)
        {
            for (int k = 0; k <= i; k++)
            {
                if (k > j || i - k > M - j)
                    continue;
                // jCk * (M-j)C(i-k)
                int mult = 1;
                if (k % 2 == 1) mult = -1;
                ans[i] += ((nc[j] * pascal[j][k]) % MOD) * pascal[M-j][i-k] * mult;
                ans[i] = (ans[i] % MOD + MOD) % MOD;
            }
        }
    }

    // # ways / 2^B * 2^(N-(M-B))
    ll cmult = 1;
    for (int i = 0; i < N - M; i++)
        cmult = (cmult * 2) % MOD;
    for (int i = 0; i < M - N; i++)
        cmult = (cmult * (MOD + 1) / 2) % MOD;
    for (int i = 0; i <= M; i++)
    {
        if (i) cout << " ";
        cout << (ans[i] * cmult) % MOD;
    }
    cout << "\n";
}