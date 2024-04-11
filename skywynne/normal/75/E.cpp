#include<bits/stdc++.h>
#define x real()
#define y imag()
using namespace std;
typedef long double ld;
typedef complex < ld > point;
const ld INF = 1e18, eps = 1e-9;
const int N = 41;
int n, m;
ld D[N][N];
point st, en, A[N];
inline ld Cross(point a, point b)
{
    return (a.x * b.y - a.y * b.x);
}
inline ld Get(point a, point b, point c, point d)
{
    ld ab_cd = Cross(b - a, d - c);
    if (abs(ab_cd) <= eps)
        return (-INF);
    return Cross(c - a, d - c) / ab_cd;
}
inline point Intersection(point a, point b, point c, point d)
{
    ld r = Get(a, b, c, d), t = Get(c, d, a, b);
    if (min(r, t) < 0.0 || max(r, t) > 1.0)
        return point(-INF, -INF);
    return (a + (b - a) * r);
}
inline ld Dist(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
inline void Add(int i, int j, ld d)
{
    D[i][j] = D[j][i] = d;
}
inline point read()
{
    ld a, b;
    cin >> a >> b;
    return point(a, b);
}
int main()
{
    st = read();
    en = read();
    cin >> n; m = n;
    for (int i = 0; i < n; i++)
        A[i] = read();
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (i != j)
                D[i][j] = INF;
    for (int i = 0; i < n; i++)
    {
        point p = Intersection(st, en, A[i], A[(i + 1) % n]);
        if (p.x != -INF)
        {
            if (m >= n + 1 && A[n] == p)
                continue;
            if (m >= n + 2 && A[n + 1] == p)
                continue;
            Add(m, i, Dist(p, A[i]));
            Add(m, (i + 1) % n, Dist(p, A[(i + 1) % n]));
            A[m ++] = p;
        }
    }
    if (m <= n + 1)
        return cout << fixed << setprecision(10) << Dist(st, en), 0;
    if (Dist(st, A[n]) > Dist(st, A[n + 1]))
        swap(A[n], A[n + 1]);
    Add(n + 2, n, Dist(st, A[n]));
    Add(n + 3, n + 1, Dist(en, A[n + 1]));
    Add(n, n + 1, Dist(A[n], A[n + 1]) * 2);
    for (int i = 0; i < n; i++)
        Add(i, (i + 1) % n, Dist(A[i], A[(i + 1) % n]));
    for (int k = 0; k <= n + 3; k++)
        for (int i = 0; i <= n + 3; i++)
            for (int j = 0; j <= n + 3; j++)
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);

    cout << fixed << setprecision(10) << D[n + 2][n + 3];
    return (0);
}