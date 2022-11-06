#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
#define i64 long long
using namespace std;

int N, i, j, X[1000001], Cnt[10000001];
int M, L, R;

int P[2000001], Div[10000001], D[10000001];

void Sieve(i64 N)
{
    int i, j;
    P[0] = 0;
    fortodo(i, 2, N) Div[i] = 0; Div[1] = 1;
    fortodo(i, 2, N)
        {
            if (Div[i] == 0)
                {
                    Div[i] = i;
                    P[++P[0]] = i;
                }
            fortodo(j, 1, P[0])
                {
                    if (i * P[j] > N) break;
                    Div[i * P[j]] = P[j];
                    if (i % P[j] == 0) break;
                };
        };
}; 

int XMAX;

int main()
{
    scanf("%d", &N);
    fortodo(i, 1, N) scanf("%d", &X[i]);
    XMAX = 0;
    fortodo(i, 1, N) XMAX = max(XMAX, X[i]);
    Sieve(XMAX);
    fortodo(i, 1, XMAX) Cnt[i] = 0;
    fortodo(i, 1, N) Cnt[X[i]]++;
    fortodo(i, 1, XMAX) D[i] = 0;
    fortodo(i, 1, P[0])
        {
            int S = XMAX / P[i];
            int Ret = 0;
            fortodo(j, 1, S) Ret += Cnt[j * P[i]];
            D[P[i]] = Ret;
        };
    fortodo(i, 2, XMAX) D[i] += D[i - 1];
    scanf("%d", &M);
    fortodo(i, 1, M)
        {
            scanf("%d%d", &L, &R);
            if (L > XMAX)
                printf("0\n");
            else
                {
                    R = min(R, XMAX);
                    printf("%d\n", D[R] - D[L - 1]);
                };
        };
};