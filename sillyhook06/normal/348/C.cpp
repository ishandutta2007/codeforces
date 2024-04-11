#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define rep(i,n) for (int i=1;i<=n;++i)
const int N = 100005, M = 320;
int n, m, Q, T;
int S[N], x[N], y[N], L[N], id[N], d[M][M], c[N][M], *s[N];
bool b[N];
long long a[N], res[N], add[N];
int get(int i)
{
    int res = 0;
    rep(j, L[i]) res += b[s[i][j]];
    return res;
}
int work(int x, int y)
{
    if (L[x] > L[y]) swap(x, y);
    int j = 1, res = 0;
    rep(i, L[x])
    {
        while (j <= L[y] && s[y][j] < s[x][i]) ++j;
        if (j > L[y]) break;
        if (s[y][j] == s[x][i]) ++res, ++j;
    }
    return res;
}
int main()
{
//	freopen("C.in","r",stdin);
//	freopen("C.out","w",stdout);
    scanf("%d%d%d", &n, &m, &Q), T = int(sqrt(n + 0.) + 1), s[1] = S;
    rep(i, n) scanf("%I64d", a + i);
    rep(i, m)
    {
        scanf("%d", L + i);
        rep(j, L[i]) scanf("%d", s[i] + j), res[i] += a[s[i][j]];
        s[i + 1] = s[i] + L[i];
        sort(s[i] + 1, s[i + 1] + 1);
        if (L[i] < T) x[++*x] = i;
        else y[++*y] = i, id[i] = *y;
    }
    //x small		y big
    rep(i, n) a[i] = 0;
    rep(k, *y)
    {
        int i = y[k];
        rep(j, L[i]) b[s[i][j]] = 1;
        rep(j, *x) c[x[j]][k] = get(x[j]);
        rep(j, L[i]) b[s[i][j]] = 0;
    }
    rep(i, *y) rep(j, i) d[i][j] = d[j][i] = i == j ? L[y[i]] : work(y[i], y[j]);
    while (Q--)
    {
        char ch[5];
        int i;
        scanf("%s%d", ch, &i);
        long long ans = res[i], z;
        if (*ch == '?')
        {
            ans = res[i];
            if (L[i] < T)
            {
                rep(j, L[i]) ans += a[s[i][j]];
                rep(j, *y) ans += add[y[j]] * c[i][j];
            }
            else
            {
                rep(j, *y) ans += add[y[j]] * d[id[i]][j];
            }
            printf("%I64d\n", ans);
        }
        else
        {
            scanf("%I64d", &z);
            if (L[i] < T)
            {
                rep(j, L[i]) a[s[i][j]] += z;
                rep(j, *y) res[y[j]] += z * c[i][j];
            }
            else add[i] += z;
        }
    }
    return 0;
}