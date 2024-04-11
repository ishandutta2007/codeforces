#include <stdio.h>

#define MAX_Q 200000
#define MAX_N 1000000

int Q;
int l, r;
int k;

int DP[10][MAX_N+1];
int C[MAX_N+1];

int ret_num(int x)
{
    int k=1;
    while(x>0)
    {
        if(x%10!=0)
        {
            k*=(x%10);
        }
        x/=10;
    }
    return k;
}

void calc_C(int x)
{
    if(x<10)
    {
        return;
    }
    else
    {
        C[x]=C[ret_num(x)];
    }
    return;
}

int main()
{
    scanf("%d", &Q);
    for(int i=1; i<=9; i++)
    {
        C[i]=i;
        for(int j=1; j<=9; j++)
        {
            DP[j][i]=DP[j][i-1];
        }
        DP[C[i]][i]++;
    }
    for(int i=10; i<=MAX_N; i++)
    {
        calc_C(i);
        for(int j=1; j<=9; j++)
        {
            DP[j][i]=DP[j][i-1];
        }
        DP[C[i]][i]++;
    }
    for(int i=1; i<=Q; i++)
    {
        scanf("%d %d %d", &l, &r, &k);
        printf("%d\n", DP[k][r]-DP[k][l-1]);
    }
    return 0;
}