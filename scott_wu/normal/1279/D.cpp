#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const int MAXN = 1000100;

ll mpow (ll b, int e)
{
    if (e == 0) return 1;
    ll v = mpow (b, e / 2);
    v = (v * v) % MOD;
    if (e & 1)
        v = (v * b) % MOD;
    return v;
}

ll inv (ll b)
{
    return mpow (b % MOD, MOD - 2);
}

int N;
vector <int> v[MAXN];
int ct[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int K; cin >> K;
        for (int j = 0; j < K; j++)
        {
            int x; cin >> x;
            v[i].push_back(x);
            ct[x]++;
        }
    }

    ll res = 0;
    for (int i = 0; i < N; i++)
    {
        for (int cv : v[i])
        {
            ll prob = (inv (v[i].size() * (ll)N)) % MOD;
            prob = (prob * ct[cv]) % MOD;
            prob = (prob * inv (N)) % MOD;
            res = (res + prob) % MOD;
        }
    }
    cout << res << "\n";
}