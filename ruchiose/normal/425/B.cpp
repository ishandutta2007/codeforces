#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, M, K, F, d, i, j, k, ANS, A[101][101];

int main()
{
    scanf("%d%d%d", &N, &M, &K);
    fortodo(i, 1, N)
        fortodo(j, 1, M)
            scanf("%d", &A[i][j]);
    ANS = 0x3FFFFFFF;
    if (N > K)
        fortodo(i, 1, N)
            {
                int t = 0, x[2];
                fortodo(j, 1, N)
                    {
                        x[0] = x[1] = 0;
                        fortodo(k, 1, M)
                            x[A[i][k] ^ A[j][k]]++;
                        t += min(x[0], x[1]);
                    }
                ANS = min(ANS, t);
            }
    else
        {
            F = (1 << N) - 1;
            fortodo(d, 0, F)
                {
                    fortodo(i, 1, N)
                        A[i][0] = (d >> (i - 1)) & 1;
                    int t = 0, x[2];
                    fortodo(j, 1, M)
                        {
                            x[0] = x[1] = 0;
                            fortodo(k, 1, N)
                                x[A[k][j] ^ A[k][0]]++;
                            t += min(x[0], x[1]);
                        }
                    ANS = min(ANS, t);
                }
        }
    if (ANS <= K)
        printf("%d\n", ANS);
    else
        printf("-1\n");
}