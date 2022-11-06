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
const int MAXV = 100000;
const int MAXQ = 100010;

struct Query
{
    int l, r;
    int id;
};

bool cmp_pl(Query a, Query b)
{
    return a.l < b.l;
}

bool cmp_praz(Query a, Query b)
{
    return a.r < b.r;
}

bool cmp_prza(Query a, Query b)
{
    return a.r > b.r;
}

#include<vector>

int N, M, A[MAXN];
vector<int> D[MAXV+1];
int legalRPos[MAXN];
Query Qs[MAXQ];

#include<deque>
deque<int> Deck[MAXV+1];
int countColor, countArith;

#define NZ(x) ((x) ? 1 : 0) 

void attach(int idx)
{
    countColor -= NZ(Deck[A[idx]].size());
    if (Deck[A[idx]].size())
        countArith -= NZ(legalRPos[Deck[A[idx]].front()] >= Deck[A[idx]].back());
    if (Deck[A[idx]].size())
        if (Deck[A[idx]].back() < idx)
            Deck[A[idx]].push_back(idx);
        else
            Deck[A[idx]].push_front(idx);
    else
        Deck[A[idx]].push_back(idx);
    countColor += NZ(Deck[A[idx]].size());
    if (Deck[A[idx]].size())
        countArith += NZ(legalRPos[Deck[A[idx]].front()] >= Deck[A[idx]].back());
}

void deattach(int idx)
{
    countColor -= NZ(Deck[A[idx]].size());
    if (Deck[A[idx]].size())
        countArith -= NZ(legalRPos[Deck[A[idx]].front()] >= Deck[A[idx]].back());
    if (Deck[A[idx]].front() == idx)
        Deck[A[idx]].pop_front();
    else
        Deck[A[idx]].pop_back();
    countColor += NZ(Deck[A[idx]].size());
    if (Deck[A[idx]].size())
        countArith += NZ(legalRPos[Deck[A[idx]].front()] >= Deck[A[idx]].back());
}

void repos(Query x, Query y)
{
    while (x.r < y.r) attach(++x.r);
    while (x.l > y.l) attach(--x.l);
    while (x.r > y.r) deattach(x.r--);
    while (x.l < y.l) deattach(x.l++);
}

void requeries()
{
    int B = int(sqrt(M) + 0.233333);
    sort(Qs + 1, Qs + M + 1, cmp_pl);
    int xs, xe;
    bool Flag = false;
    for (xs = 1; xs <= M; xs += B)
        {
            xe = min(xs + B, M + 1);
            if (Flag ^= true)
                sort(Qs + xs, Qs + xe, cmp_praz);
            else
                sort(Qs + xs, Qs + xe, cmp_prza);
        }
}

int RET[MAXQ];

int main()
{
    scanf("%d", &N);
    int i, j;
    fortodo(i, 1, N) scanf("%d", &A[i]);
    scanf("%d", &M);
    fortodo(i, 1, M)
        {
            Qs[i].id = i;
            scanf("%d%d", &Qs[i].l, &Qs[i].r);
        }
    fortodo(i, 1, MAXV) D[i].clear();
    fortodo(i, 1, N)
        D[A[i]].push_back(i);
    fortodo(i, 1, MAXV)
        if (D[i].size())
            {
                int Sz = D[i].size(), rPointer = 0;
                fortodo(j, 0, Sz - 1)
                    {
                        while ((rPointer < Sz - 1) && ((rPointer == j) || (D[i][rPointer + 1] - D[i][rPointer] == D[i][rPointer] - D[i][rPointer - 1])))
                            rPointer++; 
                        legalRPos[D[i][j]] = D[i][rPointer];
                    }
            }
    fortodo(i, 1, MAXV) Deck[i].clear();
    countColor = countArith = 0;
    requeries();
    Qs[0].l = 1; Qs[0].r = 0;
    fortodo(i, 1, M)
        {
            repos(Qs[i - 1], Qs[i]);
            RET[Qs[i].id] = countColor + ((countArith) ? 0 : 1);
        }
    fortodo(i, 1, M) printf("%d\n", RET[i]);
}