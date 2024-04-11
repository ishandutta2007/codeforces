#include <stdio.h>

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    int x, y;
    double ans=100000.00;
    for(int i=1; i<=N; i++)
    {
        scanf("%d %d", &x, &y);
        if((double)(x*M)/(double)y<ans)
        {
            ans=(double)(x*M)/(double)y;
        }
    }
    printf("%lf", ans);
    return 0;
}