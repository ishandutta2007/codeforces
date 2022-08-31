#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 9;

int N, A, B, K;
int nval[200100];

ll cpow (ll x, ll p)
{
    if (p == 0)
        return 1;
    if (p == 1)
        return x;

    ll c = cpow (x, p / 2);
    c = (c * c) % MOD;
    if (p % 2 == 1)
        c = (c * x) % MOD;
    return c;
}

ll inv (ll x)
{
    return cpow (x, MOD - 2);
}

ll gv (int x)
{
    ll v = (cpow (A, N - 1 - x) * cpow (B, x)) % MOD;
    v = (v * nval[x]) % MOD;
    v = (v + MOD) % MOD;
    return v;
}

int main()
{
    cin >> N >> A >> B >> K;
    N++;

    for (int i = 0; i < K; i++)
    {
        char c;
        cin >> c;
        if (c == '+')
            nval[i] = 1;
        else
            nval[i] = MOD - 1;
        nval[i+K] = nval[i];
    }

    int nman = N % K;
    ll res = 0;
    for (int i = 0; i < nman; i++)
    {
        res += gv(i);
    }
    res %= MOD;

    if (N < K)
    {
        cout << res << "\n";
        return 0;
    }

    ll nv = 0;
    for (int i = nman; i < nman + K; i++)
        nv += gv(i);
    nv %= MOD;

    ll cmult = cpow (B, K) * inv (cpow (A, K));
    cmult = (cmult % MOD);

    if (cmult == 1)
    {
        res = (res + (N / K) * nv) % MOD;
        cout << res << "\n";
        return 0;
    }

    int nround = N / K;
    ll ctot = ((cpow (cmult, nround) + MOD - 1) * inv (cmult + MOD - 1)) % MOD;
    res = (res + ctot * nv) % MOD;
    cout << res << "\n";

    return 0;
}