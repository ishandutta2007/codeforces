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

const i64 MOD = int(1e+9);
const int MAXN = 200000;
const int CNTN = MAXN + 10;

typedef pair<i64,i64> PLL;

i64 Fib[CNTN], pFib[CNTN];

PLL operator >> (PLL lhs, int rhs)
{
    if (rhs == 0) return lhs;
    return make_pair((lhs.first * Fib[rhs - 1] + lhs.second * Fib[rhs]) % MOD,
                     (lhs.first * Fib[rhs] + lhs.second * Fib[rhs + 1]) % MOD);
}

PLL operator + (PLL lhs, PLL rhs)
{
    return make_pair((lhs.first + rhs.first) % MOD, (lhs.second + rhs.second) % MOD);
}

PLL operator * (PLL lhs, i64 rate)
{
    return make_pair(lhs.first * rate % MOD, lhs.second * rate % MOD);
}

PLL osm(int N)
{
    return make_pair(pFib[N - 1], pFib[N]);
}

struct SEG
{
    SEG* s[2];
    int Len, Mask;
    PLL sum;
    SEG()
    {
        s[0] = s[1] = NULL; Mask = 0;
    }
    PLL Sum()
    {
        return sum + (osm(Len) * Mask);
    }
};

int A[CNTN];

SEG* emp(int L, int R)
{
    SEG* ret = new SEG;
    ret->Len = R - L + 1;
    if (L == R)
        ret->sum = osm(1) * A[L];
    else
        {
            int Mid = (L + R) / 2;
            ret->s[0] = emp(L, Mid);
            ret->s[1] = emp(Mid + 1, R);
            ret->sum = ret->s[0]->Sum() + (ret->s[1]->Sum() >> (Mid - L + 1));
        } 
    return ret;
}

void inherit(SEG* cur)
{
    if (cur->Len == 1)
        cur->sum = cur->Sum();
    else
        {
            cur->s[0]->Mask = (cur->s[0]->Mask + cur->Mask) % MOD;
            cur->s[1]->Mask = (cur->s[1]->Mask + cur->Mask) % MOD;
        }
    cur->Mask = 0;
}

void assign(SEG* cur, int L, int R, int B, int v)
{
    inherit(cur);
    if (L == R)
        cur->sum = osm(1) * v;
    else
        {
            int Mid = (L + R) / 2;
            if (B <= Mid)
                assign(cur->s[0], L, Mid, B, v);
            else
                assign(cur->s[1], Mid + 1, R, B, v);
            cur->sum = cur->s[0]->Sum() + (cur->s[1]->Sum() >> (Mid - L + 1));
        }
}

void attach(SEG* cur, int L, int R, int l, int r, int v)
{
    if ((L == l) && (R == r))
        {
            cur->Mask = (cur->Mask + v) % MOD;
            return;
        }
    int Mid = (L + R) / 2;
    if (r <= Mid) attach(cur->s[0], L, Mid, l, r, v);
    if (l >  Mid) attach(cur->s[1], Mid + 1, R, l, r, v);
    if ((l <= Mid) && (r > Mid))
        {
            attach(cur->s[0], L, Mid, l, Mid, v);
            attach(cur->s[1], Mid + 1, R, Mid + 1, r, v);
        }
    cur->sum = cur->s[0]->Sum() + (cur->s[1]->Sum() >> (Mid - L + 1));
}

PLL query(SEG* cur, int L, int R, int l, int r)
{
    if ((L == l) && (R == r))
        return cur->Sum();
    int Mid = (L + R) / 2;
    if (r <= Mid) return query(cur->s[0], L, Mid, l, r) + osm(r - l + 1) * cur->Mask;
    if (l >  Mid) return query(cur->s[1], Mid + 1, R, l, r) + osm(r - l + 1) * cur->Mask;
    return query(cur->s[0], L, Mid, l, Mid) + (query(cur->s[1], Mid + 1, R, Mid + 1, r) >> (Mid - l + 1)) + osm(r - l + 1) * cur->Mask;
}

SEG* seg;

int N, M;

int main()
{
    Fib[0] = 0; Fib[1] = 1;
    int i;
    fortodo(i, 2, MAXN) Fib[i] = (Fib[i - 1] + Fib[i - 2]) % MOD;
    pFib[0] = 0;
    fortodo(i, 1, MAXN) pFib[i] = (pFib[i - 1] + Fib[i]) % MOD;
    scanf("%d%d", &N, &M);
    fortodo(i, 1, N) scanf("%d", &A[i]);
    seg = emp(1, N);
    for (; M; M--)
        {
            int t, u, v, w;
            scanf("%d", &t);
            if (t == 1)
                {
                    scanf("%d%d", &u, &v);
                    assign(seg, 1, N, u, v);
                }
            if (t == 2)
                {
                    scanf("%d%d", &u, &v);
                    printf("%d\n", int(query(seg, 1, N, u, v).second));
                }
            if (t == 3)
                {
                    scanf("%d%d%d", &u, &v, &w);
                    attach(seg, 1, N, u, v, w);
                }
        }
}