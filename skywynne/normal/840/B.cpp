#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 3e5 + 10;
int n, m, r, t, ver, c, A[N], M[N], H[N], R[N], C[2];
vector < int > res;
vector < pair < int , int > > V[N];
bool DFS(int v)
{
    bool tp = A[v];
    M[v] = 1;
    for (auto X : V[v])
    {
        if (M[X.x])
            continue;
        bool w = DFS(X.x);
        if (w == 1)
            res.push_back(X.y);
        tp ^= w;
    }
    return (tp);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++)
        if (A[i] == -1)
            ver = i;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &r, &t);
        V[r].push_back({t, i});
        V[t].push_back({r, i});
    }
    for (int i = 1; i <= n; i++)
        if (A[i] != -1)
            c += A[i];
    if (c % 2 == 1 && ver == 0)
        return !printf("-1");
    for (int i = 1; i <= n; i++)
        if (A[i] == -1)
            A[i] = 0;
    if (c % 2 == 1)
        A[ver] = 1;
    DFS(1);
    sort(res.begin(), res.end());
    printf("%d\n", (int)res.size());
    for (auto X : res)
        printf("%d\n", X);
    return (0);
}