#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 300005, B = 18931, Mod = 1e9 + 7;
int n, _n, hsh, tot, len, H[N], P[N], At[N];
char S[N], T[N];
vector < int > Adj[N];
void DFS(int v, int h = 0)
{
    At[h] = v;
    for (int &u : Adj[v])
        H[u] = (1ll * H[v] * B + S[u]) % Mod, DFS(u, h + 1);
    if (h >= len && hsh == (H[v] - H[At[h - len]] * 1ll * P[len] % Mod + Mod) % Mod)
        tot ++;
}
int main()
{
    scanf("%d", &n); _n = n;
    for (int i = 2, p; i <= n; i++)
    {
        scanf("%d%s", &p, &T);
        len = strlen(T);
        for (int j = 0; j < len - 1; j++)
            Adj[p].pb(++ _n), p = _n, S[_n] = T[j];
        Adj[p].pb(i); S[i] = T[len - 1];
        fill(T, T + len, 0);
    }
    scanf("%s", &T);
    for (int i = P[0] = 1; i < N; i++)
        P[i] = 1ll * P[i - 1] * B % Mod;
    len = strlen(T);
    for (int i = 0; i < len; i++)
        hsh = (1ll * hsh * B + T[i]) % Mod;
    DFS(1);
    return !printf("%d", tot);
}