#include<bits/stdc++.h>
#define lc (id << 1)
#define rc (id << 1 ^ 1)
#define md ((l + r) >> 1)
using namespace std;
const int N = 1e5 + 10, LG = 18;
namespace SuffixArray
{
    int n, pw, Rank[LG][N], P[N], T[N], Lcp[N];
    char * S;
    inline bool CMP(int i, int j)
    {
        if (Rank[pw - 1][i] != Rank[pw - 1][j])
            return (Rank[pw - 1][i] < Rank[pw - 1][j]);
        i += (1 << pw - 1); j += (1 << pw - 1);
        if (i < n && j < n)
            return (Rank[pw - 1][i] < Rank[pw - 1][j]);
        return (i > j);
    }
    inline int GetLcp(int l, int r, int le, int ri)
    {
        int lcp = 0;
        for (int i = LG - 1; ~i; i--)
            if ((1 << i) <= min(r - l, ri - le))
                if (Rank[i][l] == Rank[i][le])
                    l += (1 << i), le += (1 << i), lcp += (1 << i);
        return (lcp);
    }
    inline void Build(char * _S)
    {
        S = _S;
        n = strlen(S);
        memset(T, 0, sizeof(T));
        for (int i = 0; i < n; i++)
            P[i] = i, Rank[0][i] = S[i];
        for (pw = 1; pw < LG; pw ++)
        {
            sort(P, P + n, CMP);
            for (int i = 1; i < n; i++)
                T[i] = T[i - 1] + CMP(P[i - 1], P[i]);
            for (int i = 0; i < n; i++)
                Rank[pw][P[i]] = T[i];
        }
        for (int i = 0; i < n - 1; i++)
            Lcp[i] = GetLcp(P[i], n, P[i + 1], n);
    }
}
using namespace SuffixArray;
int q, Lz[N * 4];
long long Sm[N * 4];
char A[N];
inline void Shift(int id, int l, int r)
{
    if (Lz[id] < -1) return ;
    Lz[lc] = Lz[rc] = Lz[id]; Lz[id] = -2;
    Sm[lc] = 1ll * Lz[lc] * (md - l);
    Sm[rc] = 1ll * Lz[rc] * (r - md);
}
void Set(int le, int ri, int val, int id = 1, int l = 0, int r = N)
{
    if (ri <= l || r <= le)
        return ;
    if (le <= l && r <= ri)
    {
        Sm[id] = 1ll * val * (r - l);
        Lz[id] = val; return ;
    }
    Shift(id, l, r);
    Set(le, ri, val, lc, l, md);
    Set(le, ri, val, rc, md, r);
    Sm[id] = Sm[lc] + Sm[rc];
}
long long Get(int le, int ri, int id = 1, int l = 0, int r = N)
{
    if (ri <= l || r <= le)
        return (0);
    if (le <= l && r <= ri)
        return (Sm[id]);
    Shift(id, l, r);
    return (Get(le, ri, lc, l, md) + Get(le, ri, rc, md, r));
}
int main()
{
    scanf("%d", &q);
    for (; q; q --)
    {
        long long tot = 0;
        scanf("%s", &A);
        Build(A);
        memset(A, 0, sizeof(A));
        memset(Sm, 0, sizeof(Sm));
        memset(Lz, -63, sizeof(Lz));
        Set(0, N, -1);
        for (int i = 0; i < n; i++)
        {
            tot += (1ll * (n - P[i]) * i - Get(0, n - P[i])) * 2 - (n - P[i]);
            if (i < n - 1) Set(Lcp[i], n, i);
        }
        printf("%lld\n", tot);
    }
    return (0);
}