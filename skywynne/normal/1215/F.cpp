// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 3e6 + 10;
struct SCC
{
    int n, cp, S[N], M[N];
    vector < int > T, V[N], VT[N];
    SCC (int nn)
    {
        n = nn; cp = 0; T.clear();
        for (int i = 0; i < n; i++)
            M[i] = S[i] = 0, V[i].clear(), VT[i].clear();
    }
    inline void Add(int v, int u)
    {
        V[v].push_back(u);
        VT[u].push_back(v);
        V[u ^ 1].push_back(v ^ 1);
        VT[v ^ 1].push_back(u ^ 1);
    }
    void DFS(int v)
    {
        M[v] = 1;
        for (auto X : V[v])
            if (!M[X])
                DFS(X);
        T.push_back(v);
    }
    void DFS2(int v)
    {
        M[v] = 1; S[v] = cp;
        for (auto X : VT[v])
            if (!M[X])
                DFS2(X);
    }
    inline bool Solve()
    {
        for (int i = 0; i < n; i++)
            M[i] = 0;
        for (int i = 0; i < n; i++)
            if (!M[i])
                DFS(i);
        reverse(T.begin(), T.end());
        for (int i = 0; i < n; i++)
            M[i] = 0;
        for (auto X : T)
            if (!M[X])
                cp ++, DFS2(X);
        for (int i = 0; i < n; i ++)
            if (S[i] == S[i ^ 1])
                return 0;
        return 1;
    }
    inline bool Check(int v, int u)
    {
        return (S[v] == S[u]);
    }
    inline vector < int > Result()
    {
        T.clear();
        for (int i = 0; i < n; i ++)
            M[i] = 0;
        for (int i = 0; i < n; i ++)
            if (!M[i])
                DFS(i);
        vector < int > R(n >> 1, -1);
        for (int v : T)
            if (R[v >> 1] == -1)
                R[v >> 1] = v & 1;
        return (R);
    }
};
int n, q, MAX, m, L[N], R[N], M[N];
int main()
{
    scanf("%d%d%d%d", &q, &n, &MAX, &m);
    SCC G(2 * n + 2 * MAX + 2);
    // 0 -> 2*n : stations
    for (int i = 0; i < q; i ++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a --; b --;
        G.Add(a << 1, b << 1 ^ 1);
    }
    for (int i = 0; i < n; i ++)
        scanf("%d%d", &L[i], &R[i]), L[i] --;
    for (int i = 1; i <= m; i ++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a --; b --;
        G.Add(a << 1 ^ 1, b << 1);
    }
    // 2*n -> 2*n + 2*MAX + 2 : is greater than
    for (int i = 0; i <= MAX; i ++)
        M[i] = 2 * n + 2 * i + 1;
    for (int i = 0; i < MAX; i ++)
        G.Add(M[i + 1], M[i]);
    G.Add(M[0] ^ 1, M[0]);
    G.Add(M[MAX], M[MAX] ^ 1);
    for (int i = 0; i < n; i ++)
    {
        G.Add(i << 1 ^ 1, M[L[i]]);
        G.Add(i << 1 ^ 1, M[R[i]] ^ 1);
    }
    if (!G.Solve())
        return !printf("-1\n");
    int Mn = 0;
    vector < int > vec, R = G.Result();
    for (int i = 0; i < n; i ++)
        if (R[i])
            vec.push_back(i), Mn = max(Mn, L[i]);
    printf("%d %d\n", (int)vec.size(), Mn + 1);
    for (int v : vec)
        printf("%d ", v + 1);
    return 0;
}