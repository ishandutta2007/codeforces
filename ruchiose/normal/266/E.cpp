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

const i64 MOD = 1000000007;

i64 Cone[100010][6];

void init_cone()
{
    int i, j;
    fortodo(i, 0, 100000)
        {
            Cone[i][0] = 1;
            fortodo(j, 1, 5)
                Cone[i][j] = Cone[i][j - 1] * i % MOD;
        }
    fortodo(i, 1, 100000)
        fortodo(j, 0, 5)
            Cone[i][j] = (Cone[i][j] + Cone[i - 1][j]) % MOD;
}

struct Interval
{
    i64 S[6];
    Interval(i64 I = 0)
    {
        int i;
        fortodo(i, 0, 5)
            S[i] = I % MOD;
    }
};

Interval sumSame(i64 L, i64 R, i64 x)
{
    Interval ret;
    int i;
    fortodo(i, 0, 5) ret.S[i] = (Cone[R][i] + MOD - Cone[L - 1][i]) * x % MOD;
    return ret;
}

const int Bino[6][6] = 
{1, 0, 0, 0, 0, 0,
 1, 1, 0, 0, 0, 0,
 1, 2, 1, 0, 0, 0,
 1, 3, 3, 1, 0, 0,
 1, 4, 6, 4, 1, 0,
 1, 5,10,10, 5, 1};
 
Interval& operator >>= (Interval &lhs, i64 rhs)
{
    for (int i = 5; i; i--)
        {
            i64 lv = 1, nv = 0;
            for (int j = i; j >= 0; j--)
                {
                    nv = (nv + (lv * Bino[i][j] % MOD) * lhs.S[j]) % MOD;
                    lv = (lv * rhs) % MOD;
                }
            lhs.S[i] = nv;
        }
    return lhs; 
}

Interval operator >> (Interval lhs, i64 rhs)
{
    return (lhs >>= rhs);
}

Interval& operator += (Interval &lhs, Interval rhs)
{
    int i;
    fortodo(i, 0, 5)
        lhs.S[i] = (lhs.S[i] + rhs.S[i]) % MOD;
    return lhs;
}

Interval operator + (Interval lhs, Interval rhs)
{
    return (lhs += rhs);
}

struct SEG
{
    int mask, L, R;
    Interval v;
    SEG* s[2];
    SEG()
    {
        s[0] = s[1] = NULL;
        mask = -1;
        v = Interval(0);
    }
    Interval interval()
    {
        if (mask == -1)
            return v;
        else
            return sumSame(L, R, mask);
    }
};

int N, M, A[100010];

SEG* init(int L, int R)
{
    SEG* ret = new SEG;
    ret->L = L; ret->R = R;
    if (L == R)
        ret->v = sumSame(L, L, A[L]);
    else
        {
            int Mid = (L + R) / 2;
            ret->s[0] = init(L, Mid);
            ret->s[1] = init(Mid + 1, R);
            ret->v = ret->s[0]->v + ret->s[1]->v;
        }
    //printf("[%d~%d] ", L, R);
    //for (int i = 0; i <= 5; i++) printf("%d%s", int(ret->v.S[i]), (i == 5) ? "\n" : " ");
    return ret;
}

void inhr(SEG* cur)
{
    if (cur->mask == -1) return;
    if (cur->s[0] == NULL) return;
    cur->s[0]->mask = cur->s[1]->mask = cur->mask;
    cur->v = cur->s[0]->interval() + cur->s[1]->interval();
    cur->mask = -1;
}

void modify(SEG* cur, int L, int R, int l, int r, int v)
{
    if ((L == l) && (R == r))
        {
            cur->mask = v;
            return;
        }
    inhr(cur);
    int Mid = (L + R) / 2;
    if (r <= Mid) modify(cur->s[0], L, Mid, l, r, v);
    if (l > Mid) modify(cur->s[1], Mid + 1, R, l, r, v);
    if ((l <= Mid) && (r > Mid))
        {
            modify(cur->s[0], L, Mid, l, Mid, v);
            modify(cur->s[1], Mid + 1, R, Mid + 1, r, v);
        }
    cur->v = cur->s[0]->interval() + cur->s[1]->interval();
}

Interval query(SEG* cur, int L, int R, int l, int r)
{
    if ((L == l) && (R == r))
        return cur->interval();
    inhr(cur);
    int Mid = (L + R) / 2;
    if (r <= Mid)   
        return query(cur->s[0], L, Mid, l, r);
    if (l > Mid)
        return query(cur->s[1], Mid + 1, R, l, r);
    return query(cur->s[0], L, Mid, l, Mid) + query(cur->s[1], Mid + 1, R, Mid + 1, r);
}

SEG* seg;

int main()
{
    init_cone();
    scanf("%d%d", &N, &M);
    int i;
    fortodo(i, 1, N) scanf("%d", &A[i]);
    seg = init(1, N);
    for (; M; M--)
        {
            char ch[5];
            int u, v, w;
            scanf("%s%d%d%d", ch, &u, &v, &w);
            if (ch[0] == '=')
                modify(seg, 1, N, u, v, w);
            else
                printf("%d\n", int((query(seg, 1, N, u, v) >> (MOD - u + 1)).S[w]));                
        }
}