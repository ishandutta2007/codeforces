// I'm back ...
#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 200005;
int n, q, A[N], Fen[N];
long long R[N];
vector < pair < pair < int , int > , int > > P[N], S[N];
inline void Add(int i, int val)
{
    for (i ++; i < N; i += i & -i)
        Fen[i] += val;
}
inline int Get(int i)
{
    int ret = 0;
    for (i ++; i; i -= i & -i)
        ret += Fen[i];
    return ret;
}
inline long long F(int a)
{
    return (1LL * a * (a - 1) >> 1);
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    for (int i = 1; i <= q; i++)
    {
        int l, r, u, d;
        scanf("%d%d%d%d", &l, &d, &r, &u);
        R[i] = F(n) - F(l - 1) - F(n - r) - F(d - 1) - F(n - u);
        P[l - 1].pb({{0, d - 1}, i});
        P[l - 1].pb({{u, n}, i});
        S[r + 1].pb({{0, d - 1}, i});
        S[r + 1].pb({{u, n}, i});
    }
    for (int i = 1; i <= n; i++)
    {
        Add(A[i], 1);
        for (auto X : P[i])
            R[X.y] += F(Get(X.x.y) - Get(X.x.x));
    }
    memset(Fen, 0, sizeof(Fen));
    for (int i = n; i; i--)
    {
        Add(A[i], 1);
        for (auto X : S[i])
            R[X.y] += F(Get(X.x.y) - Get(X.x.x));
    }
    for (int i = 1; i <= q; i++)
        printf("%lld\n", R[i]);
    return (0);
}