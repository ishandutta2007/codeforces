#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;
 
int N, K, i, j, tmp, A[5001], D[1000002], S[1000002], DeterLim, PossiLim;
 
int Occu[1000001];
int TIME;
 
bool Judge(int X)
{
    int i, Cnt;
    Cnt = 0;
    fortodo(i, 1, N)
        {
            if (Occu[A[i] % X] == TIME)
                {
                    Cnt++;
                    if (Cnt > K) return false; 
                };
            Occu[A[i] % X] = TIME;
        };
    return true;
};
 
int main()
{
    scanf("%d%d", &N, &K);
    DeterLim = K; PossiLim = ((K + 1) * K) / 2;
    fortodo(i, 1, N) scanf("%d", &A[i]);
    sort(A + 1, A + N + 1);
    fortodo(i, 1, A[N] + 1) D[i] = 0;
    fortodo(i, 2, N)
        fortodo(j, 1, i - 1)
            D[A[i] - A[j]]++;
    fortodo(i, 0, A[N]) Occu[i] = 0;
    fortodo(i, 1, A[N] + 1)
        {
            TIME = i;
            S[i] = 0;
            tmp = (A[N] + 1) / i;
            fortodo(j, 1, tmp) S[i] += D[i * j];
            if (S[i] <= DeterLim)
                {
                    printf("%d\n", i);
                    return 0;
                };
            if (S[i] > PossiLim) continue;
            if (Judge(i))
                {
                    printf("%d\n", i);
                    return 0;
                };
        };
    return 0;
};