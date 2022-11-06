#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int M, N, i, j, Opt[100001][3], V[100001], Solved;
i64 Q[100001], Whl, Nxtwhl, hj, Src;

int main()
{
    scanf("%d", &M);
    Whl = Solved = 0;
    fortodo(i, 1, M)
        {
            scanf("%d", &Opt[i][0]);
            fortodo(j, 1, Opt[i][0])
                scanf("%d", &Opt[i][j]);
        }
    scanf("%d", &N);
    fortodo(i, 1, N) scanf("%I64d", &Q[i]);
    fortodo(i, 1, M)
        {
            if (Opt[i][0] == 1)
                {
                    Whl++;
                    if ((Solved < N) && (Q[Solved + 1] == Whl)) 
                        {
                            Solved++;
                            printf("%d%s", Opt[i][1], (Solved == N) ? "\n" : " ");
                        }
                    if (Whl <= 100000) V[Whl] = Opt[i][1]; 
                }
            if (Opt[i][0] == 2)
                {
                    Nxtwhl = Whl + Opt[i][1] * Opt[i][2];
                    while ((Solved < N) && (Q[Solved + 1] <= Nxtwhl))
                        {
                            Solved++;
                            Src = (Q[Solved] - Whl - 1) % Opt[i][1] + 1;
                            printf("%d%s", V[Src], (Solved == N) ? "\n" : " ");
                        }
                    i64 Targ = min(100000ll, Nxtwhl);
                    fortodo(hj, Whl + 1, Targ)
                        {
                            Src = (hj - Whl - 1) % Opt[i][1] + 1;
                            V[hj] = V[Src];
                        }
                    Whl = Nxtwhl;
                }
        }
}