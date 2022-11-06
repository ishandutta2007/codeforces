#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, M, K, opt[101][101], i, j;
bool rl[101];
int pl[101], occu[101];

int main()
{
    scanf("%d%d%d", &N, &M, &K);
    fortodo(i, 1, N)
        fortodo(j, 1, M)
            scanf("%d", &opt[i][j]);
    fortodo(i, 1, N) pl[i] = 0;
    fortodo(i, 1, K) rl[i] = false;
    fortodo(i, 1, M)
        {
            fortodo(j, 1, K) occu[j] = 0;
            fortodo(j, 1, N)
                if ((pl[j] == 0) && (opt[j][i] != 0))
                    {
                        if (occu[opt[j][i]] != 0)
                            {
                                pl[occu[opt[j][i]]] = i;
                                rl[opt[j][i]] = true;
                            }
                        if (rl[opt[j][i]]) pl[j] = i;
                        occu[opt[j][i]] = j;
                    }
        }
    fortodo(i, 1, N) printf("%d\n", pl[i]);
}