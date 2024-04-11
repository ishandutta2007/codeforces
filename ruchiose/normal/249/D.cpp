// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define i64 long long
#define d64 long double
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int MAXN = 100010;

int N, A, B, C, D, x[MAXN], y[MAXN];
i64 X[MAXN], Y[MAXN], Xs[MAXN], Ys[MAXN];

typedef pair<int,int> PII;

bool cmp(const PII &a, const PII &b)
{
    return (a.first == b.first) ? (a.second > b.second) : (a.first < b.first);
}

PII p[MAXN];

int V[MAXN];

void init()
{
    int i;
    fortodo(i, 1, N) V[i] = 0;
}

void att(int x, int v)
{
    for (; x <= N; x += x & -x) V[x] = max(V[x], v);
}

int qry(int x)
{
    int ret = 0;
    for (; x; x -= x & -x) ret = max(ret, V[x]);
    return ret;
}

int main()
{
    scanf("%d%d/%d%d/%d", &N, &A, &B, &C, &D);
    int i;
    fortodo(i, 1, N)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            Xs[i] = X[i] = C * 1LL * x - D * 1LL * y;
            Ys[i] = Y[i] = B * 1LL * y - A * 1LL * x;
            //printf("[%I64d, %I64d]\n", X[i], Y[i]);
        }
    sort(Xs + 1, Xs + N + 1);
    sort(Ys + 1, Ys + N + 1);
    fortodo(i, 1, N)
        {
            x[i] = lower_bound(Xs + 1, Xs + N + 1, X[i]) - Xs;
            y[i] = lower_bound(Ys + 1, Ys + N + 1, Y[i]) - Ys;
        }
    fortodo(i, 1, N) p[i] = make_pair(x[i], y[i]);
    sort(p + 1, p + N + 1, cmp);
    int ans = 0;
    init();
    fortodo(i, 1, N)
        if ((Xs[p[i].first] > 0) && (Ys[p[i].second] > 0))
            {
                //printf("[%I64d, %I64d]\n", Xs[p[i].first], Ys[p[i].second]);
                ans = max(ans, qry(p[i].second - 1) + 1);
                att(p[i].second, qry(p[i].second - 1) + 1);
            }
    printf("%d\n", ans);
}