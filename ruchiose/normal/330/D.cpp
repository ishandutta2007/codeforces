#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
#define INF 100000000
using namespace std;

int N, M, i, j, RS, CS, RE, CE;
char S[1002];
int map[1002][1002];
int Ans, Sie;

int Explain(char P)
{
    if (P == 'S') return -3;
    if (P == 'E') return -2;
    if (P == 'T') return -1;
    return P - '0';
};

int Q[2000001][2], H, T;
int dist[1002][1002];

void Calcdist()
{
    int X, Y, Nxd;
    fortodo(X, 0, N + 1)
        fortodo(Y, 0, M + 1)
            dist[X][Y] = INF;
    T = 1; H = 0;
    Q[1][0] = RE;
    Q[1][1] = CE;
    dist[RE][CE] = 0;
    while (H < T)
        {
            H++; 
            X = Q[H][0];
            Y = Q[H][1];
            Nxd = dist[X][Y] + 1;
            if ((map[X - 1][Y] != -1) && (dist[X - 1][Y] == INF))
                {
                    dist[X - 1][Y] = Nxd;
                    T++;
                    Q[T][0] = X - 1;
                    Q[T][1] = Y;
                };
            if ((map[X + 1][Y] != -1) && (dist[X + 1][Y] == INF))
                {
                    dist[X + 1][Y] = Nxd;
                    T++;
                    Q[T][0] = X + 1;
                    Q[T][1] = Y;
                };
            if ((map[X][Y - 1] != -1) && (dist[X][Y - 1] == INF))
                {
                    dist[X][Y - 1] = Nxd;
                    T++;
                    Q[T][0] = X;
                    Q[T][1] = Y - 1;
                };
            if ((map[X][Y + 1] != -1) && (dist[X][Y + 1] == INF))
                {
                    dist[X][Y + 1] = Nxd;
                    T++;
                    Q[T][0] = X;
                    Q[T][1] = Y + 1;
                };
        };
};

int main()
{
    scanf("%d%d", &N, &M);
    fortodo(i, 0, N + 1)
        fortodo(j, 0, M + 1)
            map[i][j] = -1;
    fortodo(i, 1, N)
        {
            scanf("%s", &S);
            fortodo(j, 1, M)
                {
                    map[i][j] = Explain(S[j - 1]);
                    if (map[i][j] == -3)
                        {
                            RS = i; 
                            CS = j;
                        };
                    if (map[i][j] == -2)
                        {
                            RE = i;
                            CE = j;
                        };
                };
        };
    Calcdist();
    Sie = dist[RS][CS];
    Ans = 0;
    fortodo(i, 1, N)
        fortodo(j, 1, M)
            if ((dist[i][j] <= Sie) && (map[i][j] > 0))
                Ans += map[i][j];
    printf("%d\n", Ans);
    return 0;
};