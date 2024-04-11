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

int N, M, K;

int A[15][15];
int W[15], C[15];

const int MOD = int(1e+9) + 7;

int dfs(int i, int j)
{
    if (j > M)
        {
            i++;
            j = 1;
        }
    if (i > N) return 1;
    int raw_Wj = W[j];
    W[j] |= W[j - 1];
    int ret = 0, k;
    int newColor = -1;
    int Field = ((2 << K) - 2) ^ W[j];
    if (A[i][j]) Field &= 1 << A[i][j];
    for (; Field; Field ^= (Field & -Field))
        {
            k = __builtin_ctz(Field);
            W[j] ^= 1 << k;
            C[k]++;
            if (C[k] == 1)
                {
                    if (newColor == -1) newColor = dfs(i, j + 1);
                    ret += newColor;
                }
            else
                ret += dfs(i, j + 1);
            if (ret >= MOD) ret -= MOD;
            C[k]--;
            W[j] ^= 1 << k;
        }
    W[j] = raw_Wj;
    return ret;
}

int main()
{
    scanf("%d%d%d", &N, &M, &K);
    if (N + M > K + 1)
        {
            printf("0\n");
            return 0;
        }
    int i, j;
    fortodo(i, 1, N)
        fortodo(j, 1, M)
            scanf("%d", &A[i][j]);
    fortodo(i, 0, M) W[i] = 0;
    fortodo(i, 1, K) C[i] = 0;
    fortodo(i, 1, N)
        fortodo(j, 1, M)
            if (A[i][j])
                C[A[i][j]]++;
    printf("%d\n", dfs(1, 1)); 
}