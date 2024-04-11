// In The Name Of The Queen
#include<bits/stdc++.h>
#define lc (id << 1)
#define rc (lc ^ 1)
#define md (l + r >> 1)
#define int long long
using namespace std;
const int N = 1e6 + 74;
int q, n, A[N], P[N], MN[N * 4], LZ[N * 4];
inline void Shift(int id)
{
    MN[lc] += LZ[id];
    MN[rc] += LZ[id];
    LZ[lc] += LZ[id];
    LZ[rc] += LZ[id];
    LZ[id] = 0;
}
void Set(int i, int val, int id = 1, int l = 0, int r = n)
{
    if (r - l < 2)
    {
        LZ[id] = 0;
        MN[id] = val;
        return ;
    }
    Shift(id);
    if (i < md)
        Set(i, val, lc, l, md);
    else
        Set(i, val, rc, md, r);
    MN[id] = min(MN[lc], MN[rc]);
}
void Add(int le, int ri, int val, int id = 1, int l = 0, int r = n)
{
    if (ri <= l || r <= le)
        return ;
    if (le <= l && r <= ri)
    {
        LZ[id] += val;
        MN[id] += val;
        return ;
    }
    Shift(id);
    Add(le, ri, val, lc, l, md);
    Add(le, ri, val, rc, md, r);
    MN[id] = min(MN[lc], MN[rc]);
}
int Get(int id = 1, int l = 0, int r = n)
{
    assert(MN[id] == 0);
    if (r - l < 2)
        return (l);
    Shift(id);
    if (MN[rc] == 0)
        return (Get(rc, md, r));
    return (Get(lc, l, md));
}
int32_t main()
{
    scanf("%lld", &n);
    for (int i = 0; i < n; i ++)
        scanf("%lld", &A[i]), Set(i, A[i]);
    for (int i = 0; i < n; i ++)
    {
        int j = Get();
        P[j] = i + 1;
        Add(j + 1, n, -(i + 1));
        Set(j, (long long)(1e16));
    }
    for (int i = 0; i < n; i ++)
        printf("%lld ", P[i]);
    return 0;
}