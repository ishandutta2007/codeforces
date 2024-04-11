#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define rep(i,n) for (int i=0;i<n;++i)
const int N = 305;
const double eps = 1e-8;
int n, m, K, a[N][N], p[N], q[N], *A, *B;
double w[N], ans;
bool flag[N][N];
bool cmp(const int i, const int j)
{
    return B[i] - A[i] < B[j] - A[j];
}
double cross(int i, int j)
{
    return (A[j] - A[i]) / (B[i] - A[i] - B[j] + A[j] + 0.);
}
double f(int i, double x)
{
    return B[i] * x + (1 - x) * A[i];
}
double cal(int i, int j, double l, double r)
{
    double FL = f(i, l), GL = f(j, l), FR = f(i, r), GR = f(j, r);
    if (FL + eps < GL || FR + eps < GR) return 0;
    return (FL + FR - GL - GR) * (r - l) / 2.;
}
double get(int i, int j, double l, double r)
{
    double m = cross(i, j);
    return l < m && m < r ? cal(i, j, l, m) + cal(i, j, m, r) : cal(i, j, l, r);
}
int main()
{
    scanf("%d%d", &n, &m);
    rep(i, n) rep(j, m + 1) scanf("%d", &a[j][i]);
    rep(i, n)
    {
        double ans = 0;
        rep(k, m)
        {
            A = a[k], B = a[k + 1];
            if (!i)
            {
                ans += (A[i] + B[i]) / 2.;
                continue;
            }
            int h = 0;
            rep(j, i) if (!flag[k][j])
            {
                p[h++] = j;
                if (A[i] >= A[j] && B[i] >= B[j]) flag[k][j] = 1;
            }
            sort(p, p + h, cmp);
            int t = 0;
            rep(_, h)
            {
                int j = p[_];
                while (t && cross(j, q[t - 1]) < w[t - 1] + eps) --t;
                if (t) w[t] = cross(q[t - 1], j);
                q[t++] = j;
            }
            int x = q[0];
            double l = 0, r;
            rep(_, t) if (_)
            {
                int j = q[_];
                r = w[_], ans += get(i, x, l, r), x = j, l = r;
            }
            r = 1, ans += get(i, x, l, r);
            rep(j, i) if (!flag[k][j])
                if (A[j] >= A[i] && B[j] >= B[i]) flag[k][i] = 1;
        }
        printf("%.15lf\n", ans);
    }
    return 0;
}