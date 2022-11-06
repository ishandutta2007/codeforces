#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
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

i64 Inv(i64 B)
{
    return Qipow(B, MOD - 2);
}

i64 Fact[100010], Invfact[100010];

i64 Comb(int N, int M)
{
    return (((Fact[N] * Invfact[M]) % MOD) * Invfact[N - M]) % MOD;
}

int N, i, j, P[100010], W[100010], Las[2];
i64 L[100010], R[100010];
int DL, DR, dl, dr;

int main()
{
    scanf("%d", &N);
    fortodo(i, 1, N) scanf("%d", &P[i]);
    Fact[0] = Invfact[0] = 1;
    fortodo(i, 1, N)
        {
            Fact[i] = (Fact[i - 1] * i) % MOD;
            Invfact[i] = Inv(Fact[i]);
        }
    fortodo(i, 1, N) W[i] = 0;
    fortodo(i, 1, N)
        if (P[i])
            W[P[i]] = i;
    Las[0] = Las[1] = 0;
    fortodo(i, 1, N)
        if (W[i])
            {
                L[i] = R[i] = 0;
                if (Las[0] == 0)
                    {
                        if (i == 1)
                            {
                                L[i] = 1;
                                R[i] = 0;
                                Las[0] = i;
                                Las[1] = W[i];
                                continue;
                            }
                        if (i <= W[i]) L[i] = Qipow(2, i - 2);
                        if (i <= N + 1 - W[i])
                            R[i] = Qipow(2, i - 2);
                    }
                else
                    {
                        int DT = i - Las[0];
                        // Li : Wi+1-i .. Wi
                        DL = W[i] + 1 - i;
                        DR = W[i];
                        if (DL > 0)
                            {
                                // L->L
                                dl = Las[1] + 1 - Las[0];
                                dr = Las[1];
                                if ((DL <= dl) && (dr < DR))
                                    L[i] += L[Las[0]] * Comb(i - Las[0] - 1, dl - DL);
                                // R->L
                                dl = Las[1];
                                dr = Las[1] + Las[0] - 1;
                                if ((DL <= dl) && (dr < DR))
                                    L[i] += R[Las[0]] * Comb(i - Las[0] - 1, dl - DL);
                                L[i] %= MOD;
                            }
                        // Ri : Wi .. Wi+i-1
                        DL = W[i];
                        DR = W[i] + i - 1;
                        if (DR <= N)
                            {
                                // L->R
                                dl = Las[1] + 1 - Las[0];
                                dr = Las[1];
                                if ((DL < dl) && (dr <= DR))
                                    R[i] += L[Las[0]] * Comb(i - Las[0] - 1, dl - DL - 1);
                                // R->R
                                dl = Las[1];
                                dr = Las[1] + Las[0] - 1;
                                if ((DL < dl) && (dr <= DR))
                                    R[i] += R[Las[0]] * Comb(i - Las[0] - 1, dl - DL - 1);
                                R[i] %= MOD;
                            }
                    }
                Las[0] = i;
                Las[1] = W[i];
            }
    //fortodo(i, 1, N)
    //  printf("ANS = %I64d, %I64d\n", L[i], R[i]);
    if (Las[0] == 0)
        printf("%I64d\n", Qipow(2, N - 1));
    else
        {
            i64 ANS = 0;
            DL = Las[1] - Las[0] + 1;
            DR = Las[0];
            if (DL >= 1) ANS += L[Las[0]] * Comb(N - Las[0], DL - 1);
            DL = Las[0];
            DR = Las[1] + Las[0] - 1;
            if (DR <= N) ANS += R[Las[0]] * Comb(N - Las[0], N - DR);
            printf("%I64d\n", ANS % MOD);
        }
}