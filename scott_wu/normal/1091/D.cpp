#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const ll P = 998244353;
const ll MOD = P;
const int MAXN = 1000100;

int N;
ll inv[MAXN];
ll ifac[MAXN];
ll fac[MAXN];

ll cpow (ll x, ll b)
{
    if (b == 0) return 1;
    if (b == 1) return x % P;
    ll res = cpow (x, b / 2);
    res = (res * res) % P;
    if (b % 2)
        res = (res * x) % MOD;
    return res;
}

ll get_inv (ll x)
{
    return cpow (x, P - 2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;
    ifac[0] = fac[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        inv[i] = get_inv (i);
        ifac[i] = (ifac[i-1] * inv[i]) % MOD;
        fac[i] = (fac[i-1] * i) % MOD;
    }

    ll ctake = 0;
    for (int i = 1; i <= N - 1; i++)
    {
        ctake = (ctake + fac[N] * ifac[i]) % MOD;
    }

    ll ctot = (N * fac[N]) % MOD;
    ctot = (ctot - ctake) % MOD;
    ctot = (ctot + MOD) % MOD;
    cout << ctot << "\n";
}