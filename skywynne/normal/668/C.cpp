#include<bits/stdc++.h>
#define ld long double
#define eps (ld)1e-9
using namespace std;
const int N = 1e5 + 10, Mod = 1e9 + 7;
int n, m, q, t;
ld A[2][N], B[2][N];
inline ld SQRT(ld a)
{
    assert(a >= 0);
    assert(a <= 100);
    ld l = 0, r = 11, md, ts = 90;
    for (; ts ; ts --)
    {
        md = (l + r) / 2;
        if (md * md <= a)
            l = md;
        else
            r = md;
    }
    return (l);
}
inline pair < ld, ld > Solve(ld a, ld b, ld c, ld d)
{
    c -= a * d;
    b = a - b - d;
    ld dt = sqrt(b * b - 4 * c);
    ld y = (-b + dt) / 2;
    if (y < 0 || y > 1)
        y = (b + dt) / 2;
    ld x = d - y;
    assert(y >= 0 && y <= 1);
    assert(x >= 0 && x <= 1);
    return (make_pair(x, y));
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> A[0][i];
    for (int i = 1; i <= n; i++)
        cin >> A[1][i];
    ld a = 0, b = 0;
    for (int i = 1; i < n; i++)
    {
        pair < ld, ld > ps = Solve(a, b, A[0][i], A[0][i] + A[1][i]);
        B[0][i] = ps.first;
        B[1][i] = ps.second;
        a += B[1][i];
        b += B[0][i];
    }
    B[0][n] = 1 - b;
    B[1][n] = 1 - a;
    cout << fixed << setprecision(12);
    for (int j = 1; j <= n; j++)
        cout << fixed << B[0][j] << ' ';
    cout << endl;
    for (int j = 1; j <= n; j++)
        cout << fixed << B[1][j] << ' ';
    return (0);
}