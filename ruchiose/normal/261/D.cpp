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

int K, N, MAXB, T, A[100010], dtc[100010];

int main()
{
    scanf("%d%d%d%d", &K, &N, &MAXB, &T);
    if (T > MAXB) T = MAXB;
    int SEQ = N * T;
    for (int k = K; k; k--)
        {
            int i;
            fortodo(i, 1, N) scanf("%d", &A[i]);
            fortodo(i, 1, MAXB + 1) dtc[i] = 0;
            fortodo(i, 1, SEQ)
                {
                    int Key = A[(i - 1) % N + 1];
                    int Value = dtc[Key] + 1;
                    for (int j = Key + 1; (j <= MAXB + 1) && (dtc[j] < Value); j++)
                        dtc[j] = Value;
                }
            printf("%d\n", dtc[MAXB + 1]);
        }
}