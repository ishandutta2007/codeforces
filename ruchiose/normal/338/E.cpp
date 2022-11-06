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

int N, Len, H, A[150010], B[150010];
int S[300010], W;

struct SEG
{
    SEG* s[2];
    int Sum, minPrefix;
    SEG()
    {
        s[0] = s[1] = NULL;
        Sum = minPrefix = 0;
    }
};

SEG* emp(int L, int R)
{
    SEG* ret = new SEG;
    if (L != R)
        {
            int Mid = (L + R) >> 1;
            ret->s[0] = emp(L, Mid);
            ret->s[1] = emp(Mid + 1, R);
        }
    return ret;
}

void recalc(SEG* cur)
{
    if (cur->s[0])
        {
            cur->Sum = cur->s[0]->Sum + cur->s[1]->Sum;
            cur->minPrefix = min(cur->s[0]->minPrefix, cur->s[0]->Sum + cur->s[1]->minPrefix);
        }
    else
        cur->minPrefix = min(0, cur->Sum);
}

void attach(SEG* cur, int L, int R, int b, int delta)
{
    if (L == R)
        cur->Sum += delta;
    else
        {
            int Mid = (L + R) / 2;
            if (b <= Mid)
                attach(cur->s[0], L, Mid, b, delta);
            else
                attach(cur->s[1], Mid + 1, R, b, delta);
        }
    recalc(cur);
}

void DSCRTZ()
{
    W = N + Len;
    int i;
    fortodo(i, 1, Len) S[i] = B[i];
    fortodo(i, 1, N) S[Len + i] = A[i];
    sort(S + 1, S + W + 1);
    fortodo(i, 1, Len) B[i] = lower_bound(S + 1, S + W + 1, B[i]) - S;
    fortodo(i, 1, N) A[i] = lower_bound(S + 1, S + W + 1, A[i]) - S;
}

SEG* seg;

int main()
{
    scanf("%d%d%d", &N, &Len, &H);
    int i;
    fortodo(i, 1, Len)
        {
            scanf("%d", &B[i]);
            B[i] = H - B[i];
        }
    fortodo(i, 1, N) scanf("%d", &A[i]);
    DSCRTZ();
    seg = emp(1, W);
    fortodo(i, 1, Len) attach(seg, 1, W, B[i], 1);
    int ans = 0;
    fortodo(i, 1, Len) attach(seg, 1, W, A[i], -1);
    if (seg->minPrefix >= 0) ans++;
    fortodo(i, 2, N - Len + 1)
        {
            attach(seg, 1, W, A[i - 1], 1);
            attach(seg, 1, W, A[i + Len - 1], -1);
            if (seg->minPrefix >= 0) ans++;
        }
    printf("%d\n", ans);
}