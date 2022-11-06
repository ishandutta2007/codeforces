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

struct SEG
{
    SEG *s[2];
    i64 Max, Sum;
    SEG()
    {
        s[0] = s[1] = NULL;
    }
};

const int MAXN = 100010;

int N, M, A[MAXN];
SEG* root;

void emp(SEG* &cur, int L, int R)
{
    cur = new SEG;
    if (L == R)
        cur->Max = cur->Sum = A[L];
    else
        {
            int Mid = (L + R) / 2;
            emp(cur->s[0], L, Mid);
            emp(cur->s[1], Mid + 1, R);
            cur->Max = max(cur->s[0]->Max, cur->s[1]->Max);
            cur->Sum = cur->s[0]->Sum + cur->s[1]->Sum;
        }
}

void modify(SEG* cur, int L, int R, int B, int v)
{
    if (L == R)
        cur->Max = cur->Sum = v;
    else
        {
            int Mid = (L + R) / 2;
            if (B <= Mid)
                modify(cur->s[0], L, Mid, B, v);
            else
                modify(cur->s[1], Mid + 1, R, B, v);
            cur->Max = max(cur->s[0]->Max, cur->s[1]->Max);
            cur->Sum = cur->s[0]->Sum + cur->s[1]->Sum;
        } 
}

void MO(SEG* cur, int L, int R, int l, int r, int x)
{
    if (cur->Max < x) return;
    if (L == R)
        cur->Max = cur->Sum = cur->Sum % x;
    else
        {
            int Mid = (L + R) / 2;
            if (r <= Mid)
                MO(cur->s[0], L, Mid, l, r, x);
            if (l >  Mid)
                MO(cur->s[1], Mid + 1, R, l, r, x);
            if ((l <= Mid) && (r > Mid))
                {
                    MO(cur->s[0], L, Mid, l, Mid, x);
                    MO(cur->s[1], Mid + 1, R, Mid + 1, r, x);
                }
            cur->Max = max(cur->s[0]->Max, cur->s[1]->Max);
            cur->Sum = cur->s[0]->Sum + cur->s[1]->Sum;
        }
}

i64 Qry(SEG* cur, int L, int R, int l, int r)
{
    if ((L == l) && (R == r))
        return cur->Sum;
    else
        {
            int Mid = (L + R) / 2;
            if (r <= Mid)
                return Qry(cur->s[0], L, Mid, l, r);
            if (l >  Mid)
                return Qry(cur->s[1], Mid + 1, R, l, r);
            return Qry(cur->s[0], L, Mid, l, Mid) + Qry(cur->s[1], Mid + 1, R, Mid + 1, r);
        }
}

int main()
{
    scanf("%d%d", &N, &M);
    int i;
    fortodo(i, 1, N) scanf("%d", &A[i]);
    emp(root, 1, N);
    fortodo(i, 1, M)
        {
            int o, x, y, z;
            scanf("%d", &o);
            if (o == 1)
                {
                    scanf("%d%d", &x, &y);
                    printf("%I64d\n", Qry(root, 1, N, x, y));
                }
            if (o == 2)
                {
                    scanf("%d%d%d", &x, &y, &z);
                    MO(root, 1, N, x, y, z);
                }
            if (o == 3)
                {
                    scanf("%d%d", &x, &y);
                    modify(root, 1, N, x, y);
                }
        }
}