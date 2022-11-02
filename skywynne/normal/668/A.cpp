#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 1e4 + 10, M = 102, Mod = 1e9 + 7;
int n, m, q,  A[M][M], T[N], R[N], C[N], X[N];
pair < int , int > BackTrack(int nw, int r, int c)
{
    for (nw --; nw >= 0; nw --)
    {
        if (T[nw] == 3)
            continue;
        if (T[nw] == 1)
        {
            if (R[nw] == r)
            {
                if (c == m)
                    c = 1;
                else
                    c ++;
            }
            continue;
        }
        if (R[nw] == c)
        {
            if (r == n)
                r = 1;
            else
                r ++;
        }
    }
    return (make_pair(r, c));
}
int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d%d", &T[i], &R[i]);
        if (T[i] == 3)
        {
            scanf("%d%d", &C[i], &X[i]);
            auto ps = BackTrack(i, R[i], C[i]);
            A[ps.x][ps.y] = X[i];
        }
    }
    for (int i = 1; i <= n; i++, puts(""))
        for (int j = 1; j <= m; j++)
            printf("%d ", A[i][j]);
    return (0);
}