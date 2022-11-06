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
const int MAXNUM = MAXN << 6;

int N, NUM;
i64 A[MAXNUM], Xorsum;
int Copn[MAXNUM][2], Pick[MAXNUM];

int IDX[MAXN];

vector<int> PRSSORD;

vector<int> Gauss()
{
    int i;
    vector<int> REPR;
    REPR.clear();
    REPR.push_back(0);
    fortodo(i, 1, N) IDX[i] = i;
    for (vector<int>::iterator it = PRSSORD.begin(); it != PRSSORD.end(); it++)
        {
            fortodo(i, REPR.size(), N)
                if (A[IDX[i]] & (1LL << *it))
                    break;
            if (i > N) continue;
            swap(IDX[REPR.size()], IDX[i]);
            fortodo(i, REPR.size() + 1, N)
                if (A[IDX[i]] & (1LL << *it))
                    {
                        NUM++;
                        A[NUM] = A[IDX[i]] ^ A[IDX[REPR.size()]];
                        Copn[NUM][0] = IDX[i];
                        Copn[NUM][1] = IDX[REPR.size()];
                        IDX[i] = NUM;
                    }
            REPR.push_back(*it);
        }
    return REPR;
}

int main()
{
    scanf("%d", &N); NUM = N;
    int i;
    fortodo(i, 1, N) scanf("%I64d", &A[i]);
    Xorsum = 0;
    fortodo(i, 1, N) Xorsum ^= A[i];
    PRSSORD.clear();
    for (i = 59; i >= 0; i--)
        if (((Xorsum >> i) & 1) == 0)
            PRSSORD.push_back(i);
    for (i = 59; i >= 0; i--)
        if ((Xorsum >> i) & 1)
            PRSSORD.push_back(i);
    vector<int> REPR = Gauss();
    fortodo(i, 1, NUM) Pick[i] = 0;
    i64 HAHA = 0;
    fortodo(i, 1, REPR.size() - 1)
        if (((HAHA ^ Xorsum) & (1LL << REPR[i])) == 0)
            {
                HAHA ^= A[IDX[i]];
                Pick[IDX[i]] ^= 1;
            }
    for (i = NUM; i > N; i--)
        {
            Pick[Copn[i][0]] ^= Pick[i];
            Pick[Copn[i][1]] ^= Pick[i];
            Pick[i] = 0;
        }
    fortodo(i, 1, N)
        printf("%d%s", 2 - Pick[i], (i == N) ? "\n" : " ");
}