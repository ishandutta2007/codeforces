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

const int MAXN = 1010;
const int MAXM = 1010;

int N, M, K;
int A[MAXN][MAXM];

i64 sx[MAXN][MAXM], sy[MAXN][MAXM], ss[MAXN][MAXM], sd[MAXN][MAXM];
i64 ANS[MAXN][MAXM];

void calcRow(int x, i64 lupart, i64 ldpart, i64 rupart, i64 rdpart)
{
    int y;
    fortodo(y, K + 1, M - K + 1)
        {
            rupart += sd[x][y + K - 1] - sd[x - K][y - 1];
            rdpart += ss[x + K - 1][y] - ss[x][y + K - 1];
            ANS[x][y] = ANS[x][y - 1] + rupart + rdpart - lupart - ldpart;
            lupart -= ss[x][y - K] - ss[x - K][y];
            ldpart -= sd[x + K - 1][y - 1] - sd[x][y - K];
            rupart -= sy[x][y] - sy[x - K][y];
            rdpart -= sy[x + K - 1][y] - sy[x][y];
            lupart += sy[x][y] - sy[x - K][y];
            ldpart += sy[x + K - 1][y] - sy[x][y];
        }
}

int main()
{
    scanf("%d%d%d", &N, &M, &K);
    int i, j;
    fortodo(i, 0, N + 1)
        fortodo(j, 0, M + 1)
            sx[i][j] = sy[i][j] = ss[i][j] = sd[i][j] = A[i][j] = 0;
    fortodo(i, 1, N)
        fortodo(j, 1, M)
            {
                scanf("%d", &A[i][j]);
                sx[i][j] = sx[i][j - 1] + A[i][j];
                sy[i][j] = sy[i - 1][j] + A[i][j];
                ss[i][j] = ss[i - 1][j + 1] + A[i][j];
                sd[i][j] = sd[i - 1][j - 1] + A[i][j];
            }
    fortodo(i, 1, N + 1)
        {
            sd[i][M + 1] = sd[i - 1][M];
            ss[i][0] = ss[i - 1][1];
        }
    fortodo(j, 0, M + 1)
        {
            if (j <= M) ss[N + 1][j] = ss[N][j + 1];
            if (j >= 0) sd[N + 1][j] = sd[N][j - 1];
        }
    ANS[K][K] = 0;
    fortodo(i, 1, K * 2 - 1)
        fortodo(j, 1, K * 2 - 1)
            ANS[K][K] += max(0, K - abs(K - i) - abs(K - j)) * A[i][j];
    i64 LUPart = 0, LDPart = 0, RUPart = 0, RDPart = 0;
    fortodo(i, 1, K)
        fortodo(j, 1, i)
            LUPart += A[i][K + 1 - j];
    fortodo(i, 1, K - 1)
        fortodo(j, 1, i)
            RUPart += A[i + 1][K + j];
    fortodo(i, 1, K - 1)
        fortodo(j, i, K - 1)
            LDPart += A[K + i][j + 1];
    fortodo(i, 1, K - 2)
        fortodo(j, i, K - 2)
            RDPart += A[K + i][K * 2 - 1 - j];
    calcRow(K, LUPart, LDPart, RUPart, RDPart);
    fortodo(i, K + 1, N - K + 1)
        {
            LDPart += sd[K + i - 1][K] - sd[i - 1][0];
            RDPart += ss[K + i - 2][K + 1] - ss[i - 1][K * 2];
            ANS[i][K] = ANS[i - 1][K] - LUPart - RUPart + LDPart + RDPart;
            LUPart -= ss[i - 1][1] - ss[i - K - 1][K + 1];
            RUPart -= sd[i - 1][K * 2 - 1] - sd[i - K][K];
            LDPart -= sx[i][K] - sx[i][0];
            RDPart -= sx[i][K * 2 - 1] - sx[i][K];
            LUPart += sx[i][K] - sx[i][0];
            RUPart += sx[i][K * 2 - 1] - sx[i][K];
            calcRow(i, LUPart, LDPart, RUPart, RDPart);
        }
    int x = K, y = K;
    fortodo(i, K, N - K + 1)
        fortodo(j, K, M - K + 1)
            if (ANS[i][j] > ANS[x][y])
                {
                    x = i;
                    y = j;
                }
    printf("%d %d\n", x, y);
}