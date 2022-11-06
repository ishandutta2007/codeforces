#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int MAXN = 210;

int N, K, i, j, k, A[MAXN];
int I[MAXN], O[MAXN];

bool strictly_greater(int a, int b)
{
    return a > b;
}

int main()
{
    scanf("%d%d", &N, &K);
    fortodo(i, 1, N) scanf("%d", &A[i]);
    int RET = 0x80000000;
    fortodo(i, 1, N)
        fortodo(j, i, N)
            {       
                I[0] = O[0] = 0;
                fortodo(k, 1, i - 1) O[++O[0]] = A[k];
                fortodo(k, i, j)     I[++I[0]] = A[k];
                fortodo(k, j + 1, N) O[++O[0]] = A[k];
                sort(I + 1, I + I[0] + 1, strictly_greater);
                sort(O + 1, O + O[0] + 1, strictly_greater);
                O[0] = min(O[0], K);
                int ANS = 0, pa = 1, pb = 1, ind;
                fortodo(k, i, j)
                    {
                        ind = 0;
                        if (pa > I[0]) ind = 1;
                        if (pb > O[0]) ind = -1;
                        if (ind == 0)
                            ind = (I[pa] >= O[pb]) ? -1 : 1;
                        if (ind == -1)
                            ANS += I[pa++];
                        else
                            ANS += O[pb++];
                    }
                RET = max(RET, ANS);
            }
    printf("%d\n", RET);
}