// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
#define i64 long long
#define d64 long double
using namespace std;

int N;
char ch[111][111];
int A[111];

bool S[111];

int main()
{
    scanf("%d", &N);
    int i;
    fortodo(i, 1, N)
        scanf("%s", ch[i] + 1);
    fortodo(i, 1, N)
        scanf("%d", &A[i]);
    fortodo(i, 1, N)
        S[i] = false;
    int Cnt = 0;
    do
        {
            int X;
            fortodo(X, 1, N)
                if ((S[X] == false) && (A[X] == 0))
                    break;
            if (X > N) break;
            S[X] = true;
            fortodo(i, 1, N)
                A[i] -= ch[X][i] - '0';
            Cnt++;
        }
    while (1);
    if (Cnt == 0)
        printf("0\n\n");
    else
        {
            printf("%d\n", Cnt);
            int lascho;
            fortodo(i, 1, N)
                if (S[i])
                    lascho = i;
            fortodo(i, 1, N)
                if (S[i])
                    printf("%d%s", i, (i == lascho) ? "\n" : " ");
        }
    return 0;
}