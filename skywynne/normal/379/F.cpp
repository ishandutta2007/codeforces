#include<bits/stdc++.h>
using namespace std;
const int N = 500005 * 2, LG = 21;
int n, q, H[N], P[N][LG];
inline int LCA(int v, int u)
{
    if (H[v] < H[u])
        return (LCA(u, v));
    for (int i = 0; i < LG; i++)
        if ((H[v] - H[u]) & (1 << i))
            v = P[v][i];
    if (v == u)
        return (v);
    for (int i = LG - 1; ~i; i--)
        if (P[v][i] != P[u][i])
            v = P[v][i], u = P[u][i];
    return (P[v][0]);
}
inline int Dist(int v, int u)
{
    return (H[v] + H[u] - H[LCA(v, u)] * 2);
}
int main()
{
    scanf("%d", &q);
    H[2] = H[3] = H[4] = 1; n = 4;
    P[2][0] = P[3][0] = P[4][0] = 1;
    int dv = 2, du = 3, d = 2;
    for (; q; q --)
    {
        int p, v, u;
        scanf("%d", &p);
        v = ++ n; u = ++ n;
        H[v] = H[u] = H[p] + 1;
        P[v][0] = P[u][0] = p;
        for (int i = 1; i < LG; i++)
            P[v][i] = P[P[v][i - 1]][i - 1],
            P[u][i] = P[P[u][i - 1]][i - 1];

        int v_dv = Dist(v, dv);
        int v_du = Dist(v, du);

        if (v_dv > d)
            du = v, d = v_dv;
        else if (v_du > d)
            dv = v, d = v_du;
        printf("%d\n", d);
    }
    return (0);
}