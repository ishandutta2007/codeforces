#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 2e5 + 10, LOG = 19;
int n, m, r, t, c, w, ts, Mx, A[N], S[N], H[N], PS[N], Par[N], Pow[LOG], Log[N], MN[LOG][N];
bool M[N];
pair < int , int > E[N], dp[N], dp2[N];
vector < pair < int , int > > V[N];
void Euler(int v, int p)
{
    S[v] = ts; E[ts ++] = {H[v], v}; Par[v] = p;
    for (auto X : V[v])
        if (X.x != p)
            H[X.x] = H[v] + 1, Euler(X.x, v), E[ts ++] = {H[v], v};
}
void Pre()
{
    int lg = 0; Pow[0] = 1; Log[1] = 0;
    for (int i = 1; i < LOG; i++)
        Pow[i] = Pow[i - 1] * 2, Log[Pow[i]] = i;
    for (int i = 2; i < N; i++)
        lg += (Log[i] > 0), Log[i] = lg;
    for (int j = 0; j < ts; j++)
        MN[0][j] = j;
    for (int i = 1; i < LOG; i++)
        for (int j = 0; j < ts - Pow[i] + 1; j++)
        {
            MN[i][j] = MN[i - 1][j + Pow[i - 1]];
            if (E[MN[i - 1][j]].x < E[MN[i - 1][j + Pow[i - 1]]].x)
                MN[i][j] = MN[i - 1][j];
        }
}
int RMQ(int l, int r)
{
    if (E[MN[Log[r - l + 1]][l]].x < E[MN[Log[r - l + 1]][r - Pow[Log[r - l + 1]] + 1]].x)
        return (MN[Log[r - l + 1]][l]);
    return (MN[Log[r - l + 1]][r - Pow[Log[r - l + 1]] + 1]);
}
int LCA(int v, int u)
{
    return (E[RMQ(min(S[v], S[u]), max(S[v], S[u]))].y);
}
void DFS(int v, int p)
{
    for (auto X : V[v])
    {
        if (X.x == p)
            continue;
        DFS(X.x, v);
        if (dp[X.x].y == -1)
            continue;
        if (dp[X.x].y + X.y == dp[v].y)
            dp[v].x = v;
        if (dp[X.x].y + X.y > dp[v].y)
            dp[v] = {dp[X.x].x, dp[X.x].y + X.y};
    }
}
void DFS2(int v, int p)
{
    pair < int , pair < int , int > > MX[3];
    MX[0] = {0, dp2[v]}; MX[1] = MX[2] = {0, {0, -1}};
    for (auto X : V[v])
    {
        if (X.x == p)
            continue;
        if (dp[X.x].y == -1)
            continue;
        if (MX[2].y.y <= dp[X.x].y + X.y)
            MX[2] = {X.x, {dp[X.x].x, dp[X.x].y + X.y}};
        if (MX[1].y.y <= MX[2].y.y)
            swap(MX[1], MX[2]);
        if (MX[0].y.y <= MX[1].y.y)
            swap(MX[0], MX[1]);
    }
    for (auto X : V[v])
    {
        if (X.x == p)
            continue;
        if (MX[0].y.y == -1)
            continue;
        if (MX[0].x != X.x)
        {
            if (MX[1].y.y != MX[0].y.y)
            {
                dp2[X.x] = {MX[0].y.x, MX[0].y.y + X.y};
                continue;
            }
            if (MX[1].x != X.x)
                dp2[X.x] = {v, MX[0].y.y + X.y};
            if (MX[1].x == X.x && MX[0].y.y == MX[2].y.y)
                dp2[X.x] = {v, MX[0].y.y + X.y};
            if (MX[1].x == X.x && MX[0].y.y != MX[2].y.y)
                dp2[X.x] = {MX[0].y.x, MX[0].y.y + X.y};
            continue;
        }
        if (MX[1].y.y == -1)
            continue;
        if (MX[1].y.y == MX[2].y.y)
            dp2[X.x] = {v, MX[1].y.y + X.y};
        if (MX[1].y.y != MX[2].y.y)
            dp2[X.x] = {MX[1].y.x, MX[1].y.y + X.y};
    }
    for (auto X : V[v])
        if (X.x != p)
            DFS2(X.x, v);
    if (dp[v].y == dp2[v].y || (!M[v]))
        return ;
    if (dp[v].y > dp2[v].y)
    {
        PS[dp[v].x] ++;
        PS[Par[v]] --;
        return ;
    }
    int l = LCA(v, dp2[v].x);
    PS[v] ++; PS[dp2[v].x] ++; PS[l] --; PS[Par[l]] --;
}
int DFS3(int v, int p)
{
    for (auto X : V[v])
        if (X.x != p)
            A[v] += DFS3(X.x, v);
    return (A[v] += PS[v]);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
        scanf("%d", &r), M[r] = 1;
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d%d", &r, &t, &w);
        V[r].push_back({t, w});
        V[t].push_back({r, w});
    }
    for (int i = 1; i <= n; i++)
    {
        if (M[i])
            dp[i] = dp2[i] = {i, 0};
        else
            dp[i] = dp2[i] = {0, -1};
    }
    Euler(n - 1, 0); Pre(); DFS(n - 1, 0);
    DFS2(n - 1, 0); DFS3(n - 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (Mx == A[i] && (!M[i]))
            c ++;
        if (Mx < A[i] && (!M[i]))
            Mx = A[i], c = 1;
    }
    return !printf("%d %d", Mx, c);
}