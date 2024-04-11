#include <stdio.h>

#define MAX_N 2000

int N, M, K;

char c[MAX_N+1][MAX_N+1];
char c2[MAX_N+1][MAX_N+1];
int main()
{
    int cnt=0;
    scanf("%d %d %d", &N, &M, &K);
    for(int i=0; i<N; i++)
    {
        scanf("%s", c[i]);
        for(int j=0; j<M; j++)
        {
            c2[j][i]=c[i][j];
        }
    }
    int k=0;
    for(int i=0; i<N; i++)
    {
        k=0;
        for(int j=0; j<M; j++)
        {
            if(c[i][j]=='.')
            {
                k++;
                if(k==K)
                {
                    k--;
                    cnt++;
                }
            }
            else
            {
                k=0;
            }
        }
    }
    if(K==1)
    {
        printf("%d", cnt);
        return 0;
    }
    for(int i=0; i<M; i++)
    {
        k=0;
        for(int j=0; j<N; j++)
        {
            if(c2[i][j]=='.')
            {
                k++;
                if(k==K)
                {
                    k--;
                    cnt++;
                }
            }
            else
            {
                k=0;
            }
        }
    }
    printf("%d", cnt);
    return 0;
}