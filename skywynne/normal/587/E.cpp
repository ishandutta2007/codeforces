// For what I've done , I'll start anew ...
#include<bits/stdc++.h>
#define pb push_back
#define lc (id << 1)
#define rc (lc ^ 1)
#define md (l + r >> 1)
using namespace std;
const int N = 200005;
int n, q, A[N], D[N], Lz[N];
vector < int > base, B[N * 2];
inline void Xor(int i, int val)
{
    for (i ++; i < N; i += i & -i)
        Lz[i] ^= val;
}
inline int GetAt(int i)
{
    int ret = 0;
    for (i ++; i; i -= i & -i)
        ret ^= Lz[i];
    return ret;
}
inline void Merge(vector < int > &F, vector < int > &G, vector < int > &H)
{
    F = G;
    for (int a : H)
    {
        for (int &b : F)
            a = min(a, a ^ b);
        if (a) F.pb(a);
    }
}
inline void Set(int i, int val)
{
    B[i += n] = {};
    if (val)
        B[i] = {val};
    for (; i; i >>= 1)
        Merge(B[i >> 1], B[i], B[i ^ 1]);
}
inline void Solve(int l, int r)
{
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1) Merge(base, base, B[l]), l ++;
        if (r & 1) r --, Merge(base, base, B[r]);
    }
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
        Xor(i, A[i]);
        Xor(i + 1, A[i]);
    }
    for (int i = 1; i < n; i++)
        D[i] = A[i] ^ A[i - 1], Set(i, D[i]);
    for (; q; q --)
    {
        int t, l, r, k;
        scanf("%d%d%d", &t, &l, &r); l --;
        if (t == 1)
        {
            scanf("%d", &k);
            if (!k) continue;
            Xor(l, k); Xor(r, k);
            if (l > 0)
                D[l] ^= k, Set(l, D[l]);
            if (r < n)
                D[r] ^= k, Set(r, D[r]);
            continue;
        }
        Solve(l + 1, r);
        vector < int > temp = {GetAt(l)};
        if (temp[0]) Merge(base, base, temp);
        printf("%d\n", 1 << (int)base.size());
        base.clear();
    }
    return 0;
}