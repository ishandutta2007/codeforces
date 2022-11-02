#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 505;
int n, m, r, A[N][N], F[N][N], P[N][N], R[N];
pair < int , long long > Mx, Pre[N][N], Suf[N][N];
inline void Handle(int val, long long c)
{
    if (val > Mx.x)
        Mx.x = val, Mx.y = 0;
    if (val == Mx.x)
        Mx.y += c;
}
int main()
{
    scanf("%d%d%d", &n, &m, &r);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &A[i][j]), P[i][j] = P[i][j - 1] + A[i][j];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            F[i][j] = Pre[i][j].x = Suf[i][j].x = -1e9;
    for (int i = r + 1; i + r <= n; i++)
        for (int j = r + 1; j + r <= m; j++)
        {
            F[i][j] = 0;
            for (int h = i - r; h <= i + r; h++)
            {
                int jx = sqrt(r * r - (i - h) * (i - h));
                F[i][j] += P[h][j + jx] - P[h][j - jx - 1];
            }
        }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            Pre[i][j] = max(make_pair(F[i][j], 1ll), Pre[i][j -1]);
            if (F[i][j] == Pre[i][j -1].x)
                Pre[i][j].y ++;
        }
        for (int j = m; j; j--)
        {
            Suf[i][j] = max(make_pair(F[i][j], 1ll), Suf[i][j + 1]);
            if (F[i][j] == Suf[i][j + 1].x)
                Suf[i][j].y ++;
        }
    }
    for (int i = 1; i < N; i++)
    {
        R[i] = 0;
        for (int j = 1; j <= i; j++)
            if (r * r >= max((j - 1) * (j - 1), (i - j) * (i - j)))
            {
                int ax = sqrt(r * r - (j - 1) * (j - 1));
                int bx = sqrt(r * r - (i - j) * (i - j));
                R[i] = max(R[i], ax + bx + 1);
            }
    }
    for (int i = r + 1; i + r <= n; i++)
        for (int j = r + 1; j + r <= m; j++)
            for (int h = 1; i + h - 1 + r <= n; h++)
            {
                int w = (R[h] == 0);
                if (j - R[h] >= 0) Handle(F[i][j] + Pre[i + h - 1][j - R[h]].x, Pre[i + h - 1][j - R[h]].y);
                if (j + R[h] + w < N && h - 1) Handle(F[i][j] + Suf[i + h - 1][j + R[h] + w].x, Suf[i + h - 1][j + R[h] + w].y);
            }
    return !printf("%d %lld", Mx.x, Mx.y);
}