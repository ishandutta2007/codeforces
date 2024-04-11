// In The Name Of The Queen
#include<bits/stdc++.h>
#define lc (id << 1)
#define rc (lc ^ 1)
#define md (l + r >> 1)
using namespace std;
const int N = 30003, K = 1009, LG = 17, Mod = 1e9 + 7;
int n, q, k, m, V[N], W[N], L[N], R[N], Pw[N], dp[LG][K], res[N];
vector < int > Vec[N * 4];
void Add(int le, int ri, int i, int id = 1, int l = 0, int r = m)
{
    if (ri <= l || r <= le)
        return ;
    if (le <= l && r <= ri)
        return void(Vec[id].push_back(i));
    Add(le, ri, i, lc, l, md);
    Add(le, ri, i, rc, md, r);
}
void DFS(int id = 1, int l = 0, int r = m, int h = 1)
{
    for (int i = 0; i <= k; i ++)
        dp[h][i] = dp[h - 1][i];
    for (int i : Vec[id])
        for (int j = k; j >= W[i]; j --)
            dp[h][j] = max(dp[h][j], dp[h][j - W[i]] + V[i]);
    if (r - l < 2)
    {
        int hsh = 0, Mx = dp[h][0];
        for (int i = 1; i <= k; i ++)
            Mx = max(Mx, dp[h][i]), hsh = (hsh + Mx * 1LL * Pw[i - 1]) % Mod;
        res[l] = hsh;
        return ;
    }
    else
        DFS(lc, l, md, h + 1), DFS(rc, md, r, h + 1);
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i ++)
        scanf("%d%d", &V[i], &W[i]), L[i] = 0, R[i] = N;
    scanf("%d", &q);
    for (int i = 0; i < q; i ++)
    {
        int id, tp;
        scanf("%d", &tp);
        if (tp == 1)
            scanf("%d%d", &V[n], &W[n]), L[n] = m, R[n] = N, n ++;
        else if (tp == 2)
            scanf("%d", &id), R[id - 1] = m;
        else
            m ++;
    }
    Pw[0] = 1;
    for (int i = 1; i < N; i ++)
        Pw[i] = Pw[i - 1] * (long long)(1e7 + 19) % Mod;
    memset(dp, -63, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < n; i ++)
        Add(L[i], min(R[i], m), i);
    DFS();
    for (int i = 0; i < m; i ++)
        printf("%d\n", res[i]);
    return 0;
}