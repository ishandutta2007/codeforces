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
const int BigInt = (1 << 30) - 1;

int N, M;
int L[MAXN], R[MAXN], T[MAXN];
vector<int> Ys;

struct SEG
{
    SEG *s[2];
    int Mask;
    SEG()
    {
        s[0] = s[1] = NULL;
        Mask = BigInt;
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

void modify(SEG* cur, int L, int R, int l, int r, int v)
{
    if ((L == l) && (R == r))
        {
            cur->Mask = min(cur->Mask, v);
            return;
        }
    int Mid = (L + R) / 2;
    if (r <= Mid) modify(cur->s[0], L, Mid, l, r, v);
    if (l >  Mid) modify(cur->s[1], Mid + 1, R, l, r, v);
    if ((l <= Mid) && (r > Mid))
        {
            modify(cur->s[0], L, Mid, l, Mid, v);
            modify(cur->s[1], Mid + 1, R, Mid + 1, r, v);
        }
}

void Harvest(SEG* cur, int L, int R, int oMask, int* targ)
{
    oMask = min(oMask, cur->Mask);
    if (L == R)
        targ[L] = oMask;
    else
        {
            int Mid = (L + R) / 2;
            Harvest(cur->s[0], L, Mid, oMask, targ);
            Harvest(cur->s[1], Mid + 1, R, oMask, targ);
        }
}

SEG* seg;
int earliest[MAXN<<1];

struct Event
{
    int T0, k, b;
    Event() {}
    Event(int T0, int k, int b)
    {
        this->T0 = T0;
        this->k = k;
        this->b = b;
    }
};

bool operator < (Event a, Event b)
{
    return a.T0 < b.T0;
}

Event Events[MAXN<<2];
int Ev0;
int Time[MAXN<<2];
i64 sumK[MAXN<<2], sumB[MAXN<<2];

int main()
{
    scanf("%d%d", &M, &N);
    int i;
    fortodo(i, 1, N)
        scanf("%d%d%d", &L[i], &R[i], &T[i]);
    Ys.clear();
    fortodo(i, 1, N)
        {
            Ys.push_back(L[i]);
            Ys.push_back(R[i]);
        }
    sort(Ys.begin(), Ys.end());
    Ys.resize(unique(Ys.begin(), Ys.end()) - Ys.begin());
    seg = emp(1, Ys.size() - 1);
    fortodo(i, 1, N)
        modify(seg, 1, Ys.size() - 1, upper_bound(Ys.begin(), Ys.end(), L[i]) - Ys.begin(), lower_bound(Ys.begin(), Ys.end(), R[i]) - Ys.begin(), T[i]);
    Harvest(seg, 1, Ys.size() - 1, BigInt, earliest);
    Ev0 = 0;
    fortodo(i, 1, Ys.size() - 1)
        {
            if (earliest[i] == BigInt) continue;
            Events[++Ev0] = Event(earliest[i] - Ys[i], 1, - earliest[i] + Ys[i]);
            Events[++Ev0] = Event(earliest[i] - Ys[i - 1], -1, earliest[i] - Ys[i - 1]);
        }
    sort(Events + 1, Events + Ev0 + 1);
    sumK[0] = sumB[0] = 0;
    fortodo(i, 1, Ev0)
        {
            Time[i] = Events[i].T0;
            sumK[i] = sumK[i - 1] + Events[i].k;
            sumB[i] = sumB[i - 1] + Events[i].b;
        }
    fortodo(i, 1, M)
        {
            int Q;
            scanf("%d", &Q);
            int L = lower_bound(Time + 1, Time + Ev0 + 1, Q) - Time - 1;
            int ans = int(sumK[L] * Q + sumB[L]);
            printf("%d\n", ans);
        }
}