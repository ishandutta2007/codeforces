#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, i, j, U, V, Q[101][3], ITV[101][2], NC, PNC;
bool W[101][101];

bool WALK(int A, int B)
{
    if ((ITV[A][0] > ITV[B][0]) && (ITV[A][0] < ITV[B][1])) return true; 
    if ((ITV[A][1] > ITV[B][0]) && (ITV[A][1] < ITV[B][1])) return true; 
    return false;
};

int main()
{
    scanf("%d", &N);
    NC = 0;
    fortodo(i, 1, N)
        {   
            fortodo(j, 0, 2)
                scanf("%d", &Q[i][j]);
            if (Q[i][0] == 1)
                {
                    NC++;
                    ITV[NC][0] = Q[i][1];
                    ITV[NC][1] = Q[i][2];
                };
        };
    fortodo(i, 1, NC)
        fortodo(j, 1, NC)
            W[i][j] = WALK(i, j);
    PNC = 0;
    fortodo(i, 1, N)
        {
            if (Q[i][0] == 1)
                {
                    PNC++;
                    fortodo(U, 1, NC)
                        fortodo(V, 1, NC)
                            if ((W[U][PNC]) && (W[PNC][V]))
                                W[U][V] = true;
                };
            if (Q[i][0] == 2)
                {
                    if (W[Q[i][1]][Q[i][2]])
                        printf("YES\n");
                    else
                        printf("NO\n");
                };
        };
    return 0;
};