// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
#define i64 long long
#define d64 long double
#define mp make_pair
using namespace std;

const i64 MOD = 1000000007;

i64 Qipow(i64 B, i64 T)
{
    i64 A = 1;
    for (; T; T >>= 1)
        {
            if (T & 1) A = (A * B) % MOD;
            B = (B * B) % MOD;
        }
    return A;
}

i64 Inv(i64 Q)
{
    return Qipow(Q + MOD, MOD - 2);
}

int N, M, i, j, A[100001];
i64 Factorial[100310];
i64 Difference[100010][102];
i64 Invfact[100310];

void Getfactorial()
{
    Factorial[0] = Invfact[0] = 1;
    int i;
    fortodo(i, 1, N + 300)
        {
            Factorial[i] = (Factorial[i - 1] * i) % MOD;
            Invfact[i] = Inv(Factorial[i]);
        }
}

i64 Combination(int N, int M)
{
    return (((Factorial[N] * Invfact[M]) % MOD) * Invfact[N - M]) % MOD;
}

void Operate(int L, int R, int K)
{
    Difference[L][K + 1] += 1;
    if (Difference[L][K + 1] >= MOD) 
        Difference[L][K + 1] -= MOD;
    int i;
    if (R != N)
        fortodo(i, 0, K)
            {
                Difference[R + 1][K - i + 1] += MOD - Combination(R - L + i, i);
                Difference[R + 1][K - i + 1] %= MOD;
            }
}

int Li, Ri, Ki;

int main()
{
    scanf("%d%d", &N, &M);
    Getfactorial();
    fortodo(i, 1, N)
        fortodo(j, 1, 101)
            Difference[i][j] = 0;
    fortodo(i, 1, N) scanf("%d", &A[i]);
    fortodo(i, 1, M)
        {
            scanf("%d%d%d", &Li, &Ri, &Ki);
            Operate(Li, Ri, Ki);
        }
    for (i = 101; i; i--)
        fortodo(j, 1, N)
            {
                if (j > 1)
                    Difference[j][i] += Difference[j - 1][i];
                if (i < 101)
                    Difference[j][i] += Difference[j][i + 1];
                Difference[j][i] %= MOD;
            }
    fortodo(i, 1, N)
        cout << (A[i] + Difference[i][1]) % MOD << ((i == N) ? "\n" : " ");
    return 0;
}