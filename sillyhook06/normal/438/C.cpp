#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
inline int	read()
{
    int x = 0;
    char ch = getchar();
    bool positive = 1;
    for (; ch < '0' || ch > '9'; ch = getchar())	if (ch == '-')  positive = 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar())	x = x * 10 + ch - '0';
    return positive ? x : -x;
}
#define link Link
#define next Next
#define elif else if
#define rep(i,a,b) for (int i=a;i<=b;++i)
const int N = 205;
const double eps = 1e-8;
struct node
{
    double x, y;
    node() {}
    node(double _x, double _y): x(_x), y(_y) {}
    node operator +(const node &A) const
    {
        return node(x + A.x, y + A.y);
    }
    node operator -(const node &A) const
    {
        return node(x - A.x, y - A.y);
    }
    node operator *(const double &A) const
    {
        return node(x * A, y * A);
    }
    node operator /(const double &A) const
    {
        return node(x / A, y / A);
    }
    double operator *(const node &A) const
    {
        return x * A.x + y * A.y;
    }
    double operator %(const node &A) const
    {
        return x * A.y - y * A.x;
    }
    double operator /(const node &A) const
    {
        return fabs(A.x) < eps ? y / A.y : x / A.x;
    }
    bool operator <(const node &A) const
    {
        return fabs(x - A.x) < eps ? y < A.y : x < A.x;
    }
    double angle() const
    {
        return atan2(y, x);
    }
    double norm() const
    {
        return x * x + y * y;
    }
    double len() const
    {
        return sqrt(x * x + y * y);
    }
    void Read()
    {
        x = read(), y = read();
    }
    void prt() const
    {
        printf("%lf %lf\n", x, y);
    }
} a[N];
bool b[N][N], v[N][N];

int n, ans , f[N][N];
int chg(double a)
{
    return fabs(a) < eps ? 0 : a > 0 ? 1 : -1;
}
bool cross(const node &A, const node &B, const node &C, const node &D)
{
    return chg((B - A) % (D - A)) * chg((B - A) % (C - A)) < 0 && chg((D - C) % (A - C)) * chg((D - C) % (B - C)) < 0;
}
bool up(node A, node B, node C)
{
    if (A.x > B.x) swap(A, B);
    return A.x < C.x + eps && C.x + eps < B.x && ((B - A) % (C - A) < 0);
}
bool inside(const node &A)
{
    bool cnt = 0;
    rep(i, 1, n) if (up(a[i - 1], a[i], A)) cnt ^= 1;
    return cnt;
}
bool check(int l, int r)
{
    if (l + 1 == r) return 1;
    rep(i, 1, n) if (i != l && i != r && !chg((a[l] - a[i]) % (a[r] - a[i])) &&
                     (a[i] - a[l]) / (a[r] - a[l]) > eps && (a[i] - a[l]) / (a[r] - a[l]) < 1) return 0;
    rep(i, 1, n) if (cross(a[l], a[r], a[i - 1], a[i])) return 0;
    return inside((a[l] + a[r]) / 2.);
}
LL dfs(int l, int r)
{
    if (l + 1 == r) return 1;
    if (v[l][r]) return f[l][r];
    v[l][r] = 1;
    int &res = f[l][r];
    res = 0;
    rep(k, l + 1, r - 1) if (b[l][k] && b[r][k] && fabs((a[l] - a[k]) % (a[r] - a[k])) > eps)
        res = (res + dfs(l, k) * dfs(k, r)) % 1000000007;
    return res;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    n = read();
    rep(i, 1, n) a[i].Read();
    *a = a[n];
    rep(i, 1, n) rep(j, 1, i - 1) b[i][j] = b[j][i] = check(j, i);
    printf("%d\n", (int)dfs(1, n));
    return 0;
}