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

int N, X[MAXN], Y[MAXN];
int Xs[MAXN], Ys[MAXN];
int nxt[MAXN], head[MAXN];

struct SEG
{
    SEG *s[2];
    int cnt;
    SEG()
    {
        s[0] = s[1] = NULL;
        cnt = 0;
    }
};

SEG* emp(int L, int R)
{
    SEG* ret = new SEG;
    if (L < R)
        {
            int Mid = (L + R) / 2;
            ret->s[0] = emp(L, Mid);
            ret->s[1] = emp(Mid + 1, R);
        }
    return ret;
}

SEG* att(SEG* cur, int L, int R, int B)
{
    SEG* ret = new SEG(*cur);
    ret->cnt++;
    if (L != R)
        {
            int Mid = (L + R) / 2;
            if (B <= Mid)
                ret->s[0] = att(ret->s[0], L, Mid, B);
            else
                ret->s[1] = att(ret->s[1], Mid + 1, R, B); 
        }
    return ret;
}

int qryPre(SEG* cur, int L, int R, int S)
{
    if (R == S) return cur->cnt;
    int Mid = (L + R) / 2;
    if (S <= Mid)
        return qryPre(cur->s[0], L, Mid, S);
    else
        return cur->s[0]->cnt + qryPre(cur->s[1], Mid + 1, R, S);
}

SEG* entry[MAXN];

int qrybipre(int x, int y)
{
    return qryPre(entry[upper_bound(Xs + 1, Xs + N + 1, x) - Xs - 1], 1, N, upper_bound(Ys + 1, Ys + N + 1, y) - Ys - 1);
}

int main()
{
    scanf("%d", &N);
    int i;
    fortodo(i, 1, N)
        {
            scanf("%d%d", &X[i], &Y[i]);
            Xs[i] = X[i];
            Ys[i] = Y[i];
        }
    sort(Xs + 1, Xs + N + 1);
    sort(Ys + 1, Ys + N + 1);
    fortodo(i, 1, N)
        {
            X[i] = lower_bound(Xs + 1, Xs + N + 1, X[i]) - Xs;
            Y[i] = lower_bound(Ys + 1, Ys + N + 1, Y[i]) - Ys;
        }
    fortodo(i, 1, N) head[i] = 0;
    fortodo(i, 1, N)
        {
            nxt[i] = head[X[i]];
            head[X[i]] = i;
        }
    entry[0] = emp(1, N);
    fortodo(i, 1, N)
        {
            entry[i] = entry[i - 1];
            for (int j = head[i]; j; j = nxt[j])
                entry[i] = att(entry[i], 1, N, Y[j]);
        }
    int A[9], perm[9];
    fortodo(i, 0, 8) perm[i] = i;
    fortodo(i, 0, 8) scanf("%d", &A[i]);
    int p;
    fortodo(p, 1, 362880)
        {               
            int X[3];
            X[0] = Xs[A[perm[0]] + A[perm[1]] + A[perm[2]]];
            X[1] = Xs[A[perm[0]] + A[perm[1]] + A[perm[2]] + A[perm[3]] + A[perm[4]] + A[perm[5]]];
            X[2] = Xs[N];
            Y[0] = Ys[A[perm[0]] + A[perm[3]] + A[perm[6]]];
            Y[1] = Ys[A[perm[0]] + A[perm[1]] + A[perm[3]] + A[perm[4]] + A[perm[6]] + A[perm[7]]];
            Y[2] = Ys[N];
            fortodo(i, 0, 8)
                {
                    int x, y;
                    x = i / 3, y = i % 3;
                    int Expect = 0, tx, ty;
                    fortodo(tx, 0, x)
                        fortodo(ty, 0, y)
                            Expect += A[perm[tx * 3 + ty]];
                    if (Expect != qrybipre(X[x], Y[y]))
                        break;
                }
            if (i == 9)
                {
                    printf("%.9f %.9f\n%.9f %.9f\n", X[0] + 0.5, X[1] + 0.5, Y[0] + 0.5, Y[1] + 0.5);
                    return 0;
                }
            next_permutation(perm, perm + 9);
        }
    printf("-1\n");
}