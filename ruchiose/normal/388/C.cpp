#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
#define i64 long long
using namespace std;

int N, S, C, i, j, T[101], M[101];

int Ans[2];

int main()
{
    scanf("%d", &N);
    Ans[0] = Ans[1] = 0; M[0] = 0;
    fortodo(i, 1, N)
        {
            scanf("%d", &S);
            fortodo(j, 1, S) scanf("%d", &T[j]);
            C = S / 2;
            fortodo(j, 1, C) Ans[0] += T[j];
            fortodo(j, 1, C) Ans[1] += T[S + 1 - j];
            if (S & 1)
                M[++M[0]] = T[C + 1];
        }
    if (M[0])
        {
            sort(M + 1, M + M[0] + 1);
            fortodo(i, 0, M[0] - 1)
                Ans[i & 1] += M[M[0] - i];
        }
    printf("%d %d\n", Ans[0], Ans[1]);
};