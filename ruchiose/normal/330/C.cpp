#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, i, j;
bool map[101][101];
char S[101];

int R[101], C[101];

bool FLAG;

int main()
{
    scanf("%d", &N);
    fortodo(i, 1, N)
        {
            scanf("%s", &S);
            fortodo(j, 0, N - 1)
                map[i][j + 1] = (S[j] == '.'); 
        };
    fortodo(i, 1, N)
        {
            R[i] = 0;
            fortodo(j, 1, N)
                if (map[i][j])
                    {
                        R[i] = j;
                        break;
                    };
        };
    fortodo(i, 1, N)
        {
            C[i] = 0;
            fortodo(j, 1, N)
                if (map[j][i])
                    {
                        C[i] = j;
                        break;
                    };
        };
    fortodo(i, 1, N)
        if (R[i] == 0)
            break;
    if (i > N)
        {
            fortodo(i, 1, N)
                printf("%d %d\n", i, R[i]);
        }
    else
        {
            fortodo(i, 1, N)
                if (C[i] == 0)
                    break;
            if (i > N)
                {
                    fortodo(i, 1, N)
                        printf("%d %d\n", C[i], i);
                }
            else
                printf("-1\n");
        };
    return 0;
};