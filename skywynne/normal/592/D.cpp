#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int MXN = 2e5 + 10;
int n, m, r, t, c, Mn = 1e9, M[MXN], T[MXN], dp[2][MXN], dp2[2][MXN];
vector < int > V[MXN];
void DFS(int v, int p)
{
    int Mx = 0, s = 0;
    for (auto X : V[v])
        if (X != p)
        {
            DFS(X, v);
            T[v] |= T[X];
            if (!T[X])
                continue;
            dp[0][v] += dp[0][X] + 2;
            if (Mx < dp[0][X] - dp[1][X])
                Mx = dp[0][X] - dp[1][X];
            s += dp[0][X] + 2;
        }
    dp[1][v] = max(s - Mx - 1, 0);
    T[v] |= M[v];
}
void DFS2(int v, int p, int tv)
{
    int s = 0, tt = 0, cc = 0;
    pair < int , int > Mx[2];
    Mx[0] = Mx[1] = {0, 0};
    for (auto X : V[v])
    {
        if (!T[X] || X == p)
            continue;
        s += dp[0][X] + 2; tt = X; cc ++;
        if (Mx[1].x <= dp[0][X] + 2 - dp[1][X] - 1)
            Mx[1] = {dp[0][X] + 2 - dp[1][X] - 1, X};
        if (Mx[0].x <= Mx[1].x)
            swap(Mx[0], Mx[1]);
    }
    if (tv)
    {
        cc = 2;
        if (Mx[1].x <= dp2[0][v] - dp2[1][v])
            Mx[1] = {dp2[0][v] - dp2[1][v], 0};
        if (Mx[0].x <= Mx[1].x)
            swap(Mx[0], Mx[1]);
    }
    //printf("%d : %d, (%d, %d), (%d, %d)\n", v, s, Mx[0].x, Mx[0].y, Mx[1].x, Mx[1].y);
    for (auto X : V[v])
    {
        if (!T[X] || X == p)
            continue;
        if (cc >= 2 || (cc == 1 && tt != X))
        {
            dp2[0][X] = s - dp[0][X] + dp2[0][v];
            dp2[1][X] = dp2[0][X] - 1;
            if (Mx[0].y == X)
                dp2[1][X] -= Mx[1].x;
            else
                dp2[1][X] -= Mx[0].x;
        }
        else if (M[v])
        {
            dp2[0][X] = 2;
            dp2[1][X] = 1;
        }
    }
    for (auto X : V[v])
    {
        if (X == p)
            continue;
        if (cc >= 2 || (cc == 1 && tt != X) || M[v])
            DFS2(X, v, 1);
        else
            DFS2(X, v, 0);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &r, &t);
        V[r].push_back(t);
        V[t].push_back(r);
    }
    for (int i = 1; i <= m; i++)
        scanf("%d", &r), M[r] = 1;
    DFS(1, 0); DFS2(1, 0, 0);
    /*printf("dp\n");
    for (int i = 1; i <= n; i++)
        printf("%d : (%d, %d)\n", i, dp[0][i], dp[1][i]);
    printf("dp2\n");
    for (int i = 1; i <= n; i++)
        printf("%d : (%d, %d)\n", i, dp2[0][i], dp2[1][i]);*/
    for (int i = 1; i <= n; i++)
        if (Mn > min(dp[0][i] + dp2[1][i], dp[1][i] + dp2[0][i]) && M[i])
            Mn = min(dp[0][i] + dp2[1][i], dp[1][i] + dp2[0][i]), c = i;
    //printf("%d, %d, %d, %d\n", dp[0][2], dp[1][2], dp2[0][2], dp2[1][2]);
    return !printf("%d\n%d", c, Mn);
}