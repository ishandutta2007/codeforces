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

int N, D, K;
int sch[1010][1010];

int main()
{
    scanf("%d%d%d", &N, &K, &D);
    int n = N - 1;
    for (int i = D; i; i--) n /= K;
    if (n)
        printf("-1\n");
    else
        {
            int i, j;
            fortodo(i, 1, D) sch[1][i] = 1;
            fortodo(i, 2, N)
                {
                    fortodo(j, 1, D) sch[i][j] = sch[i - 1][j];
                    sch[i][1]++;
                    for (int k = 1; sch[i][k] > K; k++)
                        {
                            sch[i][k] -= K;
                            sch[i][k + 1]++;
                        }
                }
            fortodo(i, 1, D)
                fortodo(j, 1, N)
                    printf("%d%s", sch[j][i], (j == N) ? "\n" : " ");
        }
}