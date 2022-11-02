#include<bits/stdc++.h>
#define pb push_back
#define lc (id * 2)
#define rc (id * 2 + 1)
#define md ((l + r) >> 1)
using namespace std;
const int N = 1e6 + 10;
int n, q, S[N], Tp[N], Lz[N];
long long L[N], R[N];
vector < long long > U;
inline Upd(int id, int l, int r, int tp)
{
    if (tp == 1) S[id] = r - l, Lz[id] = 1;
    if (tp == 2) S[id] = 0, Lz[id] = 2;
    if (tp == 3) S[id] = r - l - S[id], Lz[id] ^= 3;
}
inline void Shift(int id, int l, int r)
{
    if (Lz[id] == 1) Upd(lc, l, md, 1), Upd(rc, md, r, 1);
    if (Lz[id] == 2) Upd(lc, l, md, 2), Upd(rc, md, r, 2);
    if (Lz[id] == 3) Upd(lc, l, md, 3), Upd(rc, md, r, 3);
    Lz[id] = 0;
}
void Update(int le, int ri, int tp, int id = 1, int l = 0, int r = U.size())
{
    if (ri <= l || r <= le)
        return ;
    if (le <= l && r <= ri)
    {
        Upd(id, l, r, tp);
        return ;
    }
    Shift(id, l, r);
    Update(le, ri, tp, lc, l, md);
    Update(le, ri, tp, rc, md, r);
    S[id] = S[lc] + S[rc];
}
int Get(int id = 1, int l = 0, int r = U.size())
{
    if (r - l < 2) return (l);
    Shift(id, l, r);
    if (S[lc] < md - l)
        return (Get(lc, l, md));
    return (Get(rc, md, r));
}
int main()
{
    scanf("%d", &q); U.pb(1);
    for (int i = 1; i <= q; i++)
        scanf("%d%lld%lld", &Tp[i], &L[i], &R[i]), U.pb(L[i]), U.pb(R[i] + 1);
    sort(U.begin(), U.end()); U.resize(unique(U.begin(), U.end()) - U.begin());
    for (int i = 1; i <= q; i++)
    {
        L[i] = (int)(lower_bound(U.begin(), U.end(), L[i]) - U.begin());
        R[i] = (int)(lower_bound(U.begin(), U.end(), R[i] + 1) - U.begin());
        Update(L[i], R[i], Tp[i]); printf("%lld\n", U[Get()]);
    }
    return (0);
}