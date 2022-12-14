#include <stdio.h>

int main()
{
    int N;
    int cnt=0;
    scanf("%d", &N);
    for(int i=1; i<N; i++)
    {
        if(N%i==0)
        {
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}