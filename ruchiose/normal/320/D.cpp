#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define ftd(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, i, A[100010], S[100010], G[100010];

int main()
{
    scanf("%d", &N);
    ftd(i, 1, N) scanf("%d", &A[i]);
    S[0] = 0;
    A[0] = 0; G[0] = 0x3FFFFFFF;
    S[++S[0]] = 0;
    int ANS = 0;
    ftd(i, 1, N)
        {
            G[i] = 1;
            while ((S[0]) && (A[S[S[0]]] < A[i]))
                {
                    G[i] = max(G[i], G[S[S[0]]] + 1);
                    S[0]--;
                }
            S[++S[0]] = i;
            if (G[i] <= 0x3FFFFFFF) ANS = max(ANS, G[i]);
        }
    printf("%d\n", ANS);
}