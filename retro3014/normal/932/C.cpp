#include <stdio.h>

int N, A, B;
int DA, DB;

int main()
{
    scanf("%d %d %d", &N, &A, &B);
    if(N%A==0)
    {
        DA=N/A;
        DB=0;
    }
    else if(N%B==0)
    {
        DA=0;
        DB=N/B;
    }
    for(int i=1; A*i<N; i++)
    {
        if((N-A*i)%B==0)
        {
            DA=i;
            DB=(N-A*i)/B;
            break;
        }
    }
    if(DA==0 && DB==0)
    {
        printf("-1");
        return 0;
    }
    int k=1;
    for(int i=1; i<=DA; i++)
    {
        printf("%d ", k+A-1);
        for(int j=1; j<A; j++)
        {
            printf("%d ", k);
            k++;
        }
        k++;
    }
    for(int i=1; i<=DB; i++)
    {
        printf("%d ", k+B-1);
        for(int j=1; j<B; j++)
        {
            printf("%d ", k);
            k++;
        }
        k++;
    }
        
    
    return 0;
}