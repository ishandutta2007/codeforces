#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, M, i, j, V[100001];
int Gap;

i64 ANS;

i64 C3(i64 N)
{
    return (N * (N - 1) * (N - 2)) / 6;
}

i64 C2(i64 N)
{
    return (N * (N - 1)) / 2;
}

i64 Tri(i64 N)
{
    return (N * (N + 1)) / 2;
}

int Cnt0, CntN;
int R0, LN, RN, L0;

i64 Rangecnt(int L, int R)
{
    return upper_bound(V + 1, V + M + 1, R) - lower_bound(V + 1, V + M + 1, L);
}

i64 F(i64 L, i64 M, i64 R)
{
    return L * R + L * M + M * R + C2(M);
}

int main()
{
    scanf("%d%d", &N, &M);
    fortodo(i, 1, M)
        {
            int Si, Fi;
            scanf("%d%d", &Si, &Fi);
            V[i] = (Si + 1) * N - Fi;
        }
    sort(V + 1, V + M + 1);
    Gap = V[1] - V[M] + N * 2;
    fortodo(i, 2, M)
        Gap = max(Gap, V[i] - V[i - 1]);
    if (Gap > N)
        {
            int Pre, Suc, PPre, SSuc, CPre, CSuc;
            if (Gap == V[1] - V[M] + N * 2)
                Pre = M;
            fortodo(i, 2, M)
                if (Gap == V[i] - V[i - 1])
                    Pre = i - 1;
            Suc = Pre % M + 1;
            if (V[Pre] == V[Suc])
                {
                    printf("%I64d\n", C3(M));
                    return 0;
                }
            PPre = Pre; CPre = 0;
            while (V[PPre] == V[Pre])
                {
                    CPre++;
                    PPre--;
                    if (PPre == 0) PPre = M;
                }
            SSuc = Suc; CSuc = 0;
            while (V[SSuc] == V[Suc])
                {
                    CSuc++;
                    SSuc++;
                    if (SSuc > M) SSuc = 1;
                }
            printf("%I64d\n", (i64)CPre * (i64)CSuc * M - Tri(CPre) * CSuc - Tri(CSuc) * CPre);
            return 0;
        }
    Cnt0 = CntN = 0;
    fortodo(i, 1, M)
        {
            if (V[i] == 0) Cnt0++;
            if (V[i] == N) CntN++;
        }
    ANS = (i64)Cnt0 * (i64)CntN * M - Tri(Cnt0) * CntN - Tri(CntN) * Cnt0;
    R0 = upper_bound(V + 1, V + M + 1, 0) - V;
    LN = lower_bound(V + 1, V + M + 1, N) - V - 1;
    RN = upper_bound(V + 1, V + M + 1, N) - V;
    L0 = M;
    int p = RN - 1;
    fortodo(i, R0, LN)
        {
            while ((p < L0) && (V[p + 1] <= N + V[i])) p++;
            ANS += (i64)Cnt0 * (p - RN + 1);
        }
    p = R0 - 1;
    fortodo(i, RN, L0)
        {
            while ((p < LN) && (V[p + 1] <= V[i] - N)) p++;
            ANS += (i64)CntN * (p - R0 + 1);
        }
    fortodo(i, R0, LN)
        ANS += F(Rangecnt(N + 1, V[i] + N - 1), Rangecnt(V[i] + N, V[i] + N), Rangecnt(V[i] + N + 1, 2 * N - 1));
    fortodo(i, RN, L0)
        ANS += F(Rangecnt(1, V[i] - N - 1), Rangecnt(V[i] - N, V[i] - N), Rangecnt(V[i] - N + 1, N - 1));
    cout << ANS << endl;
}