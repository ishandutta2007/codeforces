#include <stdio.h>


#define MAX_N 100000

int N, M;
int A[MAX_N+1], B[MAX_N+1];

int main()
{
    scanf("%d %d", &N, &M);
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &A[i]);
    }
    for(int j=1; j<=M; j++)
    {
        scanf("%d", &B[j]);
    }
    long long sumA=A[1], sumB=B[1];
    int idxA=2, idxB=2;
    int ans=0;
    while(idxA<=N || idxB<=M)
    {
        if(sumA<sumB || (sumA==0 && sumB==0))
        {
            sumA+=(long long)A[idxA];
            idxA++;
        }
        else if(sumA==sumB)
        {
            ans++;
            sumA=0;
            sumB=0;
        }
        else
        {
            sumB+=(long long)B[idxB];
            idxB++;
        }
        //printf("%lld %lld\n", sumA, sumB);
    }
    if(sumA!=0 && sumA==sumB)
    {
        ans++;
    }
    printf("%d", ans);
    return 0;
}