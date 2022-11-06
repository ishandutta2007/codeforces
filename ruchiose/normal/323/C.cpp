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

const int MAXN = 1000010;

int N, A[MAXN], B[MAXN], iB[MAXN];

struct SEG
{
    SEG *s[2];
    int Count;
    SEG()
    {
        s[0] = s[1] = NULL;
        Count = 0;
    }
};

int countCallNewSEG = 0;
SEG Reserved[25000000];

SEG* NewSEG()
{
    return &(Reserved[countCallNewSEG++]);
}

SEG* emp(int L, int R)
{
    SEG* cur = NewSEG();
    if (L != R)
        {
            int Mid = (L + R) / 2;
            cur->s[0] = emp(L, Mid);
            cur->s[1] = emp(Mid + 1, R);
        }
    return cur;
}

SEG* att(SEG* cur, int L, int R, int B)
{
    SEG* ret = NewSEG();
    *ret = *cur;
    ret->Count++;
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

int query(SEG* cur, int L, int R, int l, int r)
{
    if ((L == l) && (R == r)) return cur->Count;
    int Mid = (L + R) / 2;
    if (r <= Mid) return query(cur->s[0], L, Mid, l, r);
    if (l >  Mid) return query(cur->s[1], Mid + 1, R, l, r);
    return query(cur->s[0], L, Mid, l, Mid) + query(cur->s[1], Mid + 1, R, Mid + 1, r);
}

SEG* Entries[MAXN];

int Q(int pl, int pr, int ql, int qr)
{
    return query(Entries[pr], 1, N, ql, qr) - query(Entries[pl - 1], 1, N, ql, qr);
}

int X;

void F(int &x)
{
    x = (x - 1 + X) % N + 1;
}

int main()
{
    scanf("%d", &N);
    int i;
    fortodo(i, 1, N) scanf("%d", &A[i]);
    fortodo(i, 1, N)
        {
            scanf("%d", &B[i]);
            iB[B[i]] = i;
        }
    Entries[0] = emp(1, N);
    fortodo(i, 1, N)
        Entries[i] = att(Entries[i - 1], 1, N, iB[A[i]]);
    int M;
    X = 0;
    for (scanf("%d", &M); M; M--)
        {
            int a, b, c, d;
            scanf("%d%d%d%d", &a, &b, &c, &d);
            F(a); F(b); F(c); F(d);
            if (a > b) swap(a, b);
            if (c > d) swap(c, d);
            int response = Q(a, b, c, d);
            printf("%d\n", response);
            X = response + 1;
        }
}