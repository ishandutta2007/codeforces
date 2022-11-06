#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, L, A[1048576], i, j, K, q;
int T[1048576];
i64 REV[20], INP[20], ANS;

void Merge(int L, int R, int lyr)
{
    if (lyr < 0) return;
    int Mid = (L + R) / 2;
    Merge(L, Mid, lyr - 1);
    Merge(Mid + 1, R, lyr - 1);
    int pa, pb, pt, id;
    pa = L; pb = Mid + 1;
    i64 Subrev, Subexrev;
    Subexrev = 0;
    fortodo(pt, L, R)
        {
            id = 0;
            if (pb > R) id = -1;
            if (pa > Mid) id = 1;
            if (id == 0) id = (A[pa] < A[pb]) ? -1 : 1;
            if (id == -1)
                {
                    T[pt] = A[pa++];
                    Subexrev += pb - Mid - 1;
                }
            else
                T[pt] = A[pb++];
        }
    Subrev = 0;
    pa = L; pb = Mid + 1;
    fortodo(pt, L, R)
        {
            id = 0;
            if (pb > R) id = -1;
            if (pa > Mid) id = 1;
            if (id == 0) id = (A[pa] <= A[pb]) ? -1 : 1;
            if (id == -1)
                {
                    T[pt] = A[pa++];
                    Subrev += pb - Mid - 1;
                }
            else
                T[pt] = A[pb++];
        }
    REV[lyr] += Subrev;
    INP[lyr] += (1ll << (lyr * 2)) - Subexrev;
    fortodo(pt, L, R) A[pt] = T[pt];
}

int main()
{
    scanf("%d", &N);
    L = 1 << N;
    fortodo(i, 0, L - 1) scanf("%d", &A[i]);
    fortodo(i, 0, N - 1) REV[i] = INP[i] = 0;
    Merge(0, L - 1, N - 1);
    scanf("%d", &K);
    fortodo(i, 1, K)
        {
            scanf("%d", &q);
            fortodo(j, 0, q - 1)
                swap(REV[j], INP[j]);
            ANS = 0;
            fortodo(j, 0, N - 1)
                ANS += REV[j];
            printf("%I64d\n", ANS);
        }
}