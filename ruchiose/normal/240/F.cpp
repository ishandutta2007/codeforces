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

#include<vector>

const int MAXN = 100010;

int N, Q;
int A0[MAXN];

struct SEG
{
    SEG *s[2];
    int Mask, Sz;
    int Count[26];
    SEG()
    {
        s[0] = s[1] = NULL;
        Mask = -1;
        int i;
        fortodo(i, 0, 25) Count[i] = 0;
    }
};

void recalc(SEG* cur)
{
    int c;
    fortodo(c, 0, 25) cur->Count[c] = 0;
    if (cur->s[0]->Mask >= 0)
        cur->Count[cur->s[0]->Mask] += cur->s[0]->Sz;
    else
        fortodo(c, 0, 25) cur->Count[c] += cur->s[0]->Count[c];
    if (cur->s[1]->Mask >= 0)
        cur->Count[cur->s[1]->Mask] += cur->s[1]->Sz;
    else
        fortodo(c, 0, 25) cur->Count[c] += cur->s[1]->Count[c];
}

SEG* emp(int L, int R)
{
    SEG* ret = new SEG;
    ret->Sz = R - L + 1;
    if (L == R)
        ret->Mask = A0[L];
    else
        {
            int Mid = (L + R) / 2;
            ret->s[0] = emp(L, Mid);
            ret->s[1] = emp(Mid + 1, R);
            recalc(ret);
        }
    return ret;
}

void inhr(SEG* cur)
{
    if (cur->Mask == -1) return;
    if (cur->Sz == 1) return;
    cur->s[0]->Mask = cur->s[1]->Mask = cur->Mask;
    int i;
    fortodo(i, 0, 25) cur->Count[i] = 0;
    cur->Count[cur->Mask] = cur->Sz;
    cur->Mask = -1;
}

void modify(SEG* cur, int L, int R, int l, int r, int c)
{
    if ((L == l) && (R == r))
        {
            cur->Mask = c;
            return;
        }
    inhr(cur);
    int Mid = (L + R) / 2;
    if (r <= Mid) modify(cur->s[0], L, Mid, l, r, c);
    if (l >  Mid) modify(cur->s[1], Mid + 1, R, l, r, c);
    if ((l <= Mid) && (r > Mid))
        {
            modify(cur->s[0], L, Mid, l, Mid, c);
            modify(cur->s[1], Mid + 1, R, Mid + 1, r, c);
        }
    recalc(cur);
}

void Query(SEG* cur, int L, int R, int l, int r, int* d)
{
    if (cur->Mask >= 0)
        {
            d[cur->Mask] += r - l + 1;
            return;
        }
    if ((L == l) && (R == r))
        {
            int i;
            fortodo(i, 0, 25) d[i] += cur->Count[i];
            return;
        }
    int Mid = (L + R) / 2;
    if (r <= Mid) Query(cur->s[0], L, Mid, l, r, d);
    if (l >  Mid) Query(cur->s[1], Mid + 1, R, l, r, d);
    if ((l <= Mid) && (r > Mid))
        {
            Query(cur->s[0], L, Mid, l, Mid, d);
            Query(cur->s[1], Mid + 1, R, Mid + 1, r, d);
        }
}

SEG* seg;

void travel(SEG* cur)
{
    inhr(cur);
    if (cur->Sz == 1)
        putchar('a' + cur->Mask);
    else
        {
            travel(cur->s[0]);
            travel(cur->s[1]);
        }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d", &N, &Q);
    int i, q;
    static char ch[100010];
    scanf("%s", ch + 1);
    fortodo(i, 1, N) A0[i] = ch[i] - 'a';
    seg = emp(1, N);
    fortodo(q, 1, Q)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            int d[25];
            fortodo(i, 0, 25) d[i] = 0;
            Query(seg, 1, N, l, r, d);
            int cntodd = 0;
            fortodo(i, 0, 25) cntodd += d[i] & 1;
            if (cntodd > 1) continue;
            if (cntodd == 1)
                {
                    int mid = (l + r) / 2;
                    fortodo(i, 0, 25)
                        if (d[i] & 1)
                            modify(seg, 1, N, mid, mid, i);
                }
            fortodo(i, 0, 25)
                if (d[i] > 1)
                    {
                        l += d[i] / 2;
                        modify(seg, 1, N, l - d[i] / 2, l - 1, i);
                        r -= d[i] / 2;
                        modify(seg, 1, N, r + 1, r + d[i] / 2, i);
                    }
        }
    travel(seg);
    puts("");
}