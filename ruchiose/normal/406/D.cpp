#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, M, i, j, Ai, Bi;
i64 X[100010], Y[100010];
int L, R;

int Ance[100010][18], Dep[100010];
int H[100010]; 

int Shade(int L, int M, int R)
{
    i64 DxM = X[M] - X[L]; i64 DyM = Y[M] - Y[L];
    i64 DxR = X[R] - X[L]; i64 DyR = Y[R] - Y[L];
    i64 EL = DxR * DyM; i64 ER = DxM * DyR;
    if (EL == ER) 
        return 0;
    else
        return (EL > ER) ? 1 : -1; // 1:  
}

int LCA(int x, int y)
{
    int Lyr;
    if (Dep[x] < Dep[y]) swap(x, y);
    for (Lyr = 17; Lyr >= 0; Lyr--)
        if ((1 << Lyr) <= (Dep[x] - Dep[y]))
            x = Ance[x][Lyr];
    if (x == y) return x;
    for (Lyr = 17; Lyr >= 0; Lyr--)
        if (Ance[x][Lyr] != Ance[y][Lyr])
            {
                x = Ance[x][Lyr];
                y = Ance[y][Lyr];
            }
    return Ance[x][0];
}

void Claim(int i, int F)
{
    int j;
    Ance[i][0] = F; Dep[i] = Dep[F] + 1;
    fortodo(j, 1, 17) Ance[i][j] = Ance[Ance[i][j - 1]][j - 1];
}

int main()
{
    scanf("%d", &N);
    fortodo(i, 1, N) scanf("%I64d%I64d", &X[i], &Y[i]);
    fortodo(i, 0, 17) Ance[N][i] = N; Dep[N] = 0;
    H[0] = 1; H[1] = N;
    for (i = N - 1; i; i--)
        {
            if ((H[0] == 1) || (Shade(i, H[2], H[1]) < 0))
                Claim(i, H[1]);
            else
                {
                    L = 1; R = H[0]; // L: , R: 
                    while (R - L > 1)
                        {
                            int Mid = (L + R) / 2;
                            if (Shade(i, H[Mid + 1], H[Mid]) >= 0)
                                L = Mid;
                            else
                                R = Mid;
                        } 
                    Claim(i, H[R]);
                }
            while ((H[0] > 1) && (Shade(i, H[H[0] - 1], H[H[0]]) >= 0)) H[0]--;
            H[++H[0]] = i;
        }
    scanf("%d", &M);
    fortodo(i, 1, M)
        {
            scanf("%d%d", &Ai, &Bi);
            printf("%d%s", LCA(Ai, Bi), (i == M) ? "\n" : " ");
        }
}