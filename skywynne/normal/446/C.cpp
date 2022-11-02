// I'm back ...
#include<bits/stdc++.h>
#define lc (id * 2)
#define rc (id * 2 + 1)
#define md ((l + r) >> 1)
using namespace std;
const int N = 3e5 + 3, Mod = 1e9 + 9;
int n, q, F[N], P[N], L[N * 4][2], S[N * 4];
inline int Getfib(int a, int b, int i)
{
    return ((1ll * F[i] * a + 1ll * F[i -1] * (b - a + Mod)) % Mod);
}
inline void Update(int id, int l, int r, int le, int a = 1, int b = 1)
{
    L[id][0] = (L[id][0] + Getfib(a, b, l - le)) % Mod;
    L[id][1] = (L[id][1] + Getfib(a, b, l - le + 1)) % Mod;
    S[id] = (1ll * S[id] + Getfib(a, b, r - le + 1) - Getfib(a, b, l - le + 1) + Mod) % Mod;
}
inline void Shift(int id, int l, int r)
{
    Update(lc, l, md, l, L[id][0], L[id][1]);
    Update(rc, md, r, l, L[id][0], L[id][1]);
    L[id][0] = L[id][1] = 0;
}
void Add(int le, int ri, int id = 1, int l = 0, int r = n)
{
    if (ri <= l || r <= le)
        return ;
    if (le <= l && r <= ri)
    {
        Update(id, l, r, le);
        return ;
    }
    Shift(id, l, r);
    Add(le, ri, lc, l, md);
    Add(le, ri, rc, md, r);
    S[id] = (S[lc] + S[rc]) % Mod;
}
int Get(int le, int ri, int id = 1, int l = 0, int r = n)
{
    if (ri <= l || r <= le)
        return (0);
    if (le <= l && r <= ri)
        return (S[id]);
    Shift(id, l, r);
    return ((Get(le, ri, lc, l, md) + Get(le, ri, rc, md, r)) % Mod);
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &P[i]), P[i] = (P[i] + P[i -1]) % Mod;
    F[0] = F[1] = 1;
    for (int i = 2; i < N; i++)
        F[i] = (F[i -1] + F[i - 2]) % Mod;
    for (int l, r, tp; q; q --)
    {
        scanf("%d%d%d", &tp, &l, &r);
        if (tp == 1)
            Add(l - 1, r);
        else
            printf("%lld\n", (1ll * Get(l - 1, r) + P[r] - P[l - 1] + Mod) % Mod);
    }
    return (0);
}