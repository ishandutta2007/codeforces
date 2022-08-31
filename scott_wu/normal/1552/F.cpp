#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 200100;
const ll MOD = 998244353;

int N;
ll X[MAXN], Y[MAXN];
int S[MAXN];
ll v[MAXN];
ll ps[MAXN];

void gogo()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> X[i] >> Y[i] >> S[i];

    for (int i = 0; i < MAXN; i++)
        ps[i] = 0;

    for (int i = 0; i < N; i++)
    {
        int nc = (lower_bound (X, X + N, Y[i]) - X);
        ll t = ps[i] - ps[nc];
        v[i] = ((t + X[i] - Y[i]) % MOD + MOD) % MOD;
        ps[i+1] = (ps[i] + v[i]) % MOD;
    }

    ll res = (X[N-1] + 1) % MOD;
    for (int i = 0; i < N; i++)
    {
        if (S[i]) res = (res + v[i]) % MOD;
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