#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 5005, Mod = 1e9 + 7;
int n, cp, X[N], Y[N], P[N];
bool D[N];
vector < pair < int , int > > A[N * 2];
int Find(int v)
{
    if (P[v] < 0) return (v);
    int p = P[v]; P[v] = Find(P[v]);
    D[v] ^= D[p]; return (P[v]);
}
inline int Power(int a, int b)
{
    int ret = 1;
    for (; b; b >>= 1, a = 1ll * a * a % Mod)
        if (b & 1) ret = 1ll * ret * a % Mod;
    return (ret);
}
int main()
{
    scanf("%d", &n); cp = n;
    memset(P, -1, sizeof(P));
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &X[i], &Y[i]);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            A[abs(X[i] - X[j]) + abs(Y[i] - Y[j])].pb({i, j});
    for (int i = N * 2 - 1; ~i; i--)
    {
        int cpy = cp;
        for (auto st : A[i])
        {
            int v = st.first, u = st.second, pv = Find(v), pu = Find(u);
            if (pv != pu)
            {
                D[pv] = D[v] ^ D[u] ^ 1;
                P[pv] = pu; cp --;
                continue;
            }
            if (D[v] == D[u])
                return !printf("%d\n%d", i, Power(2, cpy));
        }
    }
    return !printf("0\n%d", Power(2, cp));
}