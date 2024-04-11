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

int N, A[MAXN], B[MAXN], F[MAXN << 1];

struct SEG
{
    SEG* s[2];
    int Count;
    SEG()
    {
        s[0] = s[1] = NULL;
        Count = 0;
    }
};

SEG* emp(int L, int R)
{
    SEG* ret = new SEG;
    if (L != R)
        {
            int Mid = (L + R) / 2;
            ret->s[0] = emp(L, Mid);
            ret->s[1] = emp(Mid + 1, R);
        }
    return ret;
}

SEG* att(SEG* cur, int L, int R, int b)
{
    SEG* nxt = new SEG(*cur);
    nxt->Count++;
    if (L != R)
        {
            int Mid = (L + R) / 2;
            if (b <= Mid)
                nxt->s[0] = att(nxt->s[0], L, Mid, b);
            else
                nxt->s[1] = att(nxt->s[1], Mid + 1, R, b);
        }
    return nxt;
}

int query(SEG* cur, int L, int R, int l, int r)
{
    if ((L == l) && (R == r)) return cur->Count;
    int Mid = (L + R) / 2;
    if (r <= Mid) return query(cur->s[0], L, Mid, l, r);
    if (l >  Mid) return query(cur->s[1], Mid + 1, R, l, r);
    return query(cur->s[0], L, Mid, l, Mid) + query(cur->s[1], Mid + 1, R, Mid + 1, r);
}

SEG* entries[MAXN << 1];

int Query(int xl, int xr, int yl, int yr)
{
    if ((xl > xr) || (yl > yr)) return 0;
    return query(entries[xr], 1, N * 2, yl, yr) - query(entries[xl - 1], 1, N * 2, yl, yr);
}

int PI[MAXN], PO[MAXN];

int main()
{
    scanf("%d", &N);
    int i;
    fortodo(i, 1, N * 2) F[i] = 0;
    fortodo(i, 1, N)
        {
            scanf("%d%d", &A[i], &B[i]);
            if (A[i] > B[i])
                swap(A[i], B[i]);
            F[A[i]] = B[i];
        }
    entries[0] = emp(1, N * 2);
    fortodo(i, 1, N * 2)
        if (F[i])
            entries[i] = att(entries[i - 1], 1, N * 2, F[i]);
        else
            entries[i] = entries[i - 1];
    i64 NIE = 0;
    fortodo(i, 1, N)
        {
            PI[i] = Query(A[i] + 1, B[i] - 1, A[i] + 1, B[i] - 1);
            PO[i] = Query(1, A[i] - 1, B[i] + 1, N * 2) + Query(1, A[i] - 1, 1, A[i] - 1) + Query(B[i] + 1, N * 2, B[i] + 1, N * 2);
            int PINTERSECT = N - 1 - PI[i] - PO[i];
            NIE += 2LL * PI[i] * PO[i] + 1LL * (PI[i] + PO[i]) * PINTERSECT;
        }
    i64 TOT = (1LL * N * (N - 1LL) * (N - 2LL)) / 6;
    cout << TOT - (NIE / 2) << endl;
}