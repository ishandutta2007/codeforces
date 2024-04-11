#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10, NX = 1e9 + 7;
int n, r, t, p, c, m, k, cyc, Mx, M[N], T[N][30], dp[N][30];
string A;
vector < int > V[N];
void DFS(int v)
{
    M[v] = 1;
    for (auto X : V[v])
    {
        if (M[X] == 1)
        {
            cyc = 1;
            continue;
        }
        if (M[X] == 2)
            continue;
        DFS(X);
    }
    M[v] = 2;
}
void Solve(int i, int j)
{
    T[i][j] = 1;
    dp[i][j] = (A[i] == 'a' + j);
    for (auto X : V[i])
    {
        if (!T[X][j])
            Solve(X, j);
        dp[i][j] = max(dp[i][j], dp[X][j] + (A[i] == 'a' + j));
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    cin >> A; A = '#' + A;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &r, &t);
        V[r].push_back(t);
    }
    for (int i = 1; i <= n; i++)
        if (!M[i])
            DFS(i);
    if (cyc == 1)
        return !printf("-1");
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 26; j++)
            if (!T[i][j])
                Solve(i, j);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 26; j++)
            Mx = max(Mx, dp[i][j]);
    printf("%d", Mx);
    return (0);
}