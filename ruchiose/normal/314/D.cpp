#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

#define pii pair<i64,i64>
#define mp make_pair
#define x first
#define y second

const int MAXN = 100010;
const i64 Inf = (i64)(1e+18);

bool cmp_px(pii a, pii b)
{
    return a.x < b.x;
}

int N, i, j;
pii p[MAXN];
i64 pma[MAXN], pmi[MAXN], sma[MAXN], smi[MAXN];

bool chk(i64 diam)
{
    int L, R;
    L = R = 1;
    fortodo(L, 1, N)
        {
            while ((R < N) && (p[R + 1].x - p[L].x <= diam)) R++;
            if (max(pma[L - 1], sma[R + 1]) - min(pmi[L - 1], smi[R + 1]) <= diam) return true;
        }
    return false;
}

int main()
{
    scanf("%d", &N);
    fortodo(i, 1, N)
        {
            i64 u, v;
            scanf("%I64d%I64d", &u, &v);
            p[i] = mp(u + v, u - v);
        }
    sort(p + 1, p + N + 1, cmp_px);
    pma[0] = -Inf; pmi[0] = Inf;
    fortodo(i, 1, N)
        {
            pma[i] = max(pma[i - 1], p[i].y);
            pmi[i] = min(pmi[i - 1], p[i].y);
        }
    sma[N + 1] = -Inf; smi[N + 1] = Inf;
    for (i = N; i; i--)
        {
            sma[i] = max(sma[i + 1], p[i].y);
            smi[i] = min(smi[i + 1], p[i].y);
        }
    if (chk(0))
        {
            printf("%.9f\n", 0.0);
            return 0;
        }
    i64 L = 0, R = (i64)(4e+9), Mid;
    while (R - L > 1)
        {
            Mid = (L + R) / 2;
            if (chk(Mid))
                R = Mid;
            else
                L = Mid;
        }
    printf("%.9f\n", 0.5 * R);
}