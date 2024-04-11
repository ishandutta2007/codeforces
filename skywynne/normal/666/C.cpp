#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 1e5 + 10, SQ = 500, Mod = 1e9 + 7;
int n, m, q, r, t, a, b, c, d, A[N], F[N], P5[N], I[N], sz[N], ln[N], dp[SQ][N];
char S[N];
bitset < N > M;
vector < int > V;
map < int , int > MA;
int Power(int a, int b)
{
    int ret = 1;
    for (; b; b >>= 1, a = 1ll * a * a % Mod)
        if (b & 1)
            ret = 1ll * ret * a % Mod;
    return (ret);
}
int C(int a, int b)
{
    if (b < 0 || a < 0 || b > a)
        return (0);
    return (1ll * F[a] * I[b] % Mod * I[a - b] % Mod);
}
int main()
{
    scanf("%d", &q);
    scanf("%s", &S);
    sz[0] = strlen(S);
    for (int i = 1; i <= q; i++)
    {
        scanf("%d", &t);
        if (t == 2)
            scanf("%d", &ln[i]);
        else
            scanf("%s", &S), sz[i] = strlen(S);
    }
    for (int i = 0; i <= q; i++)
        M[sz[i]] = 1, V.pb(sz[i]);
    V.pb(0);
    sort(V.begin(), V.end());
    V.resize(unique(V.begin(), V.end()) - V.begin());
    for (int i = 1; i < V.size(); i++)
        MA[V[i]] = i;
    for (int i = 0; i <= q; i++)
    {
        if (sz[i])
            sz[i] = MA[sz[i]];
        else
            sz[i] = sz[i - 1];
    }
    for (int i = F[0] = P5[0] = 1; i < N; i++)
        F[i] = 1ll * F[i - 1] * i % Mod, P5[i] = 1ll * P5[i - 1] * 25 % Mod;
    I[N - 1] = Power(F[N - 1], Mod - 2);
    for (int i = N - 2; ~i; i--)
        I[i] = 1ll * I[i + 1] * (i + 1) % Mod;
    for (int i = 1; i < N; i++)
    {
        if (!M[i])
            continue;
        int w = MA[i];
        for (int j = i; j < N; j++)
            dp[w][j] = (1ll * dp[w][j - 1] * 26 + C(j - 1, i - 1) * 1ll * P5[j - i]) % Mod;
    }
    for (int i = 1; i <= q; i++)
    {
        if (!ln[i])
            continue;
        printf("%d\n", dp[sz[i]][ln[i]]);
    }
    return (0);
}