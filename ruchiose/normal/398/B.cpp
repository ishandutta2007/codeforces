#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
#define i64 long long
#define d64 long double
using namespace std;

int N, M, i, j, u, v, r, c;
bool R[2001], C[2001];
d64 Cost[2001][2001];

#define p(x) (d64)(N - x) / N
#define q(x) (d64)x / N

int main()
{
    scanf("%d%d", &N, &M);
    fortodo(i, 1, N) R[i] = C[i] = false;
    fortodo(i, 1, M)
        {
            scanf("%d%d", &u, &v);
            R[u] = C[v] = true;
        }
    r = 0; fortodo(i, 1, N) if (R[i]) r++;
    c = 0; fortodo(i, 1, N) if (C[i]) c++;
    Cost[N][N] = 0;
    for (i = N; i >= r; i--)
        for (j = N; j >= c; j--)
            {
                if ((i == N) && (j == N)) continue;
                if (i == N) Cost[i][j] = Cost[i][j + 1] + (d64)N / (N - j);
                if (j == N) Cost[i][j] = Cost[i + 1][j] + (d64)N / (N - i);
                if ((i != N) && (j != N))
                    Cost[i][j] = (1 + p(i) * q(j) * Cost[i + 1][j]
                                    + q(i) * p(j) * Cost[i][j + 1]
                                    + p(i) * p(j) * Cost[i + 1][j + 1]) / (1 - q(i) * q(j));
            }
    printf("%.10f\n", double(Cost[r][c]));
};