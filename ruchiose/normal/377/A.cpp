#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, M, K, i, j;
char S[510][510];
int cnt;

void Visit(int x, int y)
{
    if (S[x][y] != 'X') return;
    if (cnt == 0) return;
    S[x][y] = '.'; cnt--;
    Visit(x - 1, y);
    Visit(x + 1, y);
    Visit(x, y - 1);
    Visit(x, y + 1);
}

int main()
{
    scanf("%d%d%d", &N, &M, &K);
    fortodo(i, 1, N)
        scanf("%s", S[i] + 1);
    fortodo(i, 0, N) S[i][0] = S[i][M + 1] = '#';
    fortodo(i, 0, M) S[0][i] = S[N + 1][i] = '#';
    cnt = - K;
    fortodo(i, 1, N)
        fortodo(j, 1, M)
            if (S[i][j] == '.')
                {
                    S[i][j] = 'X';
                    cnt++;
                }
    fortodo(i, 1, N)
        fortodo(j, 1, M)
            if (S[i][j] != '#')
                {
                    Visit(i, j);
                    break;
                }
    fortodo(i, 1, N)
        {
            fortodo(j, 1, M) putchar(S[i][j]);
            printf("\n");
        }
}