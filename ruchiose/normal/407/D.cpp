#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, M, i, j, k, s, A[401][401];
int Alp[401];
int DP[2][401][401], p;
int S[160001], Rn;

void Insert(int x)
{
    if (S[x]) Rn++;
    S[x]++;
}

void Remove(int x)
{
    S[x]--;
    if (S[x]) Rn--;
}

void Setalp(int i, int j)
{
    int k;
    p = 1;
    fortodo(k, 1, M)
        {
            Insert(A[i][k]);
            Insert(A[j][k]);
            while (Rn)
                {
                    Alp[p] = k - 1;
                    Remove(A[i][p]);
                    Remove(A[j][p]);
                    p++;
                }
        }
    while (p <= M)
        {
            Alp[p] = M;
            Remove(A[i][p]);
            Remove(A[j][p]);
            p++;
        }
}

int main()
{
    scanf("%d%d", &N, &M);
    fortodo(i, 1, N)
        fortodo(j, 1, M)
            scanf("%d", &A[i][j]);
    fortodo(i, 1, 160000) S[i] = 0; Rn = 0;
    int ANS = 0;
    fortodo(i, 1, N)
        {
            p = 1;
            fortodo(k, 1, M)
                {
                    Insert(A[i][k]);
                    while (Rn)
                        {
                            DP[0][i][p] = k - 1;
                            ANS = max(ANS, k - 1 - p + 1);
                            Remove(A[i][p]);
                            p++;
                        }
                }
            while (p <= M)
                {
                    DP[0][i][p] = M;
                    ANS = max(ANS, M - p + 1);
                    Remove(A[i][p]);
                    p++;
                }
        }
    fortodo(s, 2, N)
        {
            fortodo(i, 1, N + 1 - s)
                {
                    j = i + s - 1;
                    Setalp(i, j);
                    fortodo(k, 1, M)
                        {
                            DP[1][i][k] = min(Alp[k], min(DP[0][i][k], DP[0][i + 1][k]));
                            ANS = max(ANS, s * (DP[1][i][k] - k + 1));
                        }
                }
            fortodo(i, 1, N + 1 - s)
                fortodo(k, 1, M)
                    DP[0][i][k] = DP[1][i][k];
        }
    printf("%d\n", ANS);
}