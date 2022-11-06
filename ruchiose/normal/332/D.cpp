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

int N, K, cntEdge[2010];
i64 sumEdge[2010];

int main()
{
    scanf("%d%d", &N, &K);
    int i, j;
    fortodo(i, 1, N) sumEdge[i] = cntEdge[i] = 0;
    fortodo(i, 1, N)
        fortodo(j, i + 1, N)
            {
                int u;
                scanf("%d", &u);
                if (u != -1)
                    {
                        sumEdge[i] += u;
                        sumEdge[j] += u;
                        cntEdge[i]++;
                        cntEdge[j]++;
                    }
            }
    if (K != 2)
        {
            i64 sumSumEdge = 0;
            fortodo(i, 1, N) sumSumEdge += sumEdge[i];
            cout << sumSumEdge / N << endl;
        }
    else
        {
            i64 sumWeightedSumEdge = 0;
            fortodo(i, 1, N) sumWeightedSumEdge += sumEdge[i] * (cntEdge[i] - 1);
            cout << sumWeightedSumEdge / (N * (N - 1) / 2) << endl;
        }
}