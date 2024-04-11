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

int i, j, k, N;
int T[3][3], W[3][3];
i64 DP[41][3][3];

int main()
{
    fortodo(i, 0, 2)
        fortodo(j, 0, 2)
            scanf("%d", &T[i][j]);
    fortodo(i, 0, 2)
        fortodo(j, 0, 2)
            DP[0][i][j] = 0;
    scanf("%d", &N);
    int s;
    fortodo(k, 1, N)
        fortodo(i, 0, 2)
            fortodo(j, 0, 2)
                if (i != j)
                    {
                        s = 3 ^ i ^ j;
                        DP[k][i][j] = min(DP[k - 1][i][s] + T[i][j] + DP[k - 1][s][j],
                                          DP[k - 1][i][j] + T[i][s] + DP[k - 1][j][i] + T[s][j] + DP[k - 1][i][j]);
                    }
    cout << DP[N][0][2] << endl;
}