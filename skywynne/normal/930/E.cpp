#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e6 + 10, Mod = 1e9 + 7;
int n, M[2], k, L[N][2], R[N][2];
vector < int > U, B[N][2];
struct SEG
{
    int S[N * 4];
    bool L[N * 4];
    SEG()
    {
        memset(S, 0, sizeof(S));
        memset(L, 0, sizeof(L));
    }
    inline void Shift(int id, int lc, int rc)
    {
        if (!L[id]) return ;
        L[lc] = L[rc] = 1;;
        S[lc] = S[rc] = L[id] = 0;
    }
    void Set(int i, int val, int id = 1, int l = 0, int r = n)
    {
        if (r - l < 2){S[id] = val; return ;}
        int lc = id * 2, rc = lc + 1, md = (l + r) >> 1;
        Shift(id, lc, rc);
        if (i < md) Set(i, val, lc, l, md);
        else Set(i, val, rc, md, r);
        S[id] = (S[lc] + S[rc]) % Mod;
    }
    void Setzero(int le, int ri, int id = 1, int l = 0, int r = n)
    {
        if (ri <= l || r <= le)
            return ;
        if (le <= l && r <= ri){L[id] = 1; S[id] = 0; return ;}
        int lc = id * 2, rc = lc + 1, md = (l + r) >> 1;
        Shift(id, lc, rc);
        Setzero(le, ri, lc, l, md);
        Setzero(le, ri, rc, md, r);
        S[id] = (S[lc] + S[rc]) % Mod;
    }
    int Get(int le, int ri, int id = 1, int l = 0, int r = n)
    {
        if (ri <= l || r <= le)
            return (0);
        if (le <= l && r <= ri)
            return (S[id]);
        int lc = id * 2, rc = id * 2 + 1, md = (l + r) >> 1;
        Shift(id, lc, rc);
        return ((Get(le, ri, lc, l, md) + Get(le, ri, rc, md, r)) % Mod);
    }
};
inline int Power(int a, int b)
{
    int ret = 1;
    for (; b; b >>= 1, a = 1ll * a * a % Mod)
        if (b & 1) ret = 1ll * ret * a % Mod;
    return (ret);
}
inline Getid(int val)
{
    return ((int)(lower_bound(U.begin(), U.end(), val) - U.begin()));
}
int main()
{
    scanf("%d%d%d", &k, &M[0], &M[1]);
    for (int w = 0; w <= 1; w ++)
        for (int i = 0; i < M[w]; i++)
            scanf("%d%d", &L[i][w], &R[i][w]), U.pb(L[i][w]), U.pb(R[i][w]), U.pb(L[i][w] - 1);
    U.pb(0); U.pb(k); sort(U.begin(), U.end()); U.resize(unique(U.begin(), U.end()) - U.begin());
    for (int w = 0; w <= 1; w ++)
        for (int i = 0; i < M[w]; i++)
            L[i][w] = Getid(L[i][w]), R[i][w] = Getid(R[i][w]), B[R[i][w]][w].pb(L[i][w]);
    n = (int)U.size();
    SEG A[2];
    for (int w = 0; w <= 1; w ++)
    {
        A[w].Set(0, 1);
        A[w].Set(1, Power(2, U[1] - 1) - 1);
        for (int &l : B[1][w])
        {
            if (l != 1) A[w].Setzero(0, l);
            else A[w].Setzero(0, n);
        }
    }
    for (int i = 2; i < n; i++)
    {
        int sum[2] = {A[0].Get(0, n), A[1].Get(0, n)};
        int tmp[2] = {A[0].Get(i - 1, i), A[1].Get(i - 1, i)};
        for (int w = 0; w <= 1; w ++)
            A[w].Set(i - 1, (sum[!w] + tmp[w]) % Mod), A[w].Set(i, 1ll * (Power(2, U[i] - U[i - 1] - 1) - 1) * (sum[0] + sum[1]) % Mod);
        for (int w = 0; w <= 1; w ++)
            for (int &l : B[i][w])
            {
                if (i != l) A[w].Setzero(0, l);
                else A[w].Setzero(0, n);
            }
    }
    return !printf("%d\n", (A[0].Get(0, n) + A[1].Get(0, n)) % Mod);
}