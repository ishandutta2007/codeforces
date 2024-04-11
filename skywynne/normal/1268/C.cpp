// In The Name Of The Queen
#include<bits/stdc++.h>
#define lc (id << 1)
#define rc (lc ^ 1)
#define mid (l + r >> 1)
using namespace std;
const int N = 3e5 + 10;
int n, A[N], F[N], FN[N], rev[N], CNT[2][N * 4], LZ[2][N * 4];
long long res[N], S[2][N * 4];
inline void AddFen(int i, int val)
{
    for (i ++; i < N; i += i & - i)
        FN[i] += val;
}
inline int GetFen(int i)
{
    int rt = 0;
    for (i ++; i; i -= i & - i)
        rt += FN[i];
    return (rt);
}
void Build(int w, int id = 1, int l = 1, int r = n + 1)
{
    CNT[w][id] = r - l;
    if (r - l > 1)
        Build(w, lc, l, mid), Build(w, rc, mid, r);
}
inline void Shift(int w, int id)
{
    S[w][lc] += 1LL * LZ[w][id] * CNT[w][lc];
    S[w][rc] += 1LL * LZ[w][id] * CNT[w][rc];
    LZ[w][lc] += LZ[w][id];
    LZ[w][rc] += LZ[w][id];
    LZ[w][id] = 0;
}
void Del(int i, int w, int id = 1, int l = 1, int r = n + 1)
{
    CNT[w][id] --;
    if (r - l < 2)
    {
        S[w][id] = 0;
        return ;
    }
    Shift(w, id);
    if (i < mid)
        Del(i, w, lc, l, mid);
    else
        Del(i, w, rc, mid, r);
    S[w][id] = S[w][lc] + S[w][rc];
}
void Add(int le, int ri, int val, int w, int id = 1, int l = 1, int r = n + 1)
{
    if (ri <= l || r <= le)
        return ;
    if (le <= l && r <= ri)
    {
        S[w][id] += 1LL * val * CNT[w][id];
        LZ[w][id] += val;
        return ;
    }
    Shift(w, id);
    Add(le, ri, val, w, lc, l, mid);
    Add(le, ri, val, w, rc, mid, r);
    S[w][id] = S[w][lc] + S[w][rc];
}
long long Get(int le, int ri, int w, int id = 1, int l = 1, int r = n + 1)
{
    if (ri <= l || r <= le)
        return 0;
    if (le <= l && r <= ri)
        return (S[w][id]);
    Shift(w, id);
    return (Get(le, ri, w, lc, l, mid) + Get(le, ri, w, rc, mid, r));
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> A[i], rev[A[i]] = i;
    for (int i = 1; i <= n; i ++)
        AddFen(rev[i], 1), res[i] = res[i - 1] + i - GetFen(rev[i]);
    Build(0);
    Build(1);
    int bordl = n + 1;;
    int bordr = 0;
    memset(FN, 0, sizeof(FN));
    for (int i = 1; i <= n; i ++)
    {
        AddFen(rev[i], 1);
        bordl = min(bordl, rev[i]);
        bordr = max(bordr, rev[i]);
        Del(rev[i], 0);
        Del(rev[i], 1);
        Add(1, rev[i], 1, 1);
        Add(rev[i] + 1, n + 1, 1, 0);
        int le = 0, ri = n + 1, md;
        while (ri - le > 1)
        {
            md = (le + ri) >> 1;
            if (GetFen(md) >= (i + 1) / 2)
                ri = md;
            else
                le = md;
        }
        long long Mn = Get(bordl, le + 1, 0) + Get(le + 1, bordr, 1);
        le ++;
        Mn = min(Mn, Get(bordl, le + 1, 0) + Get(le + 1, bordr, 1));
        printf("%lld ", res[i] + Mn);
    }
    return 0;
}