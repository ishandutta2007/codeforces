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

int N, n;
int A[33][33];

int main()
{
    scanf("%d", &N); n = (N - 1) / 2;
    int i, j, f;
    fortodo(i, 0, N - 1)
        fortodo(j, 0, N - 1)
            scanf("%d", &A[i][j]);
    int F = (2 << n);
    int ans = -(1 << 30);
    fortodo(f, 0, F - 1)
        {
            int s = (f >> n) ? -A[n][n] : A[n][n];
            fortodo(i, 0, n - 1)
                {
                    s += ((f >> i) & 1) ? -A[i][n] : A[i][n];
                    s += (((f >> i) & 1) ^ (f >> n)) ? -A[i + n + 1][n] : A[i + n + 1][n];
                }
            //printf("primi s = %d\n", s);
            fortodo(i, 0, n - 1)
                {
                    int c[2];
                    c[0] = A[n][i] + ((f >> n) ? -A[n][n + 1 + i] : A[n][n + 1 + i]);
                    c[1] = -c[0];
                    //printf("<%d,%d>\n", c[0], c[1]);
                    fortodo(j, 0, n - 1)
                        {
                            c[0] += abs(A[j][i] + A[j + n + 1][i] + (((f >> j) & 1) ? -1 : 1) * (A[j][i + n + 1] + ((f >> n) ? -A[j + n + 1][i + n + 1] : A[j + n + 1][i + n + 1])));
                            c[1] += abs(A[j][i] - A[j + n + 1][i] + (((f >> j) & 1) ? -1 : 1) * (A[j][i + n + 1] + ((f >> n) ? A[j + n + 1][i + n + 1] : -A[j + n + 1][i + n + 1])));
                            /*printf("delta = abs(%d - %d + %d * (%d + %d))\n", 
                                A[j][i], A[j + n + 1][i], ((f >> j) & 1) ? -1 : 1,
                                A[j + n + 1][i],
                                ((f >> n) ? A[j + n + 1][i + n + 1] : -A[j + n + 1][i + n + 1]));
                            printf("=> <%d,%d>\n", c[0], c[1]);*/
                        }
                    //printf(" += max(%d, %d)\n", c[0], c[1]);
                    s += max(c[0], c[1]);
                }
            //printf("f->s = %d->%d\n", f, s);
            ans = max(ans, s);
        }
    printf("%d\n", ans);
}