#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const int MAXN = 2000100;

ll cpow (ll b, int e)
{
    if (e == 0) return 1;
    if (e == 1) return b;
    ll v = cpow (b, e / 2);
    v = (v * v) % MOD;
    if (e & 1) v = (v * b) % MOD;
    return v;
}

ll minv (ll x)
{
    return cpow (x, MOD - 2);
}

int N, M;
ll ans[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> M;

    ans[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        ans[i] = ans[i-1] + (M + i) * minv(i) - 1;
        ans[i] = (ans[i] % MOD + MOD) % MOD;
    }
    ll res = ans[N];
    res = (res * (N + M + 1)) % MOD;
    res = (res * minv (M + 1)) % MOD;
    res = (res % MOD + MOD) % MOD;
    cout << res << "\n";
}